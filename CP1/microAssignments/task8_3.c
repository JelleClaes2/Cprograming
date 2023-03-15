/*
  Fix it!
*/

#include <stdio.h>
#include <string.h>

int main( void )
{
    unsigned short m = 0;
    char maand[10];

    do
    {
        printf( "Geef het cijfer van een maand: " );
        (void)scanf( "%hu", &m );
    } while( m < 0 || m > 13 );



    switch( m )
    {
        case 1:
            strcpy( maand, "Januari" );
            break;
        case 2:
            strcpy( maand, "Februari" );
            break;
        case 3:
            strcpy( maand, "Maart" );
            break;
        case 4:
            strcpy( maand, "April" );
            break;
        case 5:
            strcpy( maand, "Mei" );
            break;
        case 6:
            strcpy( maand, "Juni" );
            break;
        case 7:
            strcpy( maand, "Juli" );
            break;
        case 8:
            strcpy( maand, "Augustus" );
            break;
        case 9:
            strcpy( maand, "September" );
            break;
        case 10:
            strcpy( maand, "Oktober" );
            break;
        case 11:
            strcpy( maand, "November" );
            break;
        case 12:
            strcpy( maand, "December" );
            break;
    }

    printf( "%s\n", maand );

    return 0;
}
