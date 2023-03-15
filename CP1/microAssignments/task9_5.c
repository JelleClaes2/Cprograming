#include <stdio.h>
#include <stdint.h>
#include <math.h>

// Create this !
uint32_t pow2( uint8_t exp )
{
    return pow(2,exp);
}

int main( void )
{
    uint8_t getal;
    printf( "Geef een positief geheel getal " );
    (void)scanf( "%hhu", &getal );
    printf( "2 tot de macht %hhu = %u\n", getal, pow2( getal ) );
    return 0;
}
