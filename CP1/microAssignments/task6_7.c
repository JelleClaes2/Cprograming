#include <stdio.h>

#define SIZE 100

int main( void )
{
    // Fix it! -> Hint: index?
    int array[SIZE + 1];

    for( int i = 0; i <= SIZE; i++ )
    {
        array[i] = ( SIZE - i ) * i;
        printf( "array[%d] = %d\n", i, array[i] );
    }

    return 0;
}
