/*
  Zorg dat de tafels mooi onder elkaar afgeprint worden en de lijntjes dus recht zijn.
  De tafels van 0 t.e.m. 99 worden gegenereerd, dus het antwoord kan tussen de 0 en 9900 liggen.
  HINT : gebruik de "field width" in de "format specifier" (zie documentatie over printf). Je kan deze oplossen met 2 kleine aanpassingen.
*/
#include <stdio.h>

int main( void )
{
    int getal = 0;
    printf( "Geef een getal tussen 0 en 100 :" );
    scanf( "%d", &getal );
    printf( "De tafels van %d zijn :\n", getal );
    for( int i = 0; i < 25; i++ )
    {
        for( int j = 0; j < 100; j += 25 )
        {
            printf( "%d x %2d = %4d | ", getal, i + j, getal * ( i + j ) );
        }
        printf( "\n" );
    }
    return 0;
}