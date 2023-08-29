#include <stdlib.h>

#ifdef NDEBUG
#define ASSERT(condition) ((void)0)
#else
#define ASSERT(condition) ({ \
if (!condition) {            \
    printf("Assertion failed: in file: %s, in function: %s, in line: %d", __FILE__, __FUNCTION__, __LINE__);           \
    abort();            \
}         })
#endif

