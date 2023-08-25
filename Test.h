#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include "Solve.h"

const int NAME_SIZE = 15;   /*!< a value of test's name*/
const int TEST_NUM = 5;     /*!< a number of tests */

/*! A structer for all information in tests */

struct test
{
    struct coeffs ec;
    double x1, x2;
    int nRoots;
    char name[NAME_SIZE];
};

int FileReader(test* ref);      //!< a function that put information from file to structer.
void TestAll();                 //!< a function that started tests.
bool TestOne(const test* ref);  //!< a function that doing separate test.

#endif
