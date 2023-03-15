/*
  Print de inhoud van de variabele getal af in wetenschappelijke notatie.
  Gebruik de correcte format specifier.
*/
#include <stdio.h>

int main( void )
{

    float getal = 5361;

    printf( "Getal = %e\n", getal );
    return 0;
}