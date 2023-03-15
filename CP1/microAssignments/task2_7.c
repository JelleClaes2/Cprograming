/*
  De output van dit programma is -153. Verwijder 4 haken zodat de output -9 wordt.
*/
#include <stdio.h>

int main( void )
{
    int a = 6;
    int b = 9;
    int c = 12;
    int d = 17;
    int e = 0;

    e = (d % (b + c)) * (a / d) - b;
    printf( "e = %d\n", e );

    return 0;
}
