#ifndef TEST_H
#define TEST_H


#include <stdio.h>
#include "Solve.h"

const int NAME_SIZE = 15;   /*!< a value of test's name*/


/*! \brief A structure for all information in tests */
struct Test
{
    struct Coeffs expect_coef;    ///< structure of coefficients in testing
    struct Roots expect_root;     ///< structure of expected roots
    int    number_roots;             ///< expected number of roots
    char   test_name[NAME_SIZE];    ///< value of test name
};

void sort_roots(double root1, double root2);
int file_reader(Test* expect, int* number_tests);      //!< \brief a function that put information from file to structure.
void test_all();                    //!< \brief a function that started tests.
bool test_one(const Test* expect);  //!< \brief a function that doing separate test \param [in] ref structure which include all information.

#endif
