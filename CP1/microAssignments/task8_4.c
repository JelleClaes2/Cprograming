/*
  Maak een switch case met joined cases om de graad van onderscheiding te bepalen.
  10-12: Voldoende
  13-14: Onderscheiding
  15-16: Grote onderscheiding
  17-20: Grootste onderscheiding
*/

#include <stdio.h>

int main( void )
{
    unsigned short cijfer = 0;

    do
    {
        printf( "Geef een cijfer in van 10 tot 20 om de graad van onderscheiding te bepalen: " );
        (void)scanf( "%hu", &cijfer );
    } while( cijfer < 10 || cijfer > 20 );

    switch( cijfer )
    {
        case 10:
        case 11:
        case 12:
            printf("Voldoende\n");
            break;
        case 13:
        case 14:
            printf("Onderscheiding\n");
            break;
        case 15:
        case 16:
            printf("Grote onderscheiding\n");
            break;
        case 17:
        case 18:
        case 19:
        case 20:
            printf("Grootste onderscheiding\n");
            break;
    }

    return 0;
}
