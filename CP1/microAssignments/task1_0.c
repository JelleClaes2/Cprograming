/*
    Zorg ervoor dat de variabele "getal" maar 1 byte geheugenruimte inneemt en zowel de grootte als het getal zelf uitprint.
*/

#include <stdio.h>

int main( void )
{
    char getal = 42;

    printf( "grootte = %d & getal = %lld\n", sizeof( getal ), getal );
    return 0;
}
