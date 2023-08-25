#include "Solve.h"
            // ctype.h isfinite isnan

const double EPS = 1e-9;

bool CompareDouble (double a, double b)
    {
    Assert(isfinite(a));
    assert(isfinite(b));
    assert(!isnan(a));
    assert(!isnan(b));


    if (fabs (a - b) < EPS)
        return 1;
    else
        return 0;
    }

roots SolveSquare(coeffs* coef, double* root1, double* root2)
    {


    if (CompareDouble (coef->a, 0))
        {
        return SolveLinear (coef, root1);

        }

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    if (D < 0)
        return NO_ROOT;
    else if (CompareDouble (D, 0))
        {
        *root1 = - coef->b / (2 * coef->a);
        return ONE_ROOT;
        }
    else
        {
        *root1 = (-coef->b + sqrt (D)) / (2 * coef->a);
        *root2 = (-coef->b - sqrt (D)) / (2 * coef->a);
        return TWO_ROOT;
        }

    }

roots SolveLinear (coeffs* coef, double* root1)
    {
    if (CompareDouble (coef->b, 0))
        if (CompareDouble (coef->c, 0))
            return INF_ROOT;
        else
            return NO_ROOT;
    else
        {
        *root1 = - coef->c / coef->b;
        return ONE_ROOT;
        }
    }



void ReedCommandString(int number_chars, char* command[], coeffs* coef)
{
    char file[10] = "--file";

    for(int i = 0; i < number_chars; i++)
    {
        //printf("%s\n", command[i]);
        if(!strcmp(command[i], file))
        {
            ReedFromFile(command[i + 1], coef);
        }
    }

}

void ReedFromFile(char* filename, coeffs* coef)
{
    int number_roots;
    double root1 = 0, root2 = 0;

    FILE *F;

    if( (F = fopen(filename, "r")) != NULL )
    {
        while (fscanf(F, "%lg %lg %lg ", &coef->a, &coef->b, &coef->c) != EOF)
        {
            printf("%lg %lg %lg\n", coef->a, coef->b, coef->c);
            number_roots = SolveSquare(coef, &root1, &root2);
            PrintRoot( root1, root2, number_roots);
        }
        fclose(F);
    }
    else
        printf("file didn't open\n");

}
