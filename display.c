#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "display.h"
#include "colour.h"
#include "ucp_string.h"

void displayStr( char *str, char *space, char cursor )
{
    printf("%s\n", str);
    printf("%s%c\n", space, cursor);
}
    
void display( char *str, char *t1, char *t2, char *c1, char *c2 )
{
    char space[STR] = "", cursor = '^';
    char underlineBefore[STR] = "", underlineAfter[STR] = "";
    char colorOne[STR] = "", colorTwo[STR] = "";
    char checkStr[STR] = "", formatFind[STR] = "";
    int i, ii = 0, jj = 0, iDisplay = 0;
    int len = 0, len1 = 0, len2 = 0, copyIdx = 0;
    int newUnderlineBef = 0, newUnderlineAft = 0, newLen = 0;

    system("clear");
    len = strlen(str);
    len1 = strlen(t1);
    len2 = strlen(t2);
    copyIdx = len1 - 1; /* -1 to prevent overflowing array index */
    getColorText( c1, colorOne );
    getColorText( c2, colorTwo );
    ucp_strcpy( formatFind, t1 );
    toUpper(formatFind);

    /* Iterate every single character in the string */
    for( i = 0; i < len; i++ )
    {
        displayStr( str, space, cursor );

        /* Detecting the text */
        copyText( str, checkStr, i, i+copyIdx );
        toUpper( checkStr );

        /* Compare with uppercase checkStr and 
           uppercase t1 to achieve case insensitive features */
        if( ucp_strcmp(checkStr, formatFind) == TRUE )
        {
            newLen = replaceText(str, i, t1, t2, c2 );
            newUnderlineBef = createUnderlineText(underlineBefore, t1, c1, ii );
            newUnderlineAft = createUnderlineText(underlineAfter, t2, c2, jj );

            system("clear");
            displayStr( str, space, cursor );

            /* i != 0 means this is not the first word is to be changed, 
               so we need to clear screen and display the string again */
            if( i == 0 )
            {
                printf("%s%sreplaced%s\n", space, colorTwo, RESET);
                strcat(space, " ");
            }
            else
            {
                system("clear");
                displayStr( str, space, cursor );
                printf("%s%sreplaced%s\n", space, colorTwo, RESET);
                strcat(space, " ");
            }

            #ifdef INDEX
            printf("index: %d\n", iDisplay);
            #endif

            i += newLen;  /* Update the index to new position */
            ii += newUnderlineBef;
            jj += newUnderlineAft;
            iDisplay += len2 - 1; /* Update on Conditional Compilation index */
            increaseSpace( space, len2 );
            len = strlen(str); /* Update len as it is different after replace */
        }
        else
        {
            underlineBefore[ii] = str[i]; 
            underlineAfter[jj] = str[i];

            /* Detect the last character */
            if( str[i+1] == str[len-1] )
            {
                /* Stop if last character is not alphabet */
                if( isAlpha( str[i+1] ) != TRUE )
                {
                    printf("%s%sEND%s\n", colorTwo, space, RESET);
                    i = len; /* Stop the loop */
                }
                else
                    printf("%s%sno match%s\n", space, colorOne, RESET);
            }
            else
            {
                printf("%s%sno match%s\n", space, colorOne, RESET);
                strcat(space, " ");
            }

            #ifdef INDEX
            printf("index: %d\n", iDisplay);
            #endif
        }
        memset(checkStr, 0, sizeof(char));   /* Reset checkStr */

        /* Display only when the final character is alphabet */
        /* i == len-1 means the loop ends normally without updating */
        if( i == len-1 )
        {
            system("clear");
            displayStr( str, space, cursor );
            printf("%s%sEND%s\n", colorTwo, space, RESET);
        }

        sleep(1);
        system("clear");
        iDisplay++;
        ii++;
        jj++;
    }
    printf("%s\n", underlineBefore);
    printf("%s\n", underlineAfter);
}

/* Increase the space to skip the cursor display since a word is found */
void increaseSpace( char *space, int size )
{
    int i;

    /* size -1 because one space is added initially on line 25 */
    for( i = 0; i < size - 1 ; i++ )
        strcat(space, " ");
}

int replaceText( char *str, int startIdx, char *find, char *replace, char *c2 )
{
    char newStr[STR] = "", before[20] = "", after[20] = "";
    int newLen = 0;
    char background[10] = "", underline[10] = "";
    int findLen = strlen(find);
    
    getColorHighlight( c2, background );
    getUnderlineText( c2, underline );

    /*  If startIdx is not 0, we will need to copy string 
        from beginning until where the string was found     */
    if( startIdx != 0 )
    {
        /* startIdx is where the first word index points to */
        strncpy(before, str, startIdx);
    }

    /*  endIdx + 2 because we will copy 
        starting from the next character of find  */
    ucp_strncpy(after, str, (startIdx+findLen));

    sprintf(newStr, "%s%s%s%s%s", before, background, replace, RESET, after);

    ucp_strcpy( str, newStr );

    /* length of str will be reset once the word is replaced */
    newLen = strlen(background) + (strlen(replace) -1) + strlen(RESET);

    return newLen;
}

int createUnderlineText( char *str, char *find, char *color, int startIdx )
{
    char wordColor[STR] = "", word[30] = "";
    char underlineCode[30] = "";
    int len = 0;

    ucp_strcpy( word, find );
    getUnderlineText( color, underlineCode );

    sprintf(wordColor, "%s%s%s", underlineCode, word, RESET);
    strcat(str, wordColor);

    len = strlen(wordColor) - 1; /* -1 because we want to get the index */
    return len;
}
