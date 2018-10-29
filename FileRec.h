/* 
 * File:   FileRec.h
 * Author: duo
 *
 * Created on August 26, 2015, 9:38 PM
 */

#ifndef FILEREC_H
#define	FILEREC_H
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <time.h>
#include "fns.h"
#include <boost/regex.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include "mongo/client/dbclient.h"
#include "mongo/util/assert_util.h"
using namespace std;

class FileRec {
public:
    FileRec();
    //FileRec(const FileRec& orig);
    //not sure what kinds of function should be created...
    void setFileName(string& filename) { this->fileName = filename; }
    void setTempName(string& tempname) { this->tempName = tempname; }
    void setModifyTime();
    void setModifyTime(string modifyTime) { this->modifyTime = modifyTime; }
    void setLength(unsigned int i) { this->length = i; }
    void setNversion(int i) { this->nversion = i; }
    void setFileHash(int i) { this->filehash = i; }
    void setRecentHash(int i) { this->recentHash = i; }
    void setRefNumber(int i) { this->refNumber = i; }
    void addBlockHashes(string& filename);
    void setBlockHashes(vector<int> newhashes);
    void addVersionIds(string versionids);
    void addComments(string& comment) { comments.push_back(comment); }

    string getFileName() const { return this->fileName; }
    string getTempName() const { return this->tempName; }
    string getModifyTime() const { return this->modifyTime; }
    unsigned int getLength() const { return this->length; }
    int getNversion() const { return this->nversion; }
    int getFileHash() const { return this->filehash; }
    int getRecentHash() const { return this->recentHash; }
    int getRefNumber() const { return this->refNumber; }
    vector<int> getBlockHashes() const { return this->blockHashes; }
    vector<string> getversionIds() const { return this->versionIds; }
    vector<string> getcomments() const { return this->comments; }
    
    
    
    
    mongo::BSONObj tofilerecBSON();
    void fromBSON(const mongo::BSONObj &data);
    
    
    void createData(string& filename,string& tempname,string& comment,int version);
    virtual ~FileRec();
    void display() {
        cout<<"  "<<fileName<<"  "<<tempName<<"  "<<modifyTime<<"  "<<length<<"  "<<nversion<<"  "<<filehash<<"  "<<recentHash<<"  "<<refNumber<<endl;
        }
private:
    string fileName;
    string tempName;
    string modifyTime;
    unsigned int length;
    int nversion;
    int filehash;
    int recentHash;
    int refNumber;
    vector<int> blockHashes;
    vector<string> versionIds;
    vector<string> comments;
    
    //FileRec(const FileRec& orig);
    FileRec& operator=(const FileRec&);
};

#endif	/* FILEREC_H */

