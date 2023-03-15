/*
  Zorg dat het programma stopt na 10 pogingen of wanneer 21 werd ingegeven…
*/

#include <stdio.h>

int main( void )
{
	int n = 0;

	(void)scanf( "%d", &n );

	while( n != 21 )
	{
		for(int i=0;i<10;i++){
    printf( "U gaf getal: %d in\n", n );
		(void)scanf( "%d", &n );
    }
	}
	printf( "\n" );
	return 0;
}
