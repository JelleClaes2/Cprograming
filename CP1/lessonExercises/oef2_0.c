/*
  Zorg ervoor dat het getal 43 wordt geprint in plaats van het getal 42 door de increment operator (++) op de juiste positie te plaatsen.
*/
#include <stdio.h>

int main( void )
{
	int getal = 42;

	printf( "Getal = %d\n", ++getal ); // Voeg de increment operator toe bij de variabele getal.
	return 0;
}
