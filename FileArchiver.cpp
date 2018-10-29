/* 
 * File:   FileArchiver.cpp
 * Author: duo
 * 
 * Created on August 26, 2015, 9:38 PM
 */

#include "FileArchiver.h"
static const char* connectStr = "localhost:27017";
using namespace std;
FileArchiver::FileArchiver(const char* dbname) {
    // Constructors should always succeed. But suppose it failed and
    // the database couldn't be created?
    std::cout<<"*****************************************"<<endl;
    invalid = true;
    _dbname = strdup(dbname);
    // Open a connection to the mongodb process file
    try {
        _dbcon = new mongo::DBClientConnection();
        std::cout<<"Success set mongodb: "<<_dbname<<std::endl;
        _dbcon->connect(connectStr);
    } catch (const mongo::DBException &e) {
        return;
    }   
    //It's ok
    invalid = false;
    // Constructors should always succeed. But suppose it failed and
    // the database couldn't be created?
    
    std::cout << "Mongo set up complete!" << std::endl;
    std::cout<<"*****************************************"<<endl;
}


FileArchiver::~FileArchiver() {
}
bool FileArchiver::differs(string filename) {
    int local = AllHash(filename);
    cout<<"local: "<<local<<endl;
    //RecordPtr record = new FileRec();
    mongo::BSONObj search = BSON("_id" << filename);
    this->_dbname="archiver.filerec";
    auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search);
    while (cursor->more()) {
        mongo::BSONObj nextone = cursor->next();
        cout<<"Store: "<<nextone.getIntField("ovhash")<<endl;
        if(nextone.getIntField("ovhash")==local) {
            cout<<"Check different successful!"<<endl;
            return false;
        }
    }
    return true;
}
bool FileArchiver::exists(string filename) {
    mongo::BSONObjBuilder b;
    b.append("_id", filename);
    mongo::BSONObj p = b.obj();
    this->setdbname("archiver.filerec");
    string str = this->_dbname;
    unsigned long long num = _dbcon->count(str, p);
    return num == 1;
}

void FileArchiver::insertNew(string filename, string comment) {
    std::string tempname = tempnam("tmp", "ARKIV");
    tempname+=".gz";
    createZippedCopyOfFile(filename, tempname);
    
    mongo::GridFS gfs(this->getConnection(), "archiver", "blobs");
    gfs.storeFile(tempname);

    //Insert into filerec table
    filerec = new FileRec();
    filerec->createData(filename,tempname,comment,0);
    this->_dbname="archiver.filerec";
    this->_dbcon->insert(_dbname,filerec->tofilerecBSON());
    

    //Calculate the hash key.  
    unlink(tempname.c_str());
    cout<<"FileArchiver::insertNew: "<<tempname<<endl;
    std::cout<<"*****************************************"<<endl;
}
void FileArchiver::update(string filename, string comment) {
    RecordPtr last = this->getDetailsOfLastSaved (filename);
    int version = last->getNversion() + last->getRefNumber();
    cout<<version<<"->"<<last->getNversion()<<"---"<<last->getRefNumber()<<endl;
    
    RecordVer addnew = new VersionRec();
    addnew->createData(filename,version);
    
    if(last->getFileHash() == addnew->getOvash()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("A1version1");
        msgBox.setText("The file has NOT been modified,no save required.");
        msgBox.exec();
        return;
    }
    this->_dbname="archiver.versionrec";
    this->_dbcon->insert(_dbname,addnew->toBSON());
   
    
    last->addComments(comment);
    last->addVersionIds(addnew->get_oid());
    mongo::BSONObj result = BSON("$set" << BSON("comments" << last->getcomments() << 
            "curhash" << AllHash(filename) << "nversions" << last->getNversion()+1 << "versionids" << last->getversionIds()));
    this->_dbcon->update("archiver.filerec",MONGO_QUERY("_id" << filename),result);
    cout<<"Testing002!"<<endl;
    //Testing update
    

    std::vector<int> lasthash = last->getBlockHashes();
    std::vector<int> currenthash = addnew->getBlockHashes();
    std::vector<int>::iterator it = lasthash.begin();
   
    int count = 0;
    int temp;
    int times = addnew->getLength()/4096;
    ifstream ins(filename.c_str(), ios::binary);
    this->_dbname="archiver.blktable";
    for(int i=0;i<times;i++){
        char data[4096] = {0};
        ins.read(data,4096);
        temp = MurmurHashNeutral2(data, 4096,1);
        cout<<temp<<endl;
        if(it == lasthash.end() || temp != *it) {
            RecordBlk blk = new BlkTable();
            blk->createData(data,4096,count,temp);
            this->_dbcon->insert(_dbname,blk->toBSON());
            addnew->addBlockIds(blk->get_oid());
            }
        if(it!= lasthash.end()){
            it++;
            }
        count++;
    }
    cout<<"Testing003!"<<endl;
    int lastbloc = addnew->getLength()%4096;
    if(lastbloc !=0){
        char* data = new char[lastbloc];
        ins.read(data,lastbloc);
        temp = MurmurHashNeutral2(data,lastbloc,1);
        cout<<"Testing004!"<<endl;
        RecordBlk blk = new BlkTable();
        cout<<"Testing005!"<<endl;
        blk->createData(data,lastbloc,count,temp);
        cout<<"Testing006!"<<endl;
        this->_dbcon->insert(_dbname,blk->toBSON());
        addnew->addBlockIds(blk->get_oid());
    }
    ins.close();
    vector<string> test = addnew->getBlockIds();
    vector<string>::iterator is;
    for(is = test.begin();is != test.end();is++)
        cout<<"Blockid___>"<<*is<<endl;
    string abc = addnew->get_oid();
    cout<<"ABC:  "<<abc<<endl;
    mongo::BSONObj result1 = BSON("$set" << BSON("blockids" << addnew->getBlockIds()));
    this->_dbcon->update("archiver.versionrec",MONGO_QUERY("_id" << mongo::OID(abc)),result1);
    cout<<"Testing002!"<<endl;
}



vector<RecordInfo> *FileArchiver::getVersionInfo(string filename) {
    std::vector<RecordInfo> *records = new std::vector<RecordInfo>;
    mongo::BSONObj search = BSON("_id" << filename);
    this->_dbname="archiver.filerec";
    auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search);
    FileRec* refer = new FileRec();
    while (cursor->more()) {
        mongo::BSONObj nextone = cursor->next();
        refer->fromBSON(nextone);
    }
    RecordInfo arecord = new VersionInfoRecord(); 
    arecord->createData(refer->getRefNumber(),refer->getLength(),refer->getModifyTime());
    records->push_back(arecord);
    vector<string> versionids = refer->getversionIds();
    vector<string>::iterator it;
    for(it = versionids.begin();it != versionids.end();it++) {
        mongo::BSONObj search1 = BSON("_id" << mongo::OID(*it));
        this->_dbname="archiver.versionrec";
        cursor = this->_dbcon->query(_dbname, search1);
        RecordVer aversion = new VersionRec();
        while(cursor->more()) {
            mongo::BSONObj nextver = cursor->next();
            aversion->fromBSON(nextver);
            arecord = new VersionInfoRecord();
            arecord->createData(aversion->getVersionNumber(),aversion->getLength(),aversion->getModifyTime());
            records->push_back(arecord);
        }
    }
    return records;       
    
}
        
string FileArchiver::getComment(string filename,int versionnum) {
    RecordPtr record = new FileRec();
    mongo::BSONObj search = BSON("_id" << filename);
    this->_dbname="archiver.filerec";
    auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search);
    while (cursor->more()) {
        mongo::BSONObj nextone = cursor->next();
        record->fromBSON(nextone);
        }
    vector<string> temp = record->getcomments();
    return temp[versionnum];
}
void FileArchiver::retriveversion (int versionnum,string filename,string retrievedname){
    RecordPtr record = new FileRec();
    mongo::BSONObj search = BSON("_id" << filename);
    this->_dbname="archiver.filerec";
    auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search);
    while (cursor->more()) {
        mongo::BSONObj nextone = cursor->next();
        record->fromBSON(nextone);
    }
    string tempname = record->getTempName();
    mongo::GridFS gfs(this->getConnection(),"archiver", "blobs");
    mongo::GridFile afile = gfs.findFileByName(tempname);
    unsigned long long length = afile.write(tempname);
    unZippedCopyOfFile(retrievedname,tempname);
    unlink(tempname.c_str());
    vector<string> test = record->getversionIds();
    vector<int> blockHashes = record->getBlockHashes();
    int count = versionnum - record->getRefNumber();
    for(int i =0;i < count;i++){
        VersionRec* aversion = new VersionRec();
	mongo::BSONObj search1 = BSON("_id" << mongo::OID(test.at(i)));
	this->_dbname="archiver.versionrec";
	auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search1);
        while (cursor->more()) {
			mongo::BSONObj nextone1 = cursor->next();
			aversion->fromBSON(nextone1);
			vector<string> blockids = aversion->getBlockIds();
                        cout<<"loop number:"<<blockids.size()<<endl;
			for(unsigned int k =0;k < blockids.size();k++){
                                cout<<"Problem?"<<k<<endl;
				BlkTable* ablk = new BlkTable();
                                cout<<"Out"<<blockids.at(k)<<endl;
				mongo::BSONObj search2 = BSON("_id" << mongo::OID(blockids.at(k)));
				this->_dbname="archiver.blktable";
				auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search2);
                                cout<<"Test"<<endl;
                                while (cursor->more()) {
                                    mongo::BSONObj nextone2 = cursor->next();
                                    ablk->fromBSON(nextone2);
                                    int hash = ablk->getHash();
                                    int blknum = ablk->getBlkNum();
                                    cout<<"blknum:"<<blknum<<endl;
                                    cout<<"blockHashes size:"<<blockHashes.size()<<endl;
                                    cout<<"hash:"<<hash<<endl;
                                    if(blknum == blockHashes.size()){
                                        blockHashes.push_back(hash);
                                        cout<<"add 1"<<endl;
                                    } else if(blockHashes.at(blknum) != hash){
                                        blockHashes.at(blknum) = hash;
                                    }
                                }
			}
                }
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    vector<int> refer = record->getBlockHashes();
    vector<int>::const_iterator is;
    for(is = refer.begin();is != refer.end();is++)
        cout<<*is<<" -> ";
    cout<<endl;
    for(is = blockHashes.begin();is != blockHashes.end();is++)
        cout<<*is<<" -> ";
    cout<<endl;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    if(blockHashes.size() >= refer.size()){
        cout<<blockHashes.size()<<endl;
        cout<<refer.size()<<endl;
        for(int i =0;i<blockHashes.size();i++){
            if( refer.size()<=i || blockHashes.at(i) != refer.at(i)) {
                BlkTable* nowblk = new BlkTable();
                mongo::BSONObj search3 = BSON("Hash" << blockHashes.at(i));
                this->_dbname="archiver.blktable";
                auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search3);
                while (cursor->more()) {
                    mongo::BSONObj nextone3 = cursor->next();
                    nowblk->fromBSON(nextone3);
                }
                int datalength = nowblk->getDataLength();
                cout<<"@@@@@@@@@@@@---->"<<i<<endl;
                char* data = new char[datalength];
                cout<<"@@@@@@@@@@@@---->"<<nowblk->getDataLength()<<endl;
                nowblk->getData(data);
                cout<<"@@@@@@@@@@@@---->"<<data<<endl;
                fstream ins(retrievedname.c_str(), ios::in|ios::out|ios::binary);
                ins.seekg(i*4096,ios::beg);
                for(int k=0;k<datalength;k++)
                ins<<data[k];
            //ins.seekg(0,ios::beg);
                ins.close();
            }
        }
    }
}
void FileArchiver::setReference(string filename,int versionnumber,string comment) {
    RecordPtr record = new FileRec();
    mongo::BSONObj search = BSON("_id" << filename);
    this->_dbname="archiver.filerec";
    auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search);
    while (cursor->more()) {
        mongo::BSONObj nextone = cursor->next();
        record->fromBSON(nextone);
    }
    string tempname = record->getTempName();
    cout<<tempname<<endl;
    mongo::BSONObj search1 = BSON("filename" << tempname);
    this->_dbname="archiver.blobs.files";
    cursor = this->_dbcon->query(_dbname, search1);
    std::string oid;
    while (cursor->more()) {
        mongo::BSONObj nextone1 = cursor->next();
        mongo::BSONElement thing;
        nextone1.getObjectID(thing);
        mongo::OID anoid = thing.OID();
        oid = anoid.toString();
    }
    cout<<"Tenter"<<oid<<endl;
    this->_dbcon->remove("archiver.blobs.chunks",MONGO_QUERY("files_id" << mongo::OID(oid)),0);
    this->_dbcon->remove("archiver.blobs.files",MONGO_QUERY("filename" << tempname),0);
    
    createZippedCopyOfFile(filename, tempname);
    
    mongo::GridFS gfs(this->getConnection(), "archiver", "blobs");
    gfs.storeFile(tempname);
    unlink(tempname.c_str());
    
    RecordPtr newfilerec = new FileRec();
    newfilerec->createData(filename,tempname,comment,versionnumber);
    
    vector<string> newversionids = record->getversionIds();
    for(int i =0;i < versionnumber;i++) {
        this->_dbcon->remove("archiver.versionrec",MONGO_QUERY("_id" << mongo::OID(newversionids.at(0))),0);
        newversionids.erase(newversionids.begin());
    }

    
    
    mongo::BSONObj result = BSON("$set" << BSON("blkhashes" << newfilerec->getBlockHashes() << "curhash" << 
            AllHash(filename)<< "length" << newfilerec->getLength() << /*"modifytime" << newfilerec->getModifyTime() <<*/ 
            "nversions" << record->getNversion()-versionnumber << "currectversions" << versionnumber << "versionids" << newversionids));

    this->_dbcon->update("archiver.filerec",MONGO_QUERY("_id" << filename),result);
}



RecordPtr FileArchiver::getDetailsOfLastSaved (string filename) {
    RecordPtr record = new FileRec();
    mongo::BSONObj search = BSON("_id" << filename);
    this->_dbname="archiver.filerec";
    auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search);
    while (cursor->more()) {
        mongo::BSONObj nextone = cursor->next();
        record->fromBSON(nextone);
    }
    cout<<"11111111111111111111111111111111111111"<<endl;
    vector<string> test = record->getversionIds();
    vector<int> blockHashes = record->getBlockHashes();
	for(int i =0;i < test.size();i++){
		VersionRec* aversion = new VersionRec();
		mongo::BSONObj search1 = BSON("_id" << mongo::OID(test.at(i)));
		this->_dbname="archiver.versionrec";
		auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search1);
		while (cursor->more()) {
			mongo::BSONObj nextone1 = cursor->next();
			aversion->fromBSON(nextone1);
			vector<string> blockids = aversion->getBlockIds();
			for(unsigned int k =0;k < blockids.size();k++){
				BlkTable* ablk = new BlkTable();
				mongo::BSONObj search2 = BSON("_id" << mongo::OID(blockids.at(k)));
				this->_dbname="archiver.blktable";
				auto_ptr<mongo::DBClientCursor> cursor = this->_dbcon->query(_dbname, search2);
                                while (cursor->more()) {
                                    mongo::BSONObj nextone2 = cursor->next();
                                    ablk->fromBSON(nextone2);
                                    int hash = ablk->getHash();
                                    int blknum = ablk->getBlkNum();
                                    if(blknum == blockHashes.size()){
                                        blockHashes.push_back(hash);
                                        cout<<"add 1"<<endl;
                                    } else if(blockHashes.at(blknum) != hash){
                                        blockHashes.at(blknum) = hash;
                                    }
                                }
			}
                }
                record->setLength(aversion->getLength());
                record->setModifyTime(aversion->getModifyTime());
                record->setFileHash(aversion->getOvash());
    }
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    vector<int> abc = record->getBlockHashes();
    vector<int>::const_iterator is;
    for(is = abc.begin();is != abc.end();is++)
        cout<<*is<<" -> ";
    cout<<endl;
    record->setBlockHashes(blockHashes);
    vector<int> cde = record->getBlockHashes();
    for(is = cde.begin();is != cde.end();is++)
        cout<<*is<<" -> ";
    cout<<endl;
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
    
    
   return record;
}

void FileArchiver::createZippedCopyOfFile(const std::string& localfile, const std::string& tempname) {
    std::string command = "/bin/gzip -c ";
    command.append(localfile);
    command.append(" > ");
    command.append(tempname);
    cout<<"createZippedCopyOfFile: "<<localfile<<"   "<<tempname<<endl;
    std::cout<<"*****************************************"<<endl;
    system(command.c_str());
}
void FileArchiver::unZippedCopyOfFile(const std::string& localfile, const std::string& tempname) {
    std::string command = "/bin/gunzip -c ";
    command.append(tempname);
    command.append(" > ");
    command.append(localfile);
    cout<<"UnZippedCopyOfFile: "<<localfile<<"   "<<tempname<<endl;
    std::cout<<"*****************************************"<<endl;
    system(command.c_str());
    unlink(tempname.c_str());
}
