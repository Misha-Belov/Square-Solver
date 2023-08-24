#ifndef SOLVE_H
#define SOLVE_H

#include <stdio.h>
#include <math.h>



enum roots {NO_ROOT = 0, ONE_ROOT = 1, TWO_ROOT = 2, INF_ROOT = 8};

struct coeffs {double a, b, c;};

void InputCoeff( coeffs* c);
void PrintRoot( double x1, double x2, int num );

roots SolveSquare1( coeffs* c, double *x1, double *x2 );
roots SolveLinear(coeffs* c, double *x1);
int CompareDouble(double a, double b);

 #endif
