#include "Solve.h"
            // ctype.h isfinite isnan

const double EPS = 1e-9;

bool CompareDouble (double a, double b)
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

enum_roots SolveSquare(coeffs* coef, roots* root)
{
    ASSERT(!isnan(coef->a));

    if (CompareDouble (coef->a, 0))
        {
        return SolveLinear (coef, root);
        }

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    ASSERT(!isnan(D));

    if (D < 0)
        return NO_ROOT; // NO_ROOTS
    else if (CompareDouble (D, 0))
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

enum_roots SolveLinear (coeffs* coef, roots* root)
    {
    if (CompareDouble (coef->b, 0))
        if (CompareDouble (coef->c, 0))
            return INF_ROOT;
        else
            return NO_ROOT;
    else
        {
        root->root1 = - coef->c / coef->b;
        return ONE_ROOT;
        }
    }



void ReadCommandLine(int number_chars, char* command[], coeffs* coef)
{
    const char file[] = "--file";

    for(int i = 0; i < number_chars; i++)
    {
        //printf("%s\n", command[i]);
        if(!strcmp(command[i], file))
        {
            ReadFromFile(command[i + 1], coef);
        }
    }

}

void ReadFromFile(char* filename, coeffs* coef)
{
    int number_roots;
    struct roots root = {.root1 = 0, .root2 = 0};


    FILE *F = fopen(filename, "r");
    if( F == NULL )
    {
        printf("file didn't open\n");
        return;
    }

    while (fscanf(F, "%lg %lg %lg ", &coef->a, &coef->b, &coef->c) != EOF)
    {
        printf("%lg %lg %lg\n", coef->a, coef->b, coef->c);
        number_roots = SolveSquare(coef, &root);
        PrintRoot(&root, number_roots);
    }

    fclose(F);
}
