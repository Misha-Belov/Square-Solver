#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strcpy(char dest[], const char* src);
char* my_strncpy(char dest[], const char* src, int n);
int my_strlen(const char* dest);
void my_puts(const char* str);
char *my_strchr(char* str, int sim);
char* my_strcat(char* dest, const char* src);

int main()
{
    int len_dest = 0, put = 0;

    printf("For string: 123456789\n");

    printf("1: puts, 2: strchr, 3: strlen, 4: strcpy, 5: strncpy, 6: strcat, 7: strncat, 8: fgets, 9: strdup, 10: getline\n");
    scanf("%d", &put);

    switch(put)
    {
        case 1:
        {
            char num[10] = "123456789";
            printf("My version: ");
            my_puts(num);
            printf("Original: ");
            puts(num);
            break;
        }
        case 2:
        {
            int ch = '4';
            char num[10] = "123456789";
            printf("My version: \n");
            printf("first number 4 is on %d place\n", my_strchr(num, ch) - num + 1);
            printf("Original: \n");
            printf("first number 4 is on %d place\n", strchr(num, ch) - num + 1);
            break;
        }
        case 3:
        {
            char num[10] = "123456789";
            printf("My version: length of string is: %d \n", my_strlen(num));
            printf("Original: length of string is: %d \n", my_strlen(num));
            break;
        }
        case 4:
        {
            char num[10] = "123456789";
            char cpy1[10];
            char cpy2[10];
            my_strcpy(cpy1, num);
            strcpy(cpy2, num);
            printf("My version: ");
            my_puts(cpy1);
            printf("Original: ");
            my_puts(cpy2);
            break;
        }
        case 5:
        {
            char num[10] = "123456789";
            char cpy1[6];
            char cpy2[6];
            my_strncpy(cpy1, num, 5);
            strncpy(cpy2, num, 5);
            printf("My version: ");
            my_puts(cpy1);
            printf("Original: ");
            my_puts(cpy2);
            break;
        }
        case 6:
        {
            char dest_1[6] = "12345";
            char app_1[4] = "789";
            char dest_2[6] = "12345";
            char app_2[4] = "789";
            printf("My version: ");
            my_puts(my_strcat(dest_2, app_2));
            printf("Original: ");
            my_puts(strcat(dest_2, app_2));
            break;
        }
        case 7:
        {
            char num[7] = "123456";
            printf("my version:");
            printf("original");
            break;
        }
        case 8:
        {
            char num[7] = "123456";
            printf("my version:");
            printf("original");
            break;
        }
        case 9:
        {
            char num[7] = "123456";
            printf("my version:");
            printf("original");
            break;
        }
        case 10:
        {
            char num[7] = "123456";
            printf("my version:");
            printf("original");
            break;
        }
        default:
            break;
    }


}

char* my_strcpy(char dest[], const char* src)
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

char* my_strcat(char* dest, const char* src)
{
    assert(dest);
    assert(src);
    assert(src != dest);

    int i = 0, j = 0;

    for(; dest[j] != '\0'; i++)
    {
    }

    for(; src[i] != '\0'; i++, j++)
    {
        dest[j + 1] = src[i];
    }



    return dest;
}

char* my_strncpy(char dest[], const char* src, int n)
{
    assert(dest);
    assert(src);
    assert(src != dest);

    int i = 0;

    for(; src[i] != '\0' && i <= (n - 1); i++)
    {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }



    return dest;
}

int my_strlen(const char* dest)
{
    assert(dest);

    int i = 0;

    for(; dest[i] != '\0'; i++)
    {
    }
    return i;
}

void my_puts(const char* str)
{
    assert(str);

    printf("%s", str);

    printf("\n");
}

char *my_strchr(char* str, int sim)
{
    assert(str);

    int i = 0;

    while(str[i] != sim)
    {
        i++;
    }
    return &str[i];
}
