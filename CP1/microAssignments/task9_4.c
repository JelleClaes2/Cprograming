#include <stdio.h>
#include <stdint.h>

// Create this !
uint8_t countBits( uint8_t data )
{
    int count=0;
    for (int i = 0; (unsigned long)i < sizeof(int) * 8; i++) {
        int bit = (data & (1 << i)) >> i;
        if (bit == 1) {
            count++;
        }
    }
    return count;
}

int main( void )
{
    uint8_t getal;
    printf( "Geef een positief geheel getal " );
    (void)scanf( "%hhu", &getal );
    printf( "Het getal bevat %hhu bits\n", countBits( getal ) );
    return 0;
}
