#include <stdio.h>
#include <string.h>
#include "display.h"
#include "ucp_string.h"

int main(int argc, char*argv[])
{
    char str[STR] = "", t1[STR] = "", t2[STR] = "", c1[STR] = "", c2[STR] = "";
    if( argc != 6 )
    {
        printf("Usage: ./text \"The String\" <Text 1> <Text 2> <Color 1> <Color 2>\n");
        printf("        Where Text  1: Text to be replaced\n");
        printf("              Text  2: Text that will replace Text 1\n");
        printf("              Color 1: Color for Text 1\n");
        printf("              Color 2: Color for Text 2\n"); 
    }   
    else
    {
        strcpy(str, argv[1]);
        strcpy(t1, argv[2]);
        strcpy(t2, argv[3]);
        strcpy(c1, argv[4]);
        strcpy(c2, argv[5]);
        toUpper( c1 ); 
        toUpper( c2 );
        display(str, t1, t2, c1, c2);
    }
    return 0;
}
