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
void sum( struct getal a, struct getal b );

int main(void){
    printf("Getal 1:");
    struct getal a =vraagGetal();
    printf("Getal 2:");
    struct getal b =vraagGetal();
    sum(a,b);

}

struct getal vraagGetal(void){
    char input[10];//allocate ??
    printf("Geef een geheel-,komma-,complex getal:");
    fgets(input,10,stdin);

    char *newline = strchr(input, '\n');
    if (newline) {
        *newline = '\0';
    }


    if (strchr(input, 'i') != NULL) {
        struct complex *c = malloc(sizeof(struct complex));
        float re = 0, im = 0;
        int res = sscanf(input, "%f+i%f", &re, &im);
        if (res == 2) {
            c->reeel = re;
            c->imaginair = im;
            struct getal g = {COMPLEX, c};
            return g;
        }
    } else if (strchr(input, '.') != NULL || strchr(input, ',') != NULL) {
            float *f = malloc(sizeof(float));
            sscanf(input, "%f", f);
            struct getal g = {KOMMA, f};
            return g;
        }


    // Otherwise, assume it's an integer
    else {
        int *i = malloc(sizeof(int));
    sscanf(input, "%d", i);
    struct getal g = {GEHEEL, i};
    return g;
    }
}

void sum(struct getal a,struct getal b){
    {
        if (a.type == GEHEEL && b.type == GEHEEL) {
            int sum = *((int*)a.data) + *((int*)b.data);
            printf("De som is %d\n", sum);
        } else if (a.type == KOMMA && b.type == KOMMA) {
            float sum = *((float*)a.data) + *((float*)b.data);
            printf("De som is %f\n", sum);
        } else if (a.type == COMPLEX && b.type == COMPLEX) {
            struct complex* c1 = (struct complex*) a.data;
            struct complex* c2 = (struct complex*) b.data;
            float re = c1->reeel + c2->reeel;
            float im = c1->imaginair + c2->imaginair;
            printf("De som is %f + %fi\n", re, im);
        } else if(a.type == GEHEEL && b.type == KOMMA){
            float sum = *((int*)a.data) + *((float *)b.data);
            printf("De som is %f\n",sum);
        } else if(a.type == KOMMA && b.type == GEHEEL){
            float sum = *((float *)a.data) + *((int *)b.data);
            printf("De som is %f\n",sum);
        } else if(a.type == GEHEEL && b.type == COMPLEX){
            struct complex* c1 = (struct complex*) b.data;
            float re = *((int*)a.data) + c1->reeel;
            float im = c1->imaginair;
            printf("De som is %f + %fi",re,im);
        }else if(a.type == COMPLEX && b.type == GEHEEL){
            struct complex* c1 = (struct complex*) a.data;
            float re = *((int*)b.data) + c1->reeel;
            float im = c1->imaginair;
            printf("De som is %f + %fi",re,im);
        }else if(a.type == KOMMA && b.type == COMPLEX){
            struct complex* c1 = (struct complex*) b.data;
            float re = *((float *)a.data) + c1->reeel;
            float im = c1->imaginair;
            printf("De som is %f + %fi",re,im);
        }else if(a.type == COMPLEX && b.type == KOMMA){
            struct complex* c1 = (struct complex*) a.data;
            float re = *((float *)b.data) + c1->reeel;
            float im = c1->imaginair;
            printf("De som is %f + %fi",re,im);
        }
    }
}
