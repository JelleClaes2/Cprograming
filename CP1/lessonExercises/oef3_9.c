/*
 * Zorg dat volgend programma succesvol compiled. Je mag enkel de operators aanpassen (==, !=, >, <, >=, <=, &&, ||, !).
 */

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main( void )
{
	uint8_t A = 4;
	uint8_t B = 2;

	assert( A != B );
	assert( A == ( B + B ) );
	assert( ( A != B ) && ( A == A ) );
	assert( ( A != B ) || ( A == A ) );
	assert( B < A );
	assert( A > B );
	assert( A < ( B + A ) ? 1 : 0 );
	assert( A < B ? 0 : A < B ? 0 : A < B ? 0 : 1 );
	assert( ( 1 || 0 ) );
	assert( ( 1 && 1 ) );
	assert( 1 );

	printf( "1\n" );

	return EXIT_SUCCESS;
}
