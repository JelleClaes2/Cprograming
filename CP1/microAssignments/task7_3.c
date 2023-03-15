// Hoe veel lower case character zitten er in de joke?
//
// HINT: https://en.cppreference.com/w/c/string/byte/islower
//
// Verwachte output:
// Er zitten n lowercase characters in de joke.

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#include "joke.h"

int main( void )
{
    int counter = 0;
    for( size_t i = 0; i < strlen( joke ); i++ )
    {
        if(islower(joke[i])!=0){
            counter++;
        }
    }

    printf("Er zitten %d lowercase characters in de joke.",counter);
    return 0;
}
