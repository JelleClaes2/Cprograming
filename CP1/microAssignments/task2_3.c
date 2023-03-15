/*
  Schrijf een programma dat de waarde van een gegeven geheel getal (x) deelt door zijn increment (x+1) met 4 cijfers na de komma afprint. Bv. 6 maakt 6/7 = 0.8571 ; 42 maakt 42/43 = 0.9767
*/
#include <stdio.h>

int main( void )
{
    int getal = 0;
    float waarde = 0;

    printf( "Geef geheel getal in: " );
    (void)scanf( "%d", &getal );

    waarde = (float) getal / (getal + 1); // expressie voor getal delen door getal plus 1

    printf( "%d / %d = %.4f\n", getal, getal + 1, waarde ); // Hint : kijk de format specifiers na ;-)

    return 0;
}
