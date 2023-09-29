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
enum Nroots
{
    NO_ROOT  = 0,  /**< enum for no roots */
    ONE_ROOT = 1, /**< enum for one root */
    TWO_ROOT = 2, /**< enum for two roots */
    INF_ROOT = -1, /**< enum for infinity roots */
};


/*!
    \brief A structure for coefficients in the equation

    This class also used in test class
*/
struct Coeffs
{
    double a;
    double b;
    double c;
};

/*!
    \brief A structure for roots of the equation
*/
struct Roots
{
    double root1;
    double root2;
};

/*!  \fn void flush_buffer()
    \brief function for cleaning

    Function that delete symbols from buffer.

*/

void scan_decision(int* option_of_decision);
void process_options(Coeffs* coef, int option_of_decision);

void read_command_line(const int number_chars, const char* command[], Coeffs* coef);    ///< this function reed name of the fail with coefficients from command string
void read_from_file(const char* filename, Coeffs* coef);                                ///< this function reed coefficients from file defined in command line
void flush_buffer();                                //!< a function that delete symbols from buffer.
bool scan_coeff(double* coef);                      //!< a function that put coefficients from keyboard to structure and control them.
bool input_coeff(Coeffs* coef);                     //!< a function that asks user for coefficients.

/*! \fn void print_root( double x1, double x2, int num )
    \brief a function that print roots of user's equation.

    \warning  if equality have only one root, put this root on the first place, but second root is staying zero.
    \param x1 first root
    \param x2 second root \warning by default is zero
    \param num number of roots
*/
void print_root(const Roots* root, int number_roots);       //!< this function print roots to the screen


Nroots solve_square(Coeffs* coef, Roots* root);         //!< a function that solves equation in common situations.
Nroots solve_linear(const Coeffs* coef, Roots* root);         //!< a function that solves equation when main coefficient is zero.
bool is_equal(const double a, const double b);              //!< a function that compares two numbers and return 1 if they are equal or very close to equal and 0 if not.

 #endif
