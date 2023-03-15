/*
  Print de inhoud van de variabele getal af in wetenschappelijke notatie met maar 2 decimale na de komma.
  Gebruik de correcte format specifier.
*/
#include <stdio.h>

int main( void )
{
    float getal = 5361;

    printf( "Getal = %.2e\n", getal );
    return 0;
}