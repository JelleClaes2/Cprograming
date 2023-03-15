/*
  Fix it !
  --------
    Er wordt een simulatie gemaakt van een heksenketel, echter is er iets mis dat het steeds faalt.
    HINT : Heksen fluisteren je "Moeten we nog wat accolades halen voor de soep ?"
*/

#include <stdio.h>

void printCauldron( float content, int size );
float takeSpoonsFromCauldron( float content, int numberOfSpoons );

int main( void )
{
    float cauldronContent;
    int cauldronSize;
    printf( "Hoe groot is de ketel ?" );
    (void)scanf( "%d", &cauldronSize );
    cauldronContent = cauldronSize;
    do
    {
        printCauldron( cauldronContent, cauldronSize );
        if( cauldronSize == 0 ){
            printf( "Ketel mag niet 0 zijn !\n" );
            return 1;
        }
        int amount;
        printf( "Hoeveel lepels haal je uit de ketel ?" );
        (void)scanf( "%d", &amount );
        cauldronContent = takeSpoonsFromCauldron( cauldronContent, amount );

    } while( cauldronContent > 0 );
    printf( "Je lepel is kapot !\n" );
    return 0;
}

void printCauldron( float content, int size )
{
    if( size < 0 ){
        printf( "Je ketel bestaat uit anti-materie !\n" );
        return;
    }
    printf( "De ketel is " );
    if( content / size < 0.1 ){
        printf( "leeg !\n" );
    }
    else if( content / size < 0.4 ){
        printf( "bijna leeg !\n" );
    }
    else if( content / size < 0.7 ){
        printf( "half vol !\n" );
    }
    else{
        printf( "vol !\n" );
    }
}

float takeSpoonsFromCauldron( float content, int numberOfSpoons )
{
    if( numberOfSpoons <= 0 ){
        return content;
    }
    return content - ( numberOfSpoons * 0.1 );
}
