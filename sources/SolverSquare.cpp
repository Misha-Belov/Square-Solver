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
    int option_of_decision = 0;
    /*const int ncoeffs = 3;
    const int nroots = 2;  */

    //int argc;
    //char *argv[15];


    double root1 = 0, root2 = 0;
    int number_roots = 0;

    struct coeffs coef = {.a = 0, .b = 0, .c = 0} ;

    ReedCommandString(argc, argv, &coef);

    printf("Write 1 if you want to start testing or 2 if you want to input numbers:\n");
    scanf("%d", &option_of_decision);

    switch(option_of_decision)
    {
        case 1:
            TestAll();
            break;
        case 2:
            InputCoeff(&coef);
            number_roots = SolveSquare(&coef, &root1, &root2);
            PrintRoot( root1, root2, number_roots );
            break;
        default:
            break;

    }






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

void ScanCoeff( double* coef )
{
    while(!scanf("%lg", coef))
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        FlashBufer();
    }
}

void InputCoeff( coeffs* coef)
{


    printf("Input coeff A: \n");
    ScanCoeff(&coef->a);

    printf("Input coeff B: \n");
    ScanCoeff(&coef->b);

    printf("Input coeff C: \n");
    ScanCoeff(&coef->c);
}



void PrintRoot( double root1, double root2, int number_roots )
{
    Assert(isfinite(root1));
    Assert(isfinite(root2));
    Assert(!isnan(root1));
    Assert(!isnan(root2));


    switch(number_roots)
    {
    case NO_ROOT:
        printf("No roots \n\n");
        break;
    case ONE_ROOT:
        printf("One root: %lg \n\n", root1);
        break;
    case TWO_ROOT:
        printf("Two roots: %lg and %lg \n\n", root1, root2);
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

