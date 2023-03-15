/*
    Print alle gehele getallen tussen de start en de stop die de gebruiker opgeeft. Indien de start kleiner is dan de stop, moeten ze aflopen i.p.v. oplopen.
*/

#include <stdio.h>
#include <stdint.h>

int main( void )
{
    int8_t start = 0;
    int8_t stop = 0;

    printf( "Geef twee gehelen getal (tussen -100 en 100) : " );
    (void)scanf( "%hhd %hhd", &start, &stop );
    printf( "---------------------------------------------------\n" );
    if(start<stop){
        for(int i=start;i<=stop;i++){
            printf("%d\n",i);
        }
    } else{
        for(int i=start;i>=stop;i--){
            printf("%d\n",i);
        }
    }

    return 0;
}
