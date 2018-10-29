/* 
 * File:   BlkTable.h
 * Author: yf901
 *
 * Created on 30 September 2015, 4:17 PM
 */

#ifndef BLKTABLE_H
#define	BLKTABLE_H
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

class BlkTable {
public:
    BlkTable();
    BlkTable(const BlkTable& orig);
    virtual ~BlkTable();
    void setBlkNum(int& i) { this->blknum = i; }
    void setLength(unsigned int i) { this->length = i; }
    void setDataLength(int i) { this->datalength = i; }
    void setHash(int i) { this->hash = i; }
    void setData(char* data,int datalength);
    std::string get_oid() const { return this->_oid; }
    int getBlkNum() const { return this->blknum; }
    unsigned int getLength() const { return this->length; }
    int getHash() const { return this->hash; }
    void getData(char* input) { cout<<data<<endl;
    for(int i=0; i < datalength; i++) input[i] = this->data[i];}
    mongo::BSONObj toBSON();
    void fromBSON(const mongo::BSONObj &data);
    void createData(char* data,int datalength,int blknum,int hash);
    int getDataLength() { return this->datalength; }
    
private:
    std::string _oid;
    int blknum;
    unsigned int length;
    int hash;
    char* data;
    BlkTable& operator=(const BlkTable&);
    int datalength;
};


#endif	/* BLKTABLE_H */

