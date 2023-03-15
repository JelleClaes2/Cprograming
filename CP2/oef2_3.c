#include <stdio.h>
#include <stdlib.h>

struct complex
{
    float reeel;
    float imaginair;
};
struct getal
{
    enum
    {
        GEHEEL,
        KOMMA,
        COMPLEX
    } type;
    void *data;
};

struct getal vraagGetal( void );
void som( struct getal a, struct getal b );

int main(void){

}

struct getal vraagGetal(void){
    char input[10];//allocate ??
    printf("Geef een geheel-,komma-,compex getal");
    fgets(input,10,stdin);

}
