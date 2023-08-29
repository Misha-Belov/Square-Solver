#include "Solve.h"

void FlushBuffer()
{
    while( getchar() != '\n')
    {
    }
}

void ScanCoeff(double* coef)
{
    while(!scanf("%lg", coef))
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        FlushBuffer();
    }
}

void scan_decision(int* option_of_decision)
{
    while(!scanf("%d", option_of_decision))
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        FlushBuffer();
    }

    if(*option_of_decision > 2 || *option_of_decision < 1)
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        FlushBuffer();
        scan_decision(option_of_decision);
    }


}

void InputCoeff(coeffs* coef)
{
    printf("Input coeff A: \n");
    ScanCoeff(&coef->a);
    FlushBuffer();

    printf("Input coeff B: \n");
    ScanCoeff(&coef->b);
    FlushBuffer();

    printf("Input coeff C: \n");
    ScanCoeff(&coef->c);
    FlushBuffer();
}



void PrintRoot(const roots* root, int number_roots)
{
    ASSERT(isfinite(root->root1));
    ASSERT(isfinite(root->root2));
    ASSERT(!isnan(root->root1));
    ASSERT(!isnan(root->root2));


    switch(number_roots)
    {
    case NO_ROOT:
        printf("No roots \n\n");
        break;
    case ONE_ROOT:
        printf("One root: %lg \n\n", root->root1);
        break;
    case TWO_ROOT:
        printf("Two roots: %lg and %lg \n\n", root->root1, root->root2);
        break;
    case INF_ROOT:
        printf("Infinity roots \n\n");
        break;
    default:
        break;
    }
}
