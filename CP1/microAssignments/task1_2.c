/*
    Zorg ervoor dat de variabele "getal" maar 4 bytes geheugenruimte inneemt en zowel de grootte als het getal zelf uitprint.
*/

#include <stdio.h>

int main( void )
{
    int getal = 04242424242;

    printf( "grootte = %d & getal = %lld\n", sizeof( getal ), getal );
    return 0;
}
