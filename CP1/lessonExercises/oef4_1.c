/*
  Schrijf een programma dat de volgende output genereerd:
  0  1
  1  2
  2  4
  3  8
  4  16
  5  32
  6  64
*/

#include <stdio.h>

int main( void )
{
	int exponent = 0;

	while( exponent <= 6 )
	{
		int macht = 1;
		// TODO : bereken de macht m.b.v. een for loop die de variabele macht vermenigvuldigd met 2 en dit exponent aantal keer. M.a.w. geen gebruik maken van math.h
    for (int i=0; i<exponent;i++ ) {
      macht *= 2;
    }
		printf( "%d %.0d\n", exponent, macht );
		exponent++;
	}
	return 0;
}
