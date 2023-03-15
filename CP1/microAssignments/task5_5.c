/*
  Roep de functie lfsr_fib() op binnen de for-loop waarbij de start_state gelijk wordt gesteld aan het getal dat wordt teruggegeven door de functie lfsr_fib();
  Geef de variabelen start_state, tap1, tap2, tap3 en tap4 mee aan de functie lfsr_fib.
*/

#include <stdio.h>
#include <stdint.h>

unsigned lfsr_fib( uint16_t start_state, uint8_t tap1, uint8_t tap2, uint8_t tap3, uint8_t tap4 );

int main( void )
{
    printf( "Hoeveel random getallen wil je hebben? " );

    uint8_t randomGetallen = 0;
    (void)scanf( "%hhu", &randomGetallen );

    printf( "Geef de taps die je wilt gebruiken voor de random getallen? " );

    uint8_t tap1 = 0;
    uint8_t tap2 = 0;
    uint8_t tap3 = 0;
    uint8_t tap4 = 0;
    (void)scanf( "%hhu %hhu %hhu %hhu", &tap1, &tap2, &tap3, &tap4 );

    uint16_t start_state = 0xACE1u;

    for( int i = 0; i < randomGetallen; i++ )
    {
        // Roep hier de functie lfsr_fib() op.
        start_state = lfsr_fib(start_state,tap1,tap2,tap3,tap4);
        printf( "%u\n", start_state );
    }

    return 0;
}

unsigned lfsr_fib( uint16_t start_state, uint8_t tap1, uint8_t tap2, uint8_t tap3, uint8_t tap4 )
{
    if( tap1 > 15 || tap2 > 15 || tap3 > 15 || tap4 > 15 )
    {
        printf( "Zorg ervoor dat de taps kleiner zijn dan 16.\n" );
        return 0;
    }

    uint16_t lfsr = start_state;
    uint16_t bit;

    bit = ( ( lfsr >> tap1 ) ^ ( lfsr >> tap2 ) ^ ( lfsr >> tap3 ) ^ ( lfsr >> tap4 ) ) & 1u;
    lfsr = ( lfsr >> 1 ) | ( bit << 15 );
    return lfsr;
}
