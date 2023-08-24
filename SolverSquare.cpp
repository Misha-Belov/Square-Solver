#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Test.h"
#include "Solve.h"


/*int InputCoeffs( double coeffs, int Ncoeffs );
int SolveSquare( double coeffs, int Ncoeffs, double roots, int Nroots );
int PrintRoots( double roots, int Nroots );  */





int main()
{
    /*const int ncoeffs = 3;
    const int nroots = 2;  */

    double x1 = 0, x2 = 0;
    int num = 0;

    struct coeffs c = {.a = 0, .b = 0, .c = 0} ;

    InputCoeff(&c);

    printf("%lg %lg %lg \n", c.a, c.b, c.c);

    num = SolveSquare1(&c, &x1, &x2);

    PrintRoot( x1, x2, num );


    TestAll();


/*   double coeffs[ncoeffs] = {};
    InputCoeffs(coeffs, ncoeffs);

    InputCoeff(&a, &b, &c);

    double roots[nroots] = {};
    SolveSquare(coeffs, ncoeffs, roots, nroots);

    PrintRoots(roots, nroots);                 */
}



void InputCoeff( coeffs* c)
{
    printf("Input coeff A: \n");
    if(!scanf("%lg", &c->a))
        exit(EXIT_FAILURE);

    printf("Input coeff B: \n");
    if(!scanf("%lg", &c->b))
        exit(EXIT_FAILURE);

    printf("Input coeff C: \n");
    if(!scanf("%lg", &c->c))
        exit(EXIT_FAILURE);
}



void PrintRoot( double x1, double x2, int num )
{
    switch(num)
    {
    case NO_ROOT:
        printf("No roots \n");
        break;
    case ONE_ROOT:
        printf("One root: %lg \n", x1);
        break;
    case TWO_ROOT:
        printf("Two roots: %lg and %lg \n", x1, x2);
        break;
    case INF_ROOT:
        printf("Infinity roots \n");
        break;
    default:
        break;
    }
}



/*
int InputCoeffs( double coeffs, int Ncoeffs )
{
    int i = 0;
    for(;i < Ncoeffs; i++)
    {
        printf("Input coeff %d", i);
        scanf("%lg", coeffs[i]);
    }
}

int SolveSquare( double coeffs, int Ncoeffs, double roots, int Nroots )
{
    roots[1] = 1;
    roots[2] = 2;
}

int PrintRoots( double roots, int Nroots )
{
    int i = 0;
    for(;i < Nroots; i++)
    {
        print("%lg", roots[i]);
    }
}
    */

