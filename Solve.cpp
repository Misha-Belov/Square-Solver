#include "Solve.h"
            // ctype.h isfinite isnan

const double EPS = 1e-9;

int CompareDouble (double a, double b)
    {
    assert()
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
