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

void read_command_line(const int number_chars, const char* command[], COEFFS* coef)
{
    const char file[] = "--file";

    for(int i = 0; i < number_chars; i++)
    {
        if(!strcmp(command[i], file))
        {
            read_from_file(command[i + 1], coef);
        }
    }
}

void read_from_file(const char* filename, COEFFS* coef)
{
    int number_roots;
    struct ROOTS root = {.root1 = NAN, .root2 = NAN};

    FILE *F = fopen(filename, "r");

    if( F == NULL )
    {
        printf("file didn't open\n");
        return;
    }

    while (fscanf(F, "%lg %lg %lg ", &coef->a, &coef->b, &coef->c) != EOF)
    {
        printf("%lg %lg %lg\n", coef->a, coef->b, coef->c);
        number_roots = solve_square(coef, &root);
        print_root(&root, number_roots);
    }

    fclose(F);
}
