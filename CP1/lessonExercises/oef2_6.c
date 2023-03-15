/*
  Schrijf een programma dat de som, het product, het verschil en de deling van 2 reële getallen, die door de gebruiker worden ingegeven, berekent en de resultaten print. Maak deze keer gebruik van assignment operators waarbij het tussentijdse resultaat
  wordt opgeslagen in de variabele getal1.

  Voorbeeld:
  getal1 = 5.6
  getal2 = 4.3

    5.6 + 4.3 = 9.9
    9.9 * 4.3 = 42.57
  42.57 - 4.3 = 38.27
  38.27 / 4.3 = 8.9

*/
#include <stdio.h>

int main( void )
{
	double getal1 = 0;
	double getal2 = 0;
	int result = 0;

	printf( "Geef 2 reële getallen in: " );
	result = scanf( "%lf %lf", &getal1, &getal2 );
  getal1 += getal2;
	printf( "De som = %.2lf\n",getal1);
  getal1 *= getal2;
	printf( "Het product = %.2lf\n",getal1);
  getal1 -= getal2; 
	printf( "Het verschil = %.2lf\n", getal1);
  getal1 /= getal2;
	printf( "De deling = %.2lf\n", getal1);

	return 0;
}
