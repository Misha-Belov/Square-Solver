#ifndef TEST_H
#define TEST_H


#include <stdio.h>
#include "Solve.h"

const int NAME_SIZE = 15;   /*!< a value of test's name*/


/*! \brief A structure for all information in tests */
struct TEST
{
    struct COEFFS expect_coef;    ///< structure of coefficients in testing
    struct ROOTS expect_root;     ///< structure of expected roots
    int    number_roots;             ///< expected number of roots
    char   test_name[NAME_SIZE];    ///< value of test name
};

int file_reader(TEST* expect, int* number_tests);      //!< \brief a function that put information from file to structure.
void test_all();                    //!< \brief a function that started tests.
bool test_one(const TEST* expect);  //!< \brief a function that doing separate test \param [in] ref structure which include all information.

#endif
