/*
    Zorg ervoor dat "BADf00d" een hexadecimaal getal is om mee te geven en steek het in een variabele met een grootte dat het "BAD" gedeelte niet zal bewaren.
*/

#include <stdio.h>

int main( void )
{
    int origineel = 0xBADf00d; //<-- zorg dat dit als hexadecimaal wordt onthouden
    short getal = origineel; //<-- zorg voor een type dat de laatste 4 nibbles bijhoudt

    printf( "De originele waarde = %x\nDe gewenste waarde = %hx\n", origineel, getal );
    return 0;
}
