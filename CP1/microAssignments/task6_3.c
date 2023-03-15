#include <stdio.h>

#define SIZE 1000

int main( void )
{
    // Zorg ervoor dat er 1000 elementen worden afgeprint
    int array[SIZE];

    for( int i = 0; i < SIZE; i++ )
    {
        array[i] = 2 * i;
        printf( "array[%d] = %d\n", i, array[i] );
    }

    return 0;
}
