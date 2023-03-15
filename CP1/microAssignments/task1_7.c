/*
    Zorg ervoor dat de naamgevingen overal juist zijn, zodat de code hieronder kan compileren.
*/

#include <stdio.h>

#define DIT_IS_DE_VASTE_WAARDE 27

int main( void )
{
    unsigned short int eersteWaarde = DIT_IS_DE_VASTE_WAARDE;
    signed long int tweedeWaarde = DIT_IS_DE_VASTE_WAARDE;
    eersteWaarde = eersteWaarde + 15;
    tweedeWaarde = - eersteWaarde - tweedeWaarde;

    printf( "Het eerste getal = %d\nHet tweede getal = %d\n", eersteWaarde, tweedeWaarde );
    return 0;
}
