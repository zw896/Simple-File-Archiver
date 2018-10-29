/* 
 * File:   FileArchiver.h
 * Author: duo
 *
 * Created on August 26, 2015, 9:38 PM
 */

#ifndef FILEARCHIVER_H
#define	FILEARCHIVER_H
#include <string>
#include <cstdio>
#include "mongo/client/dbclient.h"
#include "mongo/util/assert_util.h"
#include "FileRec.h"
#include "VersionRec.h"
#include "BlkTable.h"
#include "VersionInfoRecord.h"
#include "qmessagebox.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>

typedef FileRec* RecordPtr;
typedef VersionRec* RecordVer;
typedef BlkTable* RecordBlk;
typedef VersionInfoRecord* RecordInfo;
using namespace std;
class FileArchiver {
public:
    FileArchiver(const char* dbmain);
    //FileArchiver(const FileArchiver& orig);
    virtual ~FileArchiver();
    bool differs(string filename);
    bool exists(string filename);
    void insertNew(string filename, string comment);
    void update(string filename, string comment);
    void setdbname(string dbname) { this->_dbname = dbname;}
    vector<RecordInfo> *getVersionInfo(string filename);
    string getComment(string filename,int versionnum);
    void retriveversion(int versionnum,string filename,string retrievedname);
    void setReference(string filename,int versionnumber,string comment);
    RecordPtr getDetailsOfLastSaved(string filename);
    void createZippedCopyOfFile(const std::string& localfile, const std::string& tempname);
    void unZippedCopyOfFile(const std::string& localfile, const std::string& tempname);
    mongo::DBClientConnection& getConnection() { return *_dbcon; }
private:
    mongo::DBClientConnection* _dbcon;
    bool invalid;
    std::string _mongourl;
    std::string _dbname;
    std::string _tempname;
    std::string _oid;
    FileRec* filerec;
    VersionRec* versionrec;
    BlkTable* blk;
    VersionInfoRecord* verinfo;
    vector<int> blockHashes;
};

#endif	/* FILEARCHIVER_H */

