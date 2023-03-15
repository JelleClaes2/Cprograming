#include <stdio.h>
#include <string.h>

int main( void )
{
    char input[150] = {0};
    // declare input
    printf( "Geef een woord : " );
    (void)scanf( "%s", input );
    printf( "Dit woord bevat %d characters.\n", strlen(input)/*string length of input*/ );
    return 0;
}
