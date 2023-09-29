#include "Solve.h"

void flush_buffer()
{
    while(getchar() != '\n')
    {
    }
}

bool scan_coeff(double* coef)
{
    int warning = scanf("%lg", coef);

    if(warning == EOF)
    {
        return false;
    }

    while(!warning)
    {
        printf("WRONG INPUT, TRY AGAIN:\n");
        flush_buffer();
    }

    return true;
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

bool input_coeff(Coeffs* coef)
{
    printf("Input coeff A: \n");
    if(!scan_coeff(&coef->a))
        return false;
    flush_buffer();

    printf("Input coeff B: \n");
    if(!scan_coeff(&coef->b))
        return false;
    flush_buffer();

    printf("Input coeff C: \n");
    if(!scan_coeff(&coef->c))
        return false;
    flush_buffer();

    return true;
}



void print_root(const Roots* root, int number_roots)
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
            assert(number_roots == NO_ROOT  ||
                   number_roots == ONE_ROOT ||
                   number_roots == TWO_ROOT ||
                   number_roots == INF_ROOT);
            break;
    }
}

void read_command_line(const int number_chars, const char* command[], Coeffs* coef)
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

void read_from_file(const char* filename, Coeffs* coef)
{
    int number_roots;
    struct Roots root = {.root1 = NAN, .root2 = NAN};

    FILE *file = fopen(filename, "r");

    if( file == NULL )
    {
        printf("file didn't open\n");
        return;
    }

    while (fscanf(file, "%lg %lg %lg ", &coef->a, &coef->b, &coef->c) != EOF)
    {
        printf("%lg %lg %lg\n", coef->a, coef->b, coef->c);
        number_roots = solve_square(coef, &root);
        print_root(&root, number_roots);
    }

    fclose(file);
}
