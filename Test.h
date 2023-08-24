#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include "Solve.h"

const int NAME_SIZE = 15;
const int TEST_NUM = 5;



struct test
{
    struct exp_coeffs
    {
        double a, b, c;
    }ec;
    double x1, x2;
    int nRoots;
    char name[NAME_SIZE];
};

int FileReader(test* ref);
void TestAll();
bool TestOne(const test* ref);

#endif
