#ifndef TEST_H
#define TEST_H


#include <stdio.h>
#include "Solve.h"

const int NAME_SIZE = 15;   /*!< a value of test's name*/
const int TEST_NUM = 5;     /*!< a number of tests */


/*! \brief A structure for all information in tests */
struct test
{
    struct coeffs ec;
    double x1, x2;     ///< expected roots
    int nRoots;
    char name[NAME_SIZE];
};

int FileReader(test* ref);      //!< \brief a function that put information from file to structure.
void TestAll();                 //!< \brief a function that started tests.
bool TestOne(const test* ref);  //!< \brief a function that doing separate test \param [in] ref structure which include all information.

#endif
