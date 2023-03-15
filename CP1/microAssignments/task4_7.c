/*
	FIX IT !
	--------
  Schrijf een programma dat de rij van Fibonacci afdrukt tot een vooraf ingegeven bovengrens. In de rij van Fibonacci is elk getal de som van de 2 voorgaande getallen te beginnen met 0 en 1.


  0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584...
*/

#include <stdio.h>

int main( void )
{
    unsigned int bovengrens = 0;
    unsigned int vorigGetal = 0;
    unsigned int huidigGetal = 1;
    unsigned int tmpGetal = 0;

    printf( "Geef een bovengrens voor de rij van Fibonacci: " );
    (void)scanf( "%u", &bovengrens );

    // Print the first two numbers
    printf( "%u %u ", vorigGetal, huidigGetal );

    while( huidigGetal +vorigGetal <= bovengrens )
    {
        // Core algorithm
        tmpGetal = huidigGetal;
        huidigGetal += vorigGetal;
        vorigGetal = tmpGetal;

        // Print result
        printf( "%u ", huidigGetal );
    }

    return 0;
}
