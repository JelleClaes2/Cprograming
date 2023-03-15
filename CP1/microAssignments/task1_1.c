/*
    Zorg ervoor dat de variabele "getal" maar 2 bytes geheugenruimte inneemt en zowel de grootte als het getal zelf uitprint.
*/

#include <stdio.h>

int main( void )
{
    short getal = 0x4242;

    printf( "grootte = %d & getal = %lld\n", sizeof( getal ), getal );
    return 0;
}
