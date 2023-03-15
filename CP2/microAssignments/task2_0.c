// Fix me !

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void *createArray( int size, int bytes );

// Er wordt steeds de machten van 2 geprint (== bit shift)
// bij een overflow laten we steeds opnieuw beginnen en dat printen we ook voor enkele cijfers
int main( void )
{
    uint8_t *reeks1bytes = (uint8_t *)createArray( 10, sizeof( uint8_t ) );
    printf( "Reeks van 1 bytes\n" );
    for( int i = 0; i < 10; i++ )
    {
        printf( "%20hhu\n", reeks1bytes[i] );
    }
    uint16_t *reeks2bytes = (uint16_t *)createArray( 20, sizeof( uint16_t ) );
    printf( "Reeks van 2 bytes\n" );
    for( int i = 0; i < 20; i++ )
    {
        printf( "%20hu\n", reeks2bytes[i] );
    }
    uint32_t *reeks4bytes = (uint32_t *)createArray( 40, sizeof( uint32_t ) );
    printf( "Reeks van 4 bytes\n" );
    for( int i = 0; i < 40; i++ )
    {
        printf( "%20u\n", reeks4bytes[i] );
    }
    uint64_t *reeks8bytes = (uint64_t *)createArray( 80, sizeof( uint64_t ) );
    printf( "Reeks van 8 bytes\n" );
    for( int i = 0; i < 80; i++ )
    {
        printf( "%20lu\n", reeks8bytes[i] );
    }
    return 0;
}

// Fout zit enkel in deze functie !
void *createArray( int size, int bytes )
{
    void *array = malloc( size*bytes );
    switch( bytes )
    {
        case 1:
            for( int i = 0; i < size; i++ )
            {
                ( (uint8_t *)array )[i] = ( (uint8_t)1 ) << ( i % 8 );
            }
            break;
        case 2:
            for( int i = 0; i < size; i++ )
            {
                ( (uint16_t *)array )[i] = ( (uint16_t)1 ) << ( i % 16 );
            }
            break;
        case 4:
            for( int i = 0; i < size; i++ )
            {
                ( (uint32_t *)array )[i] = ( (uint32_t)1 ) << ( i % 32 );
            }
            break;
        case 8:
            for( int i = 0; i < size; i++ )
            {
                ( (uint64_t *)array )[i] = ( (uint64_t)1 ) << ( i % 64 );
            }
            break;
    }
    return array;
}
