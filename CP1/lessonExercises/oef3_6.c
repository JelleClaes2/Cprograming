/*
  Maak een programma dat bepaalt of een jaar een schrikkeljaar is of niet. Print het resultaat uit. "Jaar x is een schrikkeljaar" of "Jaar x is geen schrikkeljaar".
*/

#include <stdio.h>

int main( void )
{
	int schrikkelJaar = 0;

	printf( "Geef een jaartal in: " );
	(void)scanf( "%d", &schrikkelJaar );

	if ((schrikkelJaar % 4) != 0)
	{
		printf( "Jaar %d is geen schrikkeljaar", schrikkelJaar );
	}
	else if ((schrikkelJaar % 100) != 0)
	{
		printf( "Jaar %d is een schrikkeljaar", schrikkelJaar );
	}
	else if ((schrikkelJaar % 400) != 0)
	{
		printf( "Jaar %d is geen schrikkeljaar", schrikkelJaar );
	}
	else
	{
		printf( "Jaar %d is een schrikkeljaar", schrikkelJaar );
	}

	return 0;
}
