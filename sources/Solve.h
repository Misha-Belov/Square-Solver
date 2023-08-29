#ifndef SOLVE_H
#define SOLVE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "Assert.h"
#include <ctype.h>
#include <string.h>

/**
    \file File with prototypes of function that solves quantities

    \brief This file include enum for roots and structure of coefficients
*/

//! An \enum .
/**
 * \brief enum shows quantity of roots for exact problem
 */
enum ENUM_ROOTS {
    NO_ROOT  = 0,  /**< enum for no roots */
    ONE_ROOT = 1, /**< enum for one root */
    TWO_ROOT = 2, /**< enum for two roots */
    INF_ROOT = 8, /**< enum for infinity roots */
};

// DedCodeStyle
//

// camelCaseCodeStyle
// structures - StructName
// variables - variableName

// snake_case_code_style
// structures, names ---> everything liek that


/*!
    \brief A structure for coefficients in the equation

    This class also used in test class
*/
struct COEFFS {
    double a;
    double b;
    double c;
};

struct ROOTS {
    double root1;
    double root2;
};

/*!  \fn void FlashBufer()
    \brief function for cleaning

    Function that delete symbols from buffer.

*/


void read_command_line(int number_chars, char* command[], COEFFS* coef);
void read_from_file(char* filename, COEFFS* coef);
void flush_buffer();
void scan_decision(int* option_of_decision);                                //!< a function that delete symbols from buffer.
void scan_coeff( double* coef);                             //!< a function that put coefficients from keyboard to structure and control them.
void input_coeff( COEFFS* coef);                               //!< a function that asks user for coefficients.

/*! \fn void PrintRoot( double x1, double x2, int num )
    \brief a function that print roots of user's equation.

    \warning  if equality have only one root, put this root on the first place, but second root is staying zero.
    \param x1 first root
    \param x2 second root \warning by default is zero
    \param num number of roots
*/
void print_root(const ROOTS* root, int number_roots);


ENUM_ROOTS solve_square(COEFFS* coef, ROOTS* root);    //!< a function that solves equation in common situations.
ENUM_ROOTS solve_linear(COEFFS* coef, ROOTS* root);                   //!< a function that solves equation when main coefficient is zero.
bool is_equal(const double a, const double b);                     //!< a function that compares two numbers.

 #endif
