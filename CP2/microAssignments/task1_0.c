// Fix me !

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArrayWithRandom( int *array, int size );
void printArray( int *array, int size );
void sortArray( int *array, int size );
void sort( int *lhs, int *rhs );
void swap( int *lhs, int *rhs );

int main()
{
    int seed;
    (void)scanf( "%d", &seed );
    srand( seed ? seed : time( NULL ) );
    const int ARRAY_SIZE = 42;
    int array[ARRAY_SIZE];
    fillArrayWithRandom( array, ARRAY_SIZE  );
    printf( "\nVoor sort :\n" );
    printArray( array, ARRAY_SIZE  );
    sortArray( array, ARRAY_SIZE  );
    printf( "\nNa sort :\n" );
    printArray( array, ARRAY_SIZE  );
    return 0;
}

void fillArrayWithRandom( int *array, int size)
{
    for( int i = 0; i < size; i++ )
    {
        array[i] = rand() % 42096;
    }
}

void printArray( int *array, int size )
{
    for( int i = 0; i < size; i++ )
    {
        printf( "%5d\n", array[i] );
    }
}

void sortArray( int *array, int size )
{
    for( int max = size - 1; max > 0; max-- )
    {
        for( int i = 0; i < max; i++ )
        {
            sort( &array[i], &array[i + 1] );
        }
    }
}

void sort( int *lhs, int *rhs )
{
    if( *lhs > *rhs )
    {
        swap( lhs, rhs );
    }
}

void swap( int *lhs, int *rhs )
{
    int temp;
    temp = *lhs;
    *lhs = *rhs;
    *rhs = temp;
}
