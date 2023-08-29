#include "Solve.h"

const double EPS = 1e-9;

bool is_equal(const double a, const double b)
    {
    ASSERT(isfinite(a));
    ASSERT(isfinite(b));
    ASSERT(!isnan(a));
    ASSERT(!isnan(b));


    if (fabs (a - b) < EPS)
        return true;
    else
        return false;
    }

ENUM_ROOTS solve_square(COEFFS* coef, ROOTS* root)
{
    ASSERT(!isnan(coef->a));

    if (is_equal(coef->a, 0))
        {
        return solve_linear (coef, root);
        }

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    ASSERT(!isnan(D));

    if (D < 0)
        return NO_ROOT; // NO_ROOTS
    else if (is_equal(D, 0))
        {
        root->root1 = - coef->b / (2 * coef->a);
        return ONE_ROOT;
        }
    else
        {
        root->root1 = (-coef->b + sqrt (D)) / (2 * coef->a);
        root->root2 = (-coef->b - sqrt (D)) / (2 * coef->a);
        return TWO_ROOT;
        }

    }

ENUM_ROOTS solve_linear (COEFFS* coef, ROOTS* root)
    {
    if (is_equal(coef->b, 0))
        if (is_equal(coef->c, 0))
            return INF_ROOT;
        else
            return NO_ROOT;
    else
        {
        root->root1 = - coef->c / coef->b;
        return ONE_ROOT;
        }
    }



void read_command_line(int number_chars, char* command[], COEFFS* coef)
{
    const char file[] = "--file";

    for(int i = 0; i < number_chars; i++)
    {
        //printf("%s\n", command[i]);
        if(!strcmp(command[i], file))
        {
            read_from_file(command[i + 1], coef);
        }
    }

}

void read_from_file(char* filename, COEFFS* coef)
{
    int number_roots;
    struct ROOTS root = {.root1 = 0, .root2 = 0};


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
