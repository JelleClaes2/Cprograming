/*
  Schrijf een programma dat de volgende berekeningen uitvoert op de meegegeven variabelen en gebruik maakt van 1 grote expressie, dus op 1 lijn. Je mag maar 18 lijnen code hebben !
Het getal bekom je door alfa met beta te vermenigvuldigen, daar gamma bij te tellen, het geheel te delen door delta. Gebruik dat voor een modulo/rest operatie met het verschil van delta min gamma.
*/
#include <stdio.h>

int main( void )
{
    int alfa, beta, gamma, delta;
    int getal = 0;
    printf( "Geef 4 gehele getallen in: " );
    (void)scanf( "%d %d %d %d", &alfa, &beta, &gamma, &delta );
    // Voeg volgende lijnen samen zodat dit 1 expressie wordt !
    getal = (((alfa * beta) + gamma) / delta) % (delta - gamma);
    // -------------------------------------------------------
    printf( "Getal = %d\n", getal );
    return 0;
}
