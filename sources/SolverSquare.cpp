#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Test.h"
#include "Solve.h"

int main(int argc, const char* argv[])
{
    int option_of_decision = 0;
    struct COEFFS coef = {.a = 0, .b = 0, .c = 0};

    read_command_line(argc, argv, &coef);

    printf("Write 1 if you want to start testing or 2 if you want to input numbers:\n");

    scan_decision(&option_of_decision);
    process_options(&coef, option_of_decision);
}

void process_options(COEFFS* coef, int option_of_decision)
{
    switch(option_of_decision)
    {
        case 1:
            test_all();
            break;
        case 2:
        {
            input_coeff(coef);

            struct ROOTS root = {.root1 = 0, .root2 = 0};
            int number_roots = 0;

            number_roots = solve_square(coef, &root);
            print_root(&root, number_roots);

            break;
        }
        default:
            break;
    }
}






