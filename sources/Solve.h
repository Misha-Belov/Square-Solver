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
enum enum_roots {
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
struct coeffs {
    double a;
    double b;
    double c;
};

struct roots {
    double root1;
    double root2;
};

/*!  \fn void FlashBufer()
    \brief function for cleaning

    Function that delete symbols from buffer.

*/


void ReadCommandLine(int number_chars, char* command[], coeffs* coef);
void ReadFromFile(char* filename, coeffs* coef);
void FlushBuffer();
void scan_decision(int* option_of_decision);                                //!< a function that delete symbols from buffer.
void ScanCoeff( double* coef);                             //!< a function that put coefficients from keyboard to structure and control them.
void InputCoeff( coeffs* coef);                               //!< a function that asks user for coefficients.

/*! \fn void PrintRoot( double x1, double x2, int num )
    \brief a function that print roots of user's equation.

    \warning  if equality have only one root, put this root on the first place, but second root is staying zero.
    \param x1 first root
    \param x2 second root \warning by default is zero
    \param num number of roots
*/
void PrintRoot(const roots* root, int number_roots);


enum_roots SolveSquare(coeffs* coef, roots* root);    //!< a function that solves equation in common situations.
enum_roots SolveLinear(coeffs* coef, roots* root);                   //!< a function that solves equation when main coefficient is zero.
bool CompareDouble(double a, double b);                     //!< a function that compares two numbers.

// IsEqual(double x, double y);

// IsZero(double number);

 #endif
