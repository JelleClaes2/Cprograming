#include <stdio.h>

int main( void )
{
    int teller = 0;
    int noemer = 0;

    printf( "Geef 2 gehele getallen in : " );
    (void)scanf( "%d %d", &teller, &noemer );

    /* test indien de noemer 0 is */
    if(noemer == 0){
        printf( "%d / %d = onbepaald \n", teller, noemer );
    }
        /* test indien het een kommagetal zou uitkomen. Hint : de restdeling is dan groter dan 0 */
    else if (teller % noemer > 0){
        printf( "%d / %d = %.4f \n", teller, noemer, (float)teller / noemer );
    }
        /* anders print zonder cijfers na de komma */
    else {
        printf( "%d / %d = %d \n", teller, noemer, teller / noemer );
    }
    return 0;
}
