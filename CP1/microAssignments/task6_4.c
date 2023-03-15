#include <stdio.h>
#include <assert.h>

#define SIZE 100

int main( void )
{
    // Maak een array met SIZE aantal kommagetallen die oplopen van 0.00 in stappen van 0.01

    float array[SIZE];
    for(int i=0;i<SIZE;i++){
        array[i]= (float)i/100;
    }
    assert( array[0] == 0.00f );
    assert( array[8] == 0.08f );
    assert( array[42] == 0.42f );
    assert( array[69] == 0.69f );
    assert( array[99] == 0.99f );

    for(int i=0; i<SIZE;i++){
        printf("array[%d] = %.2f\n",i,array[i]);
    }
    return 0;
}
