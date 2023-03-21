#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("Geef een geheel-,komma-,complex getal");
    fgets(input,10,stdin);
    for(int i=0;i< strlen(input);i++){
        if(strcmp(input[i],'i')==0){
            //imaginair
        } else if(strcmp(input[i],'.')==0 || strcmp(input[i],',')==0){
            //kommagetal
        }else{
            //geheel
        }
    }
}
