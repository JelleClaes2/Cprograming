#include <stdio.h>

int main( void )
{
    /* Gebruik een initializer list om de 2D array als volgt te initializeren:
     1 2 3
     4 5 6
     7 8 9
  */
    int array[3][3] ={{1,2,3},{4,5,6},{7,8,9}}; // Enkel op deze lijn aanpassingen aanbrengen!

    for( int i = 0; i < 3; i++ )
    {
        for( int j = 0; j < 3; j++ )
        {
            printf( "%d\t", array[i][j] );
        }
        printf( "\n" );
    }

    return 0;
}
