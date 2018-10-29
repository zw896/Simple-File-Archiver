/* 
 * File:   VersionRec.cpp
 * Author: duo
 * 
 * Created on August 26, 2015, 9:38 PM
 */

#include "VersionRec.h"



VersionRec::VersionRec() {
}

VersionRec::VersionRec(const VersionRec& orig) {
}

VersionRec::~VersionRec() {
}

void VersionRec::setModifyTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    this->modifyTime=buf;
}
void VersionRec::addBlockIds(std::string blockids) {
    // Should it be an error to specify the same role more than once? No, it
    // will not really matter - so don't throw exception, just don't duplicate.
    std::vector<string>::iterator it;
    it = find(this->blockIds.begin(), this->blockIds.end(), blockids);
    if (it != this->blockIds.end()) return; // Found it, so don't duplicate
    blockIds.push_back(blockids);
}
void VersionRec::addBlockHashes(string& filename) {
    int temp;
    int count = this->getLength()/4096;
    ifstream ins(filename.c_str(), ios::binary);
    for(int i =0;i<count;i++)
    {   char data[4096] = {0};
	ins.read(data,4096);
	temp = MurmurHashNeutral2(data, 4096,1);
        cout<<data<<endl;
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
    cout<<"Printing VersionRec hash number start!"<<endl;
    for(it=blockHashes.begin();it!=blockHashes.end();it++)
        cout<<*it<<endl;
    cout<<"-------------------------------------------"<<endl;
}
mongo::BSONObj VersionRec::toBSON() {
    mongo::BSONObjBuilder b;
    if (this->_oid.empty()) {
        b.genOID();
    } else {
        mongo::OID theoid(this->_oid);
        b.append("_id", theoid);
    }

    b.append("versionnumber", this->versionnumber);
    b.append("length", this->length);
    b.append("modifytime", this->modifyTime);
    b.append("ovhash", this->ovhash);
    b.append("blockids", this->blockIds);
    mongo::BSONObj result = b.obj();
    if (this->_oid.empty()) {
        mongo::BSONElement thing;
        result.getObjectID(thing);
        mongo::OID anoid = thing.OID();
        this->_oid = anoid.toString();
    }
    return result;
}
void VersionRec::fromBSON(const mongo::BSONObj &data) {
    mongo::BSONElement thing;
    data.getObjectID(thing);
    mongo::OID anoid = thing.OID();
    this->_oid = anoid.toString();
    int versionnumber = data.getIntField("versionnumber");
    this->setVersionNumber(versionnumber);
    unsigned int length = data.getIntField("length");
    this->setLength(length);
    std::string modifyTime(data.getStringField("modifytime"));
    this->setModifyTime(modifyTime);
    int ovhash = data.getIntField("ovhash");
    this->setOvhash(ovhash);
    mongo::BSONObjIterator blockit(data.getObjectField("blockids"));
    while (blockit.more()) {
        this->blockIds.push_back(blockit.next().String());
    }
}
void VersionRec::createData(std::string& filename,int version) {

    
    //Read file size.
    FILE *p_file = NULL;
    p_file = fopen(filename.c_str(),"rb");
    fseek(p_file,0,SEEK_END);
    this->length = ftell(p_file);
    fclose(p_file);
    //Read file size.
    //Calculate the all hash
    
    std::cout<<"*****************************************"<<endl;
//    this->set_oid(filename);
    this->setVersionNumber(version);
    this->setModifyTime();
    this->setOvhash(AllHash(filename));
    this->addBlockHashes(filename);
}