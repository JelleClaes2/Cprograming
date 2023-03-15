/*
  Maak gebruik van de juiste arthimetic operator om te checken of het ingegeven getal een even of oneven getal is.
*/
#include <stdio.h>

int main( void )
{
	int getal = 0;
	int result = 0;

	printf( "Geef 1 geheel getal in: " );
	result = scanf( "%d", &getal );

	result = getal %2;

	if( result == 0 ) // test of het resultaat 0 is
	{
		printf( "Het getal is even." );
	}
	else
	{
		printf( "Het getal is oneven." );
	}

	return 0;
}
