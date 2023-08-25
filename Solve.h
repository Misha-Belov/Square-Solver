#ifndef SOLVE_H
#define SOLVE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
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
enum roots {NO_ROOT = 0,    /**< enum for no roots */
            ONE_ROOT = 1,   /**< enum for one root */
            TWO_ROOT = 2,   /**< enum for two roots */
            INF_ROOT = 8};  /**< enum for infinity roots */


/*!
    \brief A structure for coefficients in the equation

    This class also used in test class
*/
struct coeffs {double a, b, c;};

/*!  \fn void FlashBufer()
    \brief function for cleaning

    Function that delete symbols from buffer.

*/

void ReedCommandString(int charnum, char* command[], coeffs* coef);
void ReedFromFile(char* filename, coeffs* coef);
void FlashBufer();                                          //!< a function that delete symbols from buffer.
void ScanCoeff( double* coeff);                             //!< a function that put coefficients from keyboard to structure and control them.
void InputCoeff( coeffs* c);                                //!< a function that asks user for coefficients.

/*! \fn void PrintRoot( double x1, double x2, int num )
    \brief a function that print roots of user's equation.

    \warning  if equality have only one root, put this root on the first place, but second root is staying zero.
    \param x1 first root
    \param x2 second root \warning by default is zero
    \param num number of roots
*/
void PrintRoot( double x1, double x2, int num );


roots SolveSquare1( coeffs* c, double *x1, double *x2 );    //!< a function that solves equation in common situations.
roots SolveLinear(coeffs* c, double *x1);                   //!< a function that solves equation when main coefficient is zero.
bool CompareDouble(double a, double b);                     //!< a function that compares two numbers.

 #endif
