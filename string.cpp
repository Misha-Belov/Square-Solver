#include <stdio.h>
#include <string.h>
#include <assert.h>

char* MyStrcpy(char dest[], const char* src);
int MyStrlen(const char* dest);

int main()
{
    int len_dest = 0;

    char src[] = "ABC";
    char dest[] = "";

    MyStrcpy(dest, src);
    len_dest = MyStrlen(dest);


    printf("%s, length is: %d", dest, len_dest);
}

char* MyStrcpy(char dest[], const char* src)
{
    assert(dest);
    assert(src);
    assert(src != dest);

    int i = 0;

    for(; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }



    return dest;
}

int MyStrlen(const char* dest)
{
    assert(dest);

    int i = 0;

    for(; dest[i] != '\0'; i++)
    {
    }



    return i;
}
