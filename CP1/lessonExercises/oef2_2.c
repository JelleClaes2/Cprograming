/*
  Schrijf een programma dat de som, het verschil, het product en de deling van 2 reële getallen, die door de gebruiker worden ingegeven, berekent en de resultaten print.
*/
#include <stdio.h>

int main( void )
{
	double getal1 = 0;
	double getal2 = 0;
	int result = 0;

	printf( "Geef 2 reële getallen in: " );
	result = scanf( "%lf %lf", &getal1, &getal2 );

	printf( "%.1lf + %.1lf = %.1lf\n", getal1, getal2, getal1+getal2);
	printf( "%.1lf - %.1lf = %.1lf\n", getal1, getal2, getal1-getal2 );
	printf( "%.1lf * %.1lf = %.1lf\n", getal1, getal2, getal1*getal2);
	printf( "%.1lf / %.1lf = %.1lf\n", getal1, getal2, getal1/getal2 );

	return 0;
}
