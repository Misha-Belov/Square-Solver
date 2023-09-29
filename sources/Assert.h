#include <stdlib.h>

/*!
    \brief assertion function

    Function that use abort, if the condition in brackets is not met.
    This function prints on the screen information about place, where did the error occur.

*/
#ifdef NDEBUG
#define ASSERT(condition) ((void)0)
#else
#define ASSERT(condition) ({                                 \
    if (!condition)                                          \
    {                                                        \
        printf("Assertion failed: in file: %s,               \
                              in function: %s,               \
                              in line:     %d",              \
                              __FILE__,                      \
                              __FUNCTION__,                  \
                              __LINE__);                     \
        abort();                                             \
    }                                                        \
})
#endif

