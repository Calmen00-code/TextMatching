#ifndef DISPLAY
#define DISPLAY

#define FALSE 0
#define TRUE !FALSE

void display( char*, char*, char*, char*, char* );
void displayStr( char*, char*, char );
void increaseSpace( char*, int );
int replaceText( char*, int, char*, char*, char* );
int createUnderlineText( char*, char*, char*, int );

#endif
