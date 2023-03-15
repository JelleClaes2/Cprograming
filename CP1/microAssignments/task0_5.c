/*
  Print de inhoud van de variabele getal af. Zorg ervoor dat twee nullen worden toegevoegd aan het begin van dit getal (i.e. 005214)
  Gebruik de correcte format specifier.
*/
#include <stdio.h>

int main( void )
{
    int getal = 5214;

    printf( "%06d\n", getal );
    return 0;
}