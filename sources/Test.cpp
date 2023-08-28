#include "Solve.h"
#include "Test.h"


#include "ANSI-color-codes.h"


int FileReader(test* expect)
{
    int number_Ok = 0;

    FILE *F;

    if( (F = fopen("txt/test.txt", "r")) != NULL )
    {
        while (fscanf(F, "%lg %lg %lg %lg %lg %d %s", &expect->expect_coef.a, &expect->expect_coef.b, &expect->expect_coef.c, &expect->root1, &expect->root2, &expect->number_roots, expect->test_name) != EOF)
        {
            printf(GRN "%lg %lg %lg %lg %lg %d %s\n" reset, expect->expect_coef.a, expect->expect_coef.b, expect->expect_coef.c, expect->root1, expect->root2, expect->number_roots, expect->test_name);
            number_Ok += TestOne(expect);
        }
        fclose(F);
    }
    else
        printf("file didn't open");

    return number_Ok;
}

void TestAll()
{
    int number_Ok = 0;

    /*test ref[TEST_NUM] = {{{1, 4, 4},-2, 0, 1, "ONE_ROOT"},
                        {{1, 0, -4}, 2, -2, 2, "TWO_ROOTS"},
                        {{0, 0, 1}, 0, 0, 0, "NO_ROOTS"},
                        {{0, 0, 0}, 0, 0, 8, "INF_ROOTS"},
                        {{0, 1, -1}, 1, 0, 1, "LINEAR"}};
    for(;i < TEST_NUM; i++)
        nOk += TestOne(&ref[i]);
    */

    test expect = {};

    number_Ok = FileReader(&expect);




    printf ("TestOk: %d out of %d\n", number_Ok, TEST_NUM);
}

bool TestOne(const test* expect)
{
    double root1 = 0, root2 = 0;

    struct coeffs coef = {expect->expect_coef.a, expect->expect_coef.b, expect->expect_coef.c} ;



    int number_roots = SolveSquare(/*&ref->ec*/ &coef, &root1, &root2);

    if( !CompareDouble(root1, expect->root1)|| !CompareDouble(root2, expect->root2) || !CompareDouble(number_roots, expect->number_roots) )
    {
        printf( BRED "ERROR in %s x1 = %lg, x2 = %lg, numroots = %d \nINSTEAD OF: x1 = %lg, x2 = %lg, numroots = %d \n" reset, expect->test_name, root1, root2, number_roots, expect->root1, expect->root2, expect->number_roots);
        return 0;
    }
    else
        return 1;

}
