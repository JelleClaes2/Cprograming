#include <stdio.h>
#include <assert.h>

int main( void )
{
    // Maak een array met 42 getallen die allemaal 0 zijn
    int array[42]={0};
    assert( array[0] == 0 );
    assert( array[8] == 0 );
    assert( array[16] == 0 );
    assert( array[32] == 0 );
    for (int i=0;i<42;i++){
        printf("array[%d] = %d\n",i,array[i]);
    }
    return 0;
}
