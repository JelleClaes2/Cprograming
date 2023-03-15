/*
  Print de inhoud van de variabele getal1 tot en met getal 5 af als karakters zonder spaties tussen om één woord te vormen.
  Gebruik de correcte format specifiers.
*/
#include <stdio.h>

int main( void )
{
    int getal1 = 68;
    int getal2 = 111;
    int getal3 = 110;
    int getal4 = 101;
    int getal5 = 33;

    printf( "%c%c%c%c%c\n", getal1, getal2, getal3, getal4, getal5 );
    return 0;
}