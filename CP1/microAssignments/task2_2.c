/*
  Schrijf een programma dat de som, het verschil, het product en de deling van 2 reële getallen, die door de gebruiker worden ingegeven, berekent en de resultaten print.
*/
#include <stdio.h>

int main( void )
{
    double getal1 = 0;
    double getal2 = 0;

    printf( "Geef 2 reële getallen in: " );
    (void)scanf( "%lf %lf", &getal1, &getal2 );

    double deling = getal1 / getal2;
    double product = getal1 * getal2;
    double som = getal1 + getal2;
    double verschil = getal1 - getal2;

    printf( "%.2lf + %.2lf = %.2lf\n", getal1, getal2, som );
    printf( "%.2lf - %.2lf = %.2lf\n", getal1, getal2, verschil );
    printf( "%.2lf * %.2lf = %.2lf\n", getal1, getal2, product );
    printf( "%.2lf / %.2lf = %.2lf\n", getal1, getal2, deling );
    printf( "%lu%lu%lu%lu%lu%lu\n", sizeof( getal1 ), sizeof( getal2 ), sizeof( som ), sizeof( verschil ), sizeof( product ), sizeof( deling ) );

    return 0;
}
