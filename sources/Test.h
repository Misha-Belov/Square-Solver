#ifndef TEST_H
#define TEST_H


#include <stdio.h>
#include "Solve.h"

const int NAME_SIZE = 15;   /*!< a value of test's name*/


/*! \brief A structure for all information in tests */
struct test
{
    struct coeffs expect_coef;
    struct roots expect_root;     ///< expected roots
    int number_roots;
    char test_name[NAME_SIZE];
};

int FileReader(test* expect, int* number_tests);      //!< \brief a function that put information from file to structure.
void TestAll();                 //!< \brief a function that started tests.
bool TestOne(const test* expect);  //!< \brief a function that doing separate test \param [in] ref structure which include all information.

#endif
