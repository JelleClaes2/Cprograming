/*
  Zorg ervoor dat onderstaande code uitgevoerd kan worden waarbij de output gelijk is aan:
  
  Getal = 5
  Getal is kleiner dan of gelijk aan 5
  Het getal ligt tussen 0 en 10
  0.1 is gelijk aan 0.1
  5 is gelijk aan 5
*/

#include <stdio.h>
#include <stdint.h>

int main( void )
{
	int getal = 5;
	if( getal == 5 )
	{
		printf( "Getal = %d\n", getal );
	}

	if( getal > 10 )
  {
		printf( "Getal is groter dan 10\n" );
    getal -= 10;
    }
  	else if( getal > 5 )
  	{
	    printf( "Getal is groter dan 5\n" );
  	}
  	else
  	{
	    printf( "Getal is kleiner dan of gelijk aan 5\n" );
  	}

	if( (getal > 0) && (getal < 10) )
	{
		printf( "Het getal ligt tussen 0 en 10\n" );
	}

	float f = 0.1;
	double g = 0.1;
  if(f == (float)g)
  {
    printf("0.1 is gelijk aan 0.1\n");
  }
  else
  {
    printf("0.1 is niet gelijk aan 0.1\n");
  }

  int tweedeGetal = 4;
  if(getal == ++tweedeGetal)
  {
    printf("%d is gelijk aan %d\n", getal, tweedeGetal);
  }
  else
  {
    printf("%d is niet gelijk aan %d\n", getal, tweedeGetal);
  }
  
	return 0;
}
