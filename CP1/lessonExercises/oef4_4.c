/*
  Schrijf met behulp van een for-loop een programma dat enkel de oneven getallen tussen 1 en 10 afprint door gebruik te maken van het continue statement.
*/

#include <stdio.h>

int main( void )
{
	for( int i = 1; i <= 10; i++ )
	{
		if(i%2!=0){
      printf( "%d\n\n", i );
      continue;
    }
	}
	return 0;
}
