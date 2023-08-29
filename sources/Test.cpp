#include "Solve.h"
#include "Test.h"


#include "ANSI-color-codes.h"


int file_reader(TEST* expect, int* number_tests)
{
    FILE *F = fopen("txt/test.txt", "r");

    if( F == NULL )
    {
        printf("file didn't open"); ;
        return 0;
    }

    int number_Ok = 0;

    while (fscanf(F, "%lg %lg %lg %lg %lg %d %s", &expect->expect_coef.a, &expect->expect_coef.b, &expect->expect_coef.c, &expect->expect_root.root1, &expect->expect_root.root2, &expect->number_roots, expect->test_name) != EOF)
    {
        printf(GRN "%lg %lg %lg %lg %lg %d %s\n" CRESET, expect->expect_coef.a, expect->expect_coef.b, expect->expect_coef.c, expect->expect_root.root1, expect->expect_root.root2, expect->number_roots, expect->test_name);
        number_Ok += test_one(expect);
        *number_tests += 1;
    }

    fclose(F);

    return number_Ok;
}

void test_all()
{
    int number_tests = 0;
    TEST expect;
    int number_Ok = file_reader(&expect, &number_tests);

    printf ("TestOk: %d out of %d\n", number_Ok, number_tests);
}

bool test_one(const TEST* expect)
{
    struct ROOTS test_root = {.root1 = NAN, .root2 = NAN};
    struct ROOTS root = {expect->expect_root.root1, expect->expect_root.root2};
    struct COEFFS coef = {expect->expect_coef.a, expect->expect_coef.b, expect->expect_coef.c} ;
    int number_roots = solve_square(&coef, &test_root);

    if(!is_equal(test_root.root1, root.root1)|| !is_equal(test_root.root2, root.root2) || !is_equal(number_roots, expect->number_roots))
    {
        printf( BRED "ERROR in %s x1 = %lg, x2 = %lg, numroots = %d \nINSTEAD OF: x1 = %lg, x2 = %lg, numroots = %d \n" CRESET, expect->test_name, test_root.root1, test_root.root2, number_roots, root.root1, root.root2, expect->number_roots);
        return false;
    }
    else
    {
        return true;
    }
}
