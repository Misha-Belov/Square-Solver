#include "Solve.h"

void flush_buffer()
{
    while( getchar() != '\n')
    {
    }
}

void scan_coeff(double* coef)
{
    while(!scanf("%lg", coef))
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        flush_buffer();
    }
}

void scan_decision(int* option_of_decision)
{
    while(!scanf("%d", option_of_decision))
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        flush_buffer();
    }

    if(*option_of_decision > 2 || *option_of_decision < 1)
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        flush_buffer();
        scan_decision(option_of_decision);
    }


}

void input_coeff(COEFFS* coef)
{
    printf("Input coeff A: \n");
    scan_coeff(&coef->a);
    flush_buffer();

    printf("Input coeff B: \n");
    scan_coeff(&coef->b);
    flush_buffer();

    printf("Input coeff C: \n");
    scan_coeff(&coef->c);
    flush_buffer();
}



void print_root(const ROOTS* root, int number_roots)
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
