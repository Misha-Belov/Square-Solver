#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Test.h"
#include "Solve.h"


/*int InputCoeffs( double coeffs, int Ncoeffs );
int SolveSquare( double coeffs, int Ncoeffs, double roots, int Nroots );
int PrintRoots( double roots, int Nroots );  */




int main(int argc, char* argv[])
{
    /*const int ncoeffs = 3;
    const int nroots = 2;  */

    //int argc;
    //char *argv[15];


    //double x1 = 0, x2 = 0;
    //int num = 0;

    struct coeffs c = {.a = 0, .b = 0, .c = 0} ;

    ReedCommandString(argc, argv, &c);

    //InputCoeff(&c);

    //printf("%lg %lg %lg \n", c.a, c.b, c.c);

    //num = SolveSquare1(&c, &x1, &x2);

    //PrintRoot( x1, x2, num );


    TestAll();


/*   double coeffs[ncoeffs] = {};
    InputCoeffs(coeffs, ncoeffs);

    InputCoeff(&a, &b, &c);

    double roots[nroots] = {};
    SolveSquare(coeffs, ncoeffs, roots, nroots);

    PrintRoots(roots, nroots);                 */
}

void FlashBufer()
{
    while( getchar() != '\n')
    {
    }
}

void ScanCoeff( double* coeff )
{
    while(!scanf("%lg", coeff))
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        FlashBufer();
    }
}

void InputCoeff( coeffs* c)
{


    printf("Input coeff A: \n");
    ScanCoeff(&c->a);

    printf("Input coeff B: \n");
    ScanCoeff(&c->b);

    printf("Input coeff C: \n");
    ScanCoeff(&c->c);
}



void PrintRoot( double x1, double x2, int num )
{
    assert(isfinite(x1));
    assert(isfinite(x2));
    assert(!isnan(x1));
    assert(!isnan(x2));


    switch(num)
    {
    case NO_ROOT:
        printf("No roots \n\n");
        break;
    case ONE_ROOT:
        printf("One root: %lg \n\n", x1);
        break;
    case TWO_ROOT:
        printf("Two roots: %lg and %lg \n\n", x1, x2);
        break;
    case INF_ROOT:
        printf("Infinity roots \n\n");
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

