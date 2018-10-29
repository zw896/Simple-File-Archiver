/* 
 * File:   VersionInfoRecord.h
 * Author: ll118
 *
 * Created on 28 August 2015, 11:53 AM
 */

#ifndef VERSIONINFORECORD_H
#define	VERSIONINFORECORD_H
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
class VersionInfoRecord {
public:
    VersionInfoRecord();
    VersionInfoRecord(const VersionInfoRecord& orig);
    virtual ~VersionInfoRecord();
    //not sure what kinds of function should be created...
    void setVersion(int i) { this->version = i; }
    void setLength(unsigned int i) { this->length = i; }
    void setModifyTime(string modifyTime) { this->modifyTime = modifyTime; }
    int getVersion() const { return this->version; }
    unsigned int getLength() const { return this->length; }
    string getModifyTime() const { return this->modifyTime; }
    
    void createData(int version,unsigned int length,string modifyTime);
private:
    int version;
    unsigned int length;
    string modifyTime;
};
#endif	/* VERSIONINFORECORD_H */

