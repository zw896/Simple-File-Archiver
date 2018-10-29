#include "VersionInfoRecord.h"



VersionInfoRecord::VersionInfoRecord() {
}

VersionInfoRecord::VersionInfoRecord(const VersionInfoRecord& orig) {
}

VersionInfoRecord::~VersionInfoRecord() {
}

void VersionInfoRecord::createData(int version,unsigned int length,string modifyTime) {
    this->version = version;
    this->length = length;
    this->modifyTime = modifyTime;
}
