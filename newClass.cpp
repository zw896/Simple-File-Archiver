/* 
 * File:   newClass.cpp
 * Author: yf901
 * 
 * Created on 1 October 2015, 2:15 PM
 */

#include "newClass.h"

CPPUNIT_TEST_SUITE_REGISTRATION(newClass);

newClass::newClass() {
}

newClass::~newClass() {
}

void newClass::setUp() {
    this->example = new int(1);
}

void newClass::tearDown() {
    delete this->example;
}

void newClass::testMethod() {
    CPPUNIT_ASSERT(*example == 1);
}

void newClass::testFailedMethod() {
    CPPUNIT_ASSERT(++*example == 1);
}
