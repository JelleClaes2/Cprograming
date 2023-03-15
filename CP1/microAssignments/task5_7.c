/*
  Fix it !
  --------
    Er wordt gevraagt hoeveel spoken je kan zien, en die zullen je ook aanspreken.
    HINT : Casper fluistert je globaal "scoOoOoOope"...
*/

#include <stdio.h>

int ghosts = 0;
void listen( void );
int howManyGhosts( void );

int main( void )
{
    //int ghosts = 0;
    do
    {
        //int ghosts = 0;
        ghosts = howManyGhosts();
    } while( ghosts <= 0 );
    listen();
    return 0;
}

void listen( void )
{
    for( int i = 0; i < ghosts; i++ )
    {
        printf( "Boo !\n" );
    }
}

int howManyGhosts( void )
{
    int numberOfGhosts;
    printf( "Give number of ghosts : " );
    (void)scanf( "%d", &numberOfGhosts );
    return numberOfGhosts;
}
