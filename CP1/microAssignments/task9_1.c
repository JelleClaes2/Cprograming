#include <stdio.h>
#include <stdint.h>

// Create this !
uint8_t setBitOff( uint8_t data, uint8_t bit )
{
    return data & ~(1<<bit);
}

int main( void )
{
    uint8_t getal;
    uint8_t bit;
    printf( "Geef een positief geheel getal " );
    (void)scanf( "%hhu", &getal );
    printf( "Zeg welke bit uit moet " );
    (void)scanf( "%hhu", &bit );
    printf( "Het resultaat is %hhu\n", setBitOff( getal, bit ) );
    return 0;
}
