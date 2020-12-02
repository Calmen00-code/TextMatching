#include <stdio.h>
#include <string.h>
#include "colour.h"
#include "display.h"
#include "ucp_string.h"

void getColorText( char *inColour, char *colorCode )
{
    toUpper( inColour );
     
    if( ucp_strcmp(inColour, "RED") == TRUE )
        strcpy(colorCode, RED);

    else if( ucp_strcmp(inColour, "GREEN") == TRUE )
        strcpy(colorCode, GRN);

    else if( ucp_strcmp(inColour, "YELLOW") == TRUE )
        strcpy(colorCode, YEL);

    else if( ucp_strcmp(inColour, "BLUE") == TRUE )
        strcpy(colorCode, BLU);

    else if( ucp_strcmp(inColour, "MAGENTA") == TRUE )
        strcpy(colorCode, MAG);

    else if( ucp_strcmp(inColour, "CYAN") == TRUE )
        strcpy(colorCode, CYN);
}

void getColorHighlight( char *inColour, char *highlightCode )
{
    toUpper( inColour );
    
    if( ucp_strcmp(inColour, "RED") == TRUE )
        strcpy(highlightCode, REDB);

    else if( ucp_strcmp(inColour, "GREEN") == TRUE )
        strcpy(highlightCode, GRNB);

    else if( ucp_strcmp(inColour, "YELLOW") == TRUE )
        strcpy(highlightCode, YELB);

    else if( ucp_strcmp(inColour, "BLUE") == TRUE )
        strcpy(highlightCode, BLUB);

    else if( ucp_strcmp(inColour, "MAGENTA") == TRUE )
        strcpy(highlightCode, MAGB);

    else if( ucp_strcmp(inColour, "CYAN") == TRUE )
        strcpy(highlightCode, CYNB);
}

void getUnderlineText( char *inColour, char *underlineCode )
{
    toUpper( inColour );

    if( ucp_strcmp(inColour, "RED") == TRUE )
        strcpy(underlineCode, URED);

    else if( ucp_strcmp(inColour, "GREEN") == TRUE )
        strcpy(underlineCode, UGRN);

    else if( ucp_strcmp(inColour, "YELLOW") == TRUE )
        strcpy(underlineCode, UYEL);

    else if( ucp_strcmp(inColour, "BLUE") == TRUE )
        strcpy(underlineCode, UBLU);

    else if( ucp_strcmp(inColour, "MAGENTA") == TRUE )
        strcpy(underlineCode, UMAG);

    else if( ucp_strcmp(inColour, "CYAN") == TRUE )
        strcpy(underlineCode, UCYN);
}
