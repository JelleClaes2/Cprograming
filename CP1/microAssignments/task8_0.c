/*
Herschijf onderstaand programma zodat er gebruik gemaakt wordt van een switch case i.p.v. een IF ELSE structuur.
*/

#include <stdio.h>

int main( void )
{
    char str[50];
    char kleur = 'w';

    printf( "Geef een zin: " );
    (void)fgets( str, 50, stdin );

    printf( "In welke kleur dient deze tekst afgedrukt te worden? [Rood (r), Groen (g), Oranje (o), Blauw (b), Magenta (m) of Cyaan (c)] " );
    kleur = getc( stdin );
    switch(kleur){
        case 'r':
            printf( "\033[91m%s\033[0m", str );
            break;
        case 'g':
            printf( "\033[92m%s\033[0m", str );
            break;
        case 'o':
            printf( "\033[93m%s\033[0m", str );
            break;
        case 'b':
            printf( "\033[94m%s\033[0m", str );
            break;
        case 'm':
            printf( "\033[95m%s\033[0m", str );
            break;
        case 'c':
            printf( "\033[96m%s\033[0m", str );
            break;
        default:
            printf( "De kleur %c is geen geldige input!\n", kleur );

            return 0;
    }
}
