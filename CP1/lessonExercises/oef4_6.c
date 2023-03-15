/*
	Volgend programma moet 2 vierkanten tekenen, eentje van 40 op 60 gevuld met + tekens, en eentje van 60 op 40 gevuld met * tekens.
*/
#include <stdio.h>

int main( void )
{
	int i = 0;
  int j=0;
	for( i = 0; i < 40; i++ )
	{
		for( j = 0; j < 60; j++ )
		{
			printf( "+" );
		}
		printf( "\n" );
	}

	printf( "\n\n\n" );
	for( i = 0; i < 60; i++ )
	{
		for( j = 0; j < 40; j++ )
		{
			printf( "*" );
		}
		printf( "\n" );
	}
	return 0;
}
