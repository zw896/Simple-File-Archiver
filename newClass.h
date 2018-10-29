/* 
 * File:   newClass.h
 * Author: yf901
 *
 * Created on 1 October 2015, 2:14 PM
 */

#ifndef NEWCLASS_H
#define	NEWCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newClass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newClass);
    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);
    CPPUNIT_TEST_SUITE_END();

public:
    newClass();
    virtual ~newClass();
    void setUp();
    void tearDown();

private:
    int *example;
    void testMethod();
    void testFailedMethod();
};

#endif	/* NEWCLASS_H */

