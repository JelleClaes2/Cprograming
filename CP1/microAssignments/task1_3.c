/*
    Zorg ervoor dat de variabele "getal" maar 8 bytes geheugenruimte inneemt en zowel de grootte als het getal zelf uitprint.
*/

#include <stdio.h>

int main( void )
{
    long getal = -0xdadab00b135;

    printf( "grootte = %d & getal = %lld\n", sizeof( getal ), getal );
    return 0;
}
