#include <stdio.h>
#include <stdint.h>

// Fix it ! Zie https://upload.wikimedia.org/wikipedia/commons/2/28/LFSR-F16.svg
unsigned lfsr( uint16_t start_state )
{
    uint16_t lfsr = start_state;
    uint16_t bit = 0; /* Must be 16-bit to allow bit<<15 later in the code */

    /* taps: 16 14 13 11; feedback polynomial: x^16 + x^14 + x^13 + x^11 + 1 */
    bit = ( ( lfsr >> 0 ) ^ ( lfsr >> 2 ) ^ ( lfsr >> 3 ) ^ ( lfsr >> 5 ) ) & 1u;
    lfsr = ( lfsr >> 1 ) | ( bit << 15 );

    return lfsr;
}

int main( void )
{
    uint16_t random = 0xACE1u;       /* Any nonzero start state will work. */
    while( ( random % 20 ) + 1 > 1 ) // As long as not critial failed
    {
        random = lfsr( random );
        printf( "%5u    --> %2u\n", random, ( random % 20 ) + 1 );
    }
    return 0;
}
