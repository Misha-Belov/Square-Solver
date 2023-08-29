#include "Solve.h"

const double EPS = 1e-9;

bool is_equal(const double a, const double b)
{
    if (fabs (a - b) < EPS)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ENUM_ROOTS solve_square(COEFFS* coef, ROOTS* root)
{
    ASSERT(!isnan(coef->a));

    if (is_equal(coef->a, 0))
    {
        return solve_linear(coef, root);
    }

    double D = coef->b * coef->b - 4 * coef->a * coef->c;

    ASSERT(!isnan(D));

    if (is_equal(D, 0))
    {
        root->root1 = - coef->b / (2 * coef->a);
        root->root2 = 0;

        return ONE_ROOT;
    }
    else if (D < 0)
    {
        root->root1 = 0;
        root->root2 = 0;

        return NO_ROOT;
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
    {
        if (is_equal(coef->c, 0))
        {
            root->root1 = 0;
            root->root2 = 0;

            return INF_ROOT;
        }
        else
        {
            root->root1 = 0;
            root->root2 = 0;

            return NO_ROOT;
        }
    }
    else
    {
        root->root1 = - coef->c / coef->b;
        root->root2 = 0;

        return ONE_ROOT;
    }
}




