/* 
 * File:   FileRec.cpp
 * Author: duo
 * 
 * Created on August 26, 2015, 9:38 PM
 */
#include "FileRec.h"

FileRec::FileRec() {
}
void FileRec::setModifyTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    this->modifyTime=buf;
}

void FileRec::addBlockHashes(string& filename) {
    int temp;
    int count = this->getLength()/4096;
    ifstream ins(filename.c_str(), ios::binary);
    for(int i =0;i<count;i++)
    {   char data[4096] = {0};
	ins.read(data,4096);

	temp = MurmurHashNeutral2(data, 4096,1);
	this->blockHashes.push_back(temp);
    }
    count = this->getLength()%4096;
    if(count!=0){
        char* data = new char[count];
        ins.read(data,count);
        cout<<data<<endl;
        cout<<"The Last one"<<endl;
	temp = MurmurHashNeutral2(data, count,1);
        this->blockHashes.push_back(temp);
	}
    ins.close();
    // Should it be an error to specify the same role more than once? No, it
    // will not really matter - so don't throw exception, just don't duplicate.
    vector<int>::iterator it;
    cout<<"Printing hash number start!"<<endl;
    for(it=blockHashes.begin();it!=blockHashes.end();it++)
        cout<<*it<<endl;
    cout<<"Printing hash number end!"<<endl;
}
void FileRec::setBlockHashes(vector<int> newhashes){
    this->blockHashes.clear();
    this->blockHashes = newhashes;
}

void FileRec::addVersionIds(string versionids) {
    // Should it be an error to specify the same role more than once? No, it
    // will not really matter - so don't throw exception, just don't duplicate.
    std::vector<std::string>::iterator it;
    it = find(this->versionIds.begin(), this->versionIds.end(), versionids);
    if (it != this->versionIds.end()) return; // Found it, so don't duplicate
    versionIds.push_back(versionids);
    }
mongo::BSONObj FileRec::tofilerecBSON() {
    mongo::BSONObjBuilder b;
    b.append("_id", this->fileName);
    b.append("blkhashes", this->blockHashes);
    b.append("comments", this->comments);
    b.append("curhash", this->recentHash);
    b.append("currectversions", this->refNumber);
    b.append("length", this->length);
    b.append("modifytime", this->modifyTime);
    b.append("nversions", this->nversion);   
    b.append("ovhash", this->filehash); 
    b.append("tempname", this->tempName);
    b.append("versionids", this->versionIds);
    mongo::BSONObj result = b.obj();
    return result;
}

void FileRec::fromBSON(const mongo::BSONObj &data) {
    std::string filename(data.getStringField("_id"));
    this->setFileName(filename);
    std::string tempname(data.getStringField("tempname"));
    this->setTempName(tempname);
    std::string modifyTime(data.getStringField("modifytime"));
    this->setModifyTime(modifyTime);
    

    unsigned int length = data.getIntField("length");
    this->setLength(length);
    int nversions = data.getIntField("nversions");
    this->setNversion(nversions);
    int filehash = data.getIntField("ovhash");
    this->setFileHash(filehash);
    int recentHash = data.getIntField("curhash");
    this->setRecentHash(recentHash);
    int refNumber = data.getIntField("currectversions");
    this->setRefNumber(refNumber);
    
    mongo::BSONObjIterator blockit(data.getObjectField("blkhashes"));
    while (blockit.more()) {
        this->blockHashes.push_back(blockit.next().Int());
    }
    mongo::BSONObjIterator versionit(data.getObjectField("versionids"));
    while (versionit.more()) {
        this->versionIds.push_back(versionit.next().String());
    }
    mongo::BSONObjIterator commentit(data.getObjectField("comments"));
    while (commentit.more()) {
        this->comments.push_back(commentit.next().String());
    }
    
}


void FileRec::createData(string& filename,string& tempname,string& comment,int version) {
    //Read file size.
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(),"rb");
    fseek(p_file,0,SEEK_END);
    this->length = ftell(p_file);
    fclose(p_file);
    //Read file size.
    //Calculate the all hash

    std::cout<<"*****************************************"<<endl;
    this->setFileName(filename);
    this->setTempName(tempname);
    this->setModifyTime();
    this->setNversion(version+1);
    this->setFileHash(AllHash(filename));
    this->setRecentHash(AllHash(filename));
    this->setRefNumber(version);
    this->addBlockHashes(filename);
    this->addComments(comment);
    this->display();
}

FileRec::~FileRec() {
}

