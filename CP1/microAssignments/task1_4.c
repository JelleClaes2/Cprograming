/*
    Zorg ervoor dat de variabele "getal" een kommagetal kan bewaren en maar 4, 8 en 16 bytes geheugenruimte inneemt en steeds zowel de grootte als het getal zelf uitprint.
*/

#include <stdio.h>

int main( void )
{
    float getal4bytes = -0.42;
    double getal8bytes = getal4bytes;
    getal8bytes += getal8bytes / 1000.0;
    long double getal16bytes = getal8bytes;
    getal16bytes += getal16bytes / 1000.0L;

    printf( "grootte = %d & getal = %.10f\n", sizeof( getal4bytes ), getal4bytes );
    printf( "grootte = %d & getal = %.10f\n", sizeof( getal8bytes ), getal8bytes );
    printf( "grootte = %d & getal = %.10Lf\n", sizeof( getal16bytes ), getal16bytes );
    return 0;
}
