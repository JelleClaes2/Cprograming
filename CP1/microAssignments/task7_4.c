// Schrijf een C programma dat de het meest voorkomend character in de joke uitprint, en hoe vaak dit character voorkomt.
// HINT: De ASCII tabel bestaat uit 128 characters. Jullie weten ook wat een cumulatieve tabel is.
//
// Verwachte output:
// Het character 'x' is het meest voorkomende character, ze komt n keer voor.

#include <stdio.h>
#include <string.h>

#include "joke.h"

int main( void )
{
    int count[129]={0};
    int max=0;
    for(size_t i=0;i<strlen(joke);i++){
        count[(int)joke[i]]++;
    }
    for(int i=0;i<=128;i++){
        if(count[i]>count[max]){
            max=i;
        }
    }
    printf("Het character '%c' is het meest voorkomende character, ze komt %d keer voor.", max,count[max]);



    return 0;
}
