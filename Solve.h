#ifndef SOLVE_H
#define SOLVE_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

//! An enum.
/**
 * enum shows quantity of roots for exact problem
 */

enum roots {NO_ROOT = 0,    /**< enum for no roots */
            ONE_ROOT = 1,   /**< enum for one root */
            TWO_ROOT = 2,   /**< enum for two roots */
            INF_ROOT = 8};  /**< enum for infinity roots */

/*! A structer for coefficients in the equation*/

struct coeffs {double a, b, c;};

void FlashBufer();                                          //!< a function that delete simbols from bufer.
void ScanCoeff( double* coeff);                             //!< a function that put coefficients from keyboard to structer and control them.
void InputCoeff( coeffs* c);                                //!< a function that asks user for coefficients.
void PrintRoot( double x1, double x2, int num );            //!< a function that print roots of user's equation.

roots SolveSquare1( coeffs* c, double *x1, double *x2 );    //!< a function that solves equation in common situations.
roots SolveLinear(coeffs* c, double *x1);                   //!< a function that solves equation when main coefficient is zero.
bool CompareDouble(double a, double b);                     //!< a function that compares two numbers.

 #endif
