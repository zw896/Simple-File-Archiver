/* 
 * File:   VersionRec.h
 * Author: duo
 *
 * Created on August 26, 2015, 9:38 PM
 */

#ifndef VERSIONREC_H
#define	VERSIONREC_H
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

class VersionRec {
public:
    VersionRec();
    VersionRec(const VersionRec& orig);
    virtual ~VersionRec();
    void setVersionNumber(int& i) { this->versionnumber = i; }
    void setLength(unsigned int i) { this->length = i; }
    void setModifyTime();
    void setModifyTime(std::string& modifyTime) { this->modifyTime = modifyTime; }
    void setOvhash(int i) { this->ovhash = i; }
    void addBlockIds(std::string blockids);
    void addBlockHashes(string& filename);
    
    std::string get_oid() const { return this->_oid; }
    int getVersionNumber() const { return this->versionnumber; }
    unsigned int getLength() const { return this->length; }
    std::string getModifyTime() const { return this->modifyTime; }
    int getOvash() const { return this->ovhash; }
    std::vector<std::string> getBlockIds() const { return this->blockIds; }
    std::vector<int> getBlockHashes() const { return this->blockHashes; }
    
    
    mongo::BSONObj toBSON();
    void fromBSON(const mongo::BSONObj &data);
    void createData(std::string& filename,int version);
    
    
private:
    std::string _oid;
    int versionnumber;
    unsigned int length;
    std::string modifyTime;
    int ovhash;
    std::vector<std::string> blockIds;
    std::vector<int> blockHashes;
    VersionRec& operator=(const VersionRec&);
};

#endif	/* VERSIONREC_H */

