/*
    Zorg ervoor dat "BADf00d" een hexadecimaal getal is om mee te geven en typecast het bij het printen naar een variabele met een grootte dat het "BAD" gedeelte niet zal bewaren.
*/

#include <stdio.h>

int main( void )
{
    int origineel = 0xBADf00d; //<-- zorg dat dit als hexadecimaal wordt onthouden

    printf( "De gewenste waarde = %hx\n", (short) origineel );
    return 0;
}
