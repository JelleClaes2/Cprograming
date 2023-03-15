#include <stdio.h>

int main( void )
{
    // Initialize an array of 5 elements by using an initializer list.
    // The values need to be 5, 2, 4, 8 en 1.
    int array[5]={5,2,4,8,1}; // Enkel op deze lijn aanpassingen aanbrengen!

    // Check if the initialization is succesful
    for( int i = 0; i < 5; i++ )
    {
        printf( "array[%d] = %d\n", i, array[i] );
    }

    return 0;
}
