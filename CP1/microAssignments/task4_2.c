/*
	FIX IT !
*/

#include <stdio.h>

int main( void )
{
    for( int rij=0; rij < 20; rij++ )
    {
        for( int kolom=0;  kolom < 15 ;kolom++)
        {
            printf( "%4d", rij * 15 + kolom );
        }
        printf( "\n" );
    }
    return 0;
}
