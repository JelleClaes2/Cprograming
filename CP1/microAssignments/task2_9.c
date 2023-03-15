/*
  Ohnoes ! Someone fucked up !!!
  Voorzie dat je enkel op regel 16 verbeterd wordt door de juiste expressie schrijft, waarbij de tafel wordt berekend door de som van a en b te vermeningvuldigen met het gegeven getal.
*/
#include <stdio.h>

int main( void )
{
    int getal = 0;
    printf( "Geef een getal tussen 0 en 100 :" );
    (void)scanf( "%d", &getal );
    printf( "De tafels van %d zijn :\n", getal );
    for( int a = 0; a < 25; a++ )
    {
        for( int b = 0; b < 100; b += 25 )
        {
            int tafel = getal * (a + b); // De som van a en b moet vermeningvuldigd worden met getal
            printf( "%2d x %2d = %4d | ", getal, a + b, tafel );
        }
        printf( "\n" );
    }
    return 0;
}
