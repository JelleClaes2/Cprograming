/*
  De output van dit programma is 3.00. Voeg 4 haken toe en 1 type cast zodat de output 12.75 wordt.
*/
#include <stdio.h>

int main( void )
{
	int a = 6;
	int b = 9;
	int c = 12;
	int d = 17;
	float e = 0;
	
	e =  d % (b + c) * a / (float) (d - b);
	printf( "e = %.2f\n", e );

	return 0;
}
