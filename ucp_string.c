#include <stdio.h>
#include <string.h>
#include "display.h"
#include "colour.h"
#include "ucp_string.h"

void ucp_strcpy( char *dest, char *src )
{
    int i;
    int srcLen = strlen(src);
    for( i = 0; i < srcLen; i++ )
        dest[i] = src[i]; 

    dest[srcLen] = '\0';
}

void ucp_strncpy( char *s, char *str, int startIdx )
{
    int i = startIdx, j = 0;

    /* Copy items from str starting from startIdx */
    /* Everything comes before startIdx will be ignored */
    for( i = startIdx; str[i] != '\0'; i++ )
    {
        s[j] = str[i];
        j++;
    }
    s[j] = '\0';
}

/* This function is used to get a copy of the text to be replaced */
void copyText( char *str, char *copy, int currIdx, int copyIdx )
{
    int i, j = 0;

    for( i = currIdx; i <= copyIdx; i++ )
    {
        copy[j] = str[i];
        j++;
    }
}

int isAlpha( char i )
{
    int status = FALSE;

    if( (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'A') )
        status = TRUE;

    return status;
}

int ucp_strcmp( char s1[], char s2[] )
{
    int status = TRUE;
    int len1 = 0, len2 = 0;
    int i = 0;

    len1 = strlen(s1);
    len2 = strlen(s2);

    if( len1 == len2 )
    {
        while( status == TRUE && (i < len1) )
        {
            if( s1[i] != s2[i] )
                status = FALSE;
            i++;
        }
    }
    else
        status = FALSE;
    return status;
}

void toUpper( char *str )
{
    int i;
    for( i = 0; str[i] != '\0'; i++ )
    {
        if( str[i] >= 'a' && str[i] <= 'z' )
            str[i] -= 32;
    }
}
