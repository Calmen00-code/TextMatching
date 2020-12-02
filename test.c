#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE !FALSE

#define STR 100

int main(int argc, char*argv[])
{
    char str[100] = "he ";
    char copy[100] = "loves helicopter";
    int i, ii = 3;

    for( i = 0; copy[i] != '\0'; i++ )
    {
        str[ii] = copy[i];
        ii++;
    }

    printf("%s\n", str);
    return 0;
}
