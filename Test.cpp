#include "Solve.h"
#include "Test.h"


int FileReader(test* ref)
{
    int nOk = 0;

    FILE *F;

    if( (F = fopen("test.txt", "r")) != NULL )
    {
        while (fscanf(F, "%lg %lg %lg %lg %lg %d %s", &ref->ec.a, &ref->ec.b, &ref->ec.c, &ref->x1, &ref->x2, &ref->nRoots, ref->name) != EOF)
        {
            printf("%lg %lg %lg %lg %lg %d %s\n", ref->ec.a, ref->ec.b, ref->ec.c, ref->x1, ref->x2, ref->nRoots, ref->name);
            nOk += TestOne(ref);
        }
        fclose(F);
    }
    else
        printf("file didn't open");

    return nOk;
}

void TestAll()
{
    int nOk = 0, i = 0;

    /*test ref[TEST_NUM] = {{{1, 4, 4},-2, 0, 1, "ONE_ROOT"},
                        {{1, 0, -4}, 2, -2, 2, "TWO_ROOTS"},
                        {{0, 0, 1}, 0, 0, 0, "NO_ROOTS"},
                        {{0, 0, 0}, 0, 0, 8, "INF_ROOTS"},
                        {{0, 1, -1}, 1, 0, 1, "LINEAR"}};
    for(;i < TEST_NUM; i++)
        nOk += TestOne(&ref[i]);
    */

    test ref[TEST_NUM] = {};

    nOk = FileReader(&ref[i]);




    printf ("TestOk: %d out of %d\n", nOk, TEST_NUM);
}

bool TestOne(const test* ref)
{
    double x1 = 0, x2 = 0;

    struct coeffs c = {ref->ec.a, ref->ec.b, ref->ec.c} ;



    int numroots = SolveSquare1(/*&ref->ec*/ &c, &x1, &x2);

    if( !CompareDouble(x1, ref->x1)|| !CompareDouble(x2, ref->x2) || !CompareDouble(numroots, ref->nRoots) )
    {
        printf("ERROR in %s x1 = %lg, x2 = %lg, numroots = %d \nINSTEAD OF: x1 = %lg, x2 = %lg, numroots = %d \n", ref->name, x1, x2, numroots, ref->x1, ref->x2, ref->nRoots);
        return 0;
    }
    else
        return 1;

}
