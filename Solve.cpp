#include "Solve.h"
            // ctype.h isfinite isnan

const double EPS = 1e-9;

bool CompareDouble (double a, double b)
    {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(!isnan(a));
    assert(!isnan(b));


    if (fabs (a - b) < EPS)
        return 1;
    else
        return 0;
    }

roots SolveSquare1 (coeffs* c, double* x1, double* x2)
    {


    if (CompareDouble (c->a, 0))
        {
        return SolveLinear (c, x1);

        }

    double D = c->b * c->b - 4 * c->a * c->c;

    if (D < 0)
        return NO_ROOT;
    else if (CompareDouble (D, 0))
        {
        *x1 = - c->b / (2 * c->a);
        return ONE_ROOT;
        }
    else
        {
        *x1 = (-c->b + sqrt (D)) / (2 * c->a);
        *x2 = (-c->b - sqrt (D)) / (2 * c->a);
        return TWO_ROOT;
        }

    }

roots SolveLinear (coeffs* c, double* x1)
    {
    if (CompareDouble (c->b, 0))
        if (CompareDouble (c->c, 0))
            return INF_ROOT;
        else
            return NO_ROOT;
    else
        {
        *x1 = - c->c / c->b;
        return ONE_ROOT;
        }
    }



void ReedCommandString(int charnum, char* command[], coeffs* coef)
{
    int i = 0;
    char file[10] = "--file";

    for(; i < charnum; i++)
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
    int num;
    double x1 = 0, x2 = 0;

    FILE *F;

    if( (F = fopen(filename, "r")) != NULL )
    {
        while (fscanf(F, "%lg %lg %lg ", &coef->a, &coef->b, &coef->c) != EOF)
        {
            printf("%lg %lg %lg\n", coef->a, coef->b, coef->c);
            num = SolveSquare1(coef, &x1, &x2);
            PrintRoot( x1, x2, num );
        }
        fclose(F);
    }
    else
        printf("file didn't open\n");

}
