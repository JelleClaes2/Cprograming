// # MIN MAX
//
// We hebben een array met een heleboel random nummers. Probeer nu het
// minimum en maximum te vinden binnen deze array. De array wordt
// geïnitialiseerd door de gebruiker. Zorg er dus voor dat de gebruiker
// een geheel getal kan meegeven om als seed te gebruiken.
//
//
// ## Verwachte output
//
// We verwachten een output die lijkt op het volgende. Opnieuw, let op de
// formatting!
//
// ```
// Min = 78411
// Max = 4737035758047
// ```

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define SIZE 1024

int main( void )
{
    uint64_t array[SIZE];
    int seed;
    printf( "Geef een geheel getal als seed : \n" );
    (void)scanf( "%d", &seed );
    srand( seed );
    for( int i = 0; i < SIZE; i++ )
    {
        array[i] = (uint64_t)rand() * rand() / rand();
    }

    // Vind het min en max in de array
    //---
    // HINT : Your code here !
    //---
    uint64_t j=0;
    for( int i = 0; i < SIZE; i++ )
    {
        if((array[i]) > j)
        {
            j=array[i];
        }
    }

    uint64_t k=array[0];
    for( int i = 0; i < SIZE; i++ )
    {
        if((array[i]) < k)
        {
            k=array[i];
        }
    }
    printf("Min = %lu\n",k);
    printf("Max = %lu",j);


    return 0;
}
