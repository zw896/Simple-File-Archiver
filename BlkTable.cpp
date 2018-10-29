
#include "BlkTable.h"



BlkTable::BlkTable() {
}

BlkTable::BlkTable(const BlkTable& orig) {
}

BlkTable::~BlkTable() {
}
void BlkTable::setData(char* data,int datalength) {
    this->data = new char[datalength];
    for(int i=0;i<datalength;i++)
        this->data[i] = data[i];
    this->datalength = datalength;
}
mongo::BSONObj BlkTable::toBSON(){
    mongo::BSONObjBuilder b;
    if (this->_oid.empty()) {
        b.genOID();
    } else {
        mongo::OID theoid(this->_oid);
        b.append("_id", theoid);
    }

    b.append("Blknum", this->blknum);
    b.append("Hash", this->hash);
    b.append("length", this->datalength);
    cout<<this->data<<endl;
    cout<<sizeof (this->data)<<endl;
    b.appendBinData("Data",
            datalength,
            mongo::BinDataGeneral,
            this->data);
    mongo::BSONObj result = b.obj();
    if (this->_oid.empty()) {
        mongo::BSONElement thing;
        result.getObjectID(thing);
        mongo::OID anoid = thing.OID();
        this->_oid = anoid.toString();
    }
    return result;
}
void BlkTable::fromBSON(const mongo::BSONObj &data) {
    mongo::BSONElement thing;
    data.getObjectID(thing);
    mongo::OID anoid = thing.OID();
    this->_oid = anoid.toString();
    int blknum = data.getIntField("Blknum");
    this->setBlkNum(blknum);
    int datalength = data.getIntField("length");
    this->setDataLength(datalength);
    int hash(data.getIntField("Hash"));
    this->setHash(hash);
    mongo::BSONElement structelem = data.getField("Data");
    int elemlength;
    const char* dataptr = structelem.binData(elemlength);
    this->data = new char[elemlength];
    for(int i=0;i<elemlength;i++)
        this->data[i]=dataptr[i];
}
void BlkTable::createData(char* data,int datalength,int blknum,int hash) {
    this->data = new char[datalength];
    for(int i=0;i<datalength;i++)
        this->data[i] = data[i];
    cout<<"Input data length"<<datalength;
    this->blknum=blknum;
    this->hash=hash;
    this->datalength = datalength;
}