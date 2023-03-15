/*
  Schrijf een programma dat gevraagde stappen uitvoert zonder extra variabelen te voorzien. M.a.w. m.b.v. o.a. assignment operators
*/
#include <stdio.h>

int main( void )
{
    long long getal = 0;

    printf( "Geef 1 geheel getal in: " );
    (void) scanf( "%lld", &getal );

    getal += 5;//tel 5 bij het getal
    printf( "+5 = %lld\n", getal );
    getal *= 10;//vermenigvuldig met 10
    printf( "x10 = %lld\n", getal );
    getal %= 99;//maak een restdeling met 99
    printf( "modulo 99 = %lld\n", getal );
    ++getal;//incrementeer met 1
    printf( "++ = %lld\n", getal );
    getal /= 10;//deel door 10
    printf( "/10 = %lld\n", getal );
    getal -= 8;//verminder met 8
    printf( "-8 = %lld\n", getal );
    getal *= getal ;//vermenigvuldig met zichzelf
    printf( "^2 = %lld\n", getal );

    return 0;
}
