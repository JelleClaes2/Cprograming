#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

char fullOptionToShort( char *fullOption );
void printUsage( char *programName );

int main( int argc, char *argv[] )
{
    srand( time( NULL ) );
    int min = 0;
    int max = 100;
    uint16_t tries = 100;
    uint8_t evil = 0;
    if( argc == 1 )
    {
        printUsage( argv[0] );
    }
    for( int i = 1; i < argc; i++ )
    {
        if( argv[i][0] == '-' )
        {
            char option = ( argv[i][1] == '-' ) ? fullOptionToShort( &argv[i][2] ) : argv[i][1];
            switch( option )
            {
                case 't':
                case 'T':
                    if( i == argc )
                    {
                        printf( "Missing value for %s.", argv[i] );
                        return 1;
                    }
                    tries = atoi( argv[i+1] );
                    i++;
                    break;
                case 'm':
                    if( i == argc )
                    {
                        printf( "Missing value for %s.", argv[i] );
                        return 1;
                    }
                    min = atoi( argv[i+1] );
                    i++;
                    break;
                case 'M':
                    if( i == argc )
                    {
                        printf( "Missing value for %s.", argv[i] );
                        return 1;
                    }
                    max = atoi( argv[i+1] );
                    i++;
                    break;
                case 's':
                case 'S':
                    if( i == argc )
                    {
                        printf( "Missing value for %s.", argv[i] );
                        return 1;
                    }
                    srand( atoi( argv[i+1] ) );
                    i++;
                    break;
                case 'e':
                case 'E':
                    evil = 1;
                    break;
                case 'v':
                case 'V':
                    printf( "Version 0.0.1\n" );
                    return 0;
                case 'h':
                case 'H':
                case '?':
                    printUsage( argv[0] );
                    return 0;
                default:
                    printf( "Invalid option %s.\n", argv[i] );
                    return 1;
            }
        }
        else
        {
            int random = ( rand() % ( max - min + 1 ) ) + min;
            uint16_t count = 1;
            int guess = 0;
            printf( "Welcome %s you can start guessing your number.\n", argv[i] );
            while( count <= tries )
            {
                printf( "Guess %d = ", count );
                (void)scanf( "%d", &guess );
                if( ( evil == 1 ) && ( ( rand() % 4 ) == 0 ) )
                {
                    switch( rand() % 11 )
                    {
                        case 0:
                        case 1:
                        case 2:
                            printf( "Lower\n" );
                            break;
                        case 3:
                        case 4:
                        case 5:
                            printf( "Higher\n" );
                            break;
                        case 6:
                        case 7:
                            printf( "\n" );
                            break;
                        case 8:
                        case 9:
                            printf( "POTATO !!!\n" );
                            break;
                        case 10:
                            printf( "Correct in 100000000 guesses ! Pathetic loser... No, you failed\n" );
                            break;
                    }
                }
                else if( guess > random )
                {
                    printf( "Lower\n" );
                }
                else if( guess < random )
                {
                    printf( "Higher\n" );
                }
                else
                {
                    printf( "Correct in %d guesses !\n", count );
                    break;
                }
                count++;
            }
            if( count > tries )
            {
                printf( "Reached the maximum allowed tries, the correct value was %d...\n", random );
            }
        }
    }
}

char fullOptionToShort( char *fullOption )
{
    if( strcasecmp( "evil", fullOption ) == 0 )
        return 'e';
    if( strcasecmp( "seed", fullOption ) == 0 )
        return 's';
    if( strcasecmp( "tries", fullOption ) == 0 )
        return 't';
    if( strcasecmp( "min", fullOption ) == 0 )
        return 'm';
    if( strcasecmp( "max", fullOption ) == 0 )
        return 'M';
    if( strcasecmp( "version", fullOption ) == 0 )
        return 'v';
    if( strcasecmp( "help", fullOption ) == 0 )
        return 'h';
    return '\0';
}

void printUsage( char *programName )
{
    printf( "Usage : %s [options] player1 player2...\n"
            "Options:\n"
            "  -m --min <number>      Lowest number that can be picked. Default = 0\n"
            "  -M --max <number>      Highest number that can be picked. Default = 100\n"
            "  -t --tries <number>    Number of tries to guess the correct number. Default = 100\n"
            "  -s --seed <number>     Print this help menu. Default = random\n"
            "  -e --evil              Play in evil mode.\n"
            "  -v --version           Print current version.\n"
            "  -h --help              Print this help menu.\n",
            programName );
}
