#include <stdio.h>
#include <stdint.h>

// Fix it !
int main( void )
{
    uint64_t bigNumber = 0;
    bigNumber=( 1l << 42 );

    printf( "Getal = %lu\n", bigNumber );
    return 0;
}
