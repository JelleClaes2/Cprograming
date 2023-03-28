#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)


struct date
{
    uint8_t dag : 5;
    uint8_t maand : 4;
    uint16_t jaar : 15;
};

struct record
{
    struct date datum;
    float waarde;
    struct record *next;
};

struct statistiek
{
    char *naam;
    char *eenheid;
    uint8_t aantal;
    struct record *lijst;
};
float gemiddeldeTemp (struct statistiek *data);
float somNeerslag (struct statistiek *neerslag);
void addValue (struct statistiek *data,float value);
void addValueWithDate(struct statistiek *data,float value,struct date datum);
struct statistiek* createStatistiek(char *naam,char *eenheid);
void cleanStatistiek(struct statistiek* data);

int main( void )
{
    struct date datum ={1,2,2023};

    struct statistiek* temperatuur = NULL;
    struct statistiek* neerslag =NULL;

    temperatuur = createStatistiek("Gemiddelde temperatuur","°C");
    neerslag = createStatistiek("Neerslag","mm");

    addValueWithDate(temperatuur,6.9,datum);


    // add all temp
    addValue(temperatuur,8.2);
    addValue(temperatuur,9.3);
    addValue(temperatuur,8.7);
    addValue(temperatuur,6.5);
    addValue(temperatuur,3.7);
    addValue(temperatuur,1.1);
    addValue(temperatuur,1.7);
    addValue(temperatuur,2.3);
    addValue(temperatuur,4);
    addValue(temperatuur,6.6);
    addValue(temperatuur,6.8);
    addValue(temperatuur,6.1);
    addValue(temperatuur,6.5);
    addValue(temperatuur,7.2);
    addValue(temperatuur,8.7);
    addValue(temperatuur,10.6);
    addValue(temperatuur,9.9);
    addValue(temperatuur,8.5);
    addValue(temperatuur,7);

    addValueWithDate(neerslag,0,datum);

    //add all neerslag
    addValue(neerslag,0.3);
    addValue(neerslag,0.3);
    addValue(neerslag,3.4);
    addValue(neerslag,0.8);
    addValue(neerslag,0);
    addValue(neerslag,0.03);
    addValue(neerslag,0);
    addValue(neerslag,0.13);
    addValue(neerslag,0);
    addValue(neerslag,0);
    addValue(neerslag,0);
    addValue(neerslag,0);
    addValue(neerslag,0);
    addValue(neerslag,0);
    addValue(neerslag,0.5);
    addValue(neerslag,0.4);
    addValue(neerslag,2.5);
    addValue(neerslag,0);
    addValue(neerslag,0);

    printf( "%lu %lu\n", sizeof( temperatuur->lijst[0].datum), sizeof(neerslag) );
    printf( "de gemiddelde temperatuur is %f \n", gemiddeldeTemp(temperatuur) );
    printf( "som van de neerslag is %f \n", somNeerslag(neerslag) );

    cleanStatistiek(temperatuur);
    cleanStatistiek(neerslag);
    return 0;
}
float gemiddeldeTemp (struct statistiek *data)
{
    int counter =0;
    float gemiddelde=0;
    struct record* pointer=data->lijst;
    while(pointer->next!=NULL){
        gemiddelde=gemiddelde+pointer->waarde;
        pointer = pointer->next;
        counter++;
    }
    gemiddelde=gemiddelde/counter;
    return gemiddelde;
}
float somNeerslag (struct statistiek *data)
{
    float som=0;
    struct record* pointer=data->lijst;
    while(pointer->next!=NULL){
        som=som+pointer->waarde;
        pointer = pointer->next;
    }
    return som;
}

void addValue(struct statistiek *data,float value){
    if(data->lijst == NULL){
        data->lijst=(struct record*)calloc(1,sizeof (struct record));
        data->lijst->waarde=value;
        data->lijst->datum.dag=8;//Aantal dagen == toe te voegen datum
        data->lijst->datum.maand=7;
        data->lijst->datum.jaar=2002;
    } else {
        struct record* pointer=data->lijst;
        while(pointer->next!=NULL){
            pointer = pointer->next;
        }
        pointer->next=(struct record*)calloc(1,sizeof (struct record));
        pointer->next->waarde=value;
        pointer->next->datum.dag=pointer->datum.dag +1;//Aantal dagen == toe te voegen datum
        pointer->next->datum.maand=pointer->datum.maand;
        pointer->next->datum.jaar=pointer->datum.jaar;
    }

}

void addValueWithDate(struct statistiek *data,float value,struct date datum){
    if(data->lijst == NULL){
        data->lijst=(struct record*)calloc(1,sizeof (struct record));
        data->lijst->waarde=value;
        data->lijst->datum.dag=datum.dag;//Aantal dagen == toe te voegen datum
        data->lijst->datum.maand=datum.maand;
        data->lijst->datum.jaar=datum.jaar;
    } else {
        struct record *pointer = data->lijst;
        while (pointer->next != NULL) {
            pointer = pointer->next;
        }
        pointer->next = (struct record *) realloc(data->lijst, (data->aantal + 1) * sizeof(struct record));
        pointer->next->waarde = value;
        pointer->next->datum.dag = datum.dag;//Aantal dagen == toe te voegen datum
        pointer->next->datum.maand = datum.maand;
        pointer->next->datum.jaar = datum.jaar;
    }
}

struct statistiek* createStatistiek(char *naam,char *eenheid){
    struct statistiek* data = (struct statistiek*)calloc(1,sizeof (struct statistiek));
    data->naam = (char *)calloc(strlen(naam)+1,sizeof (char));
    strcpy(data->naam,naam);
    data->eenheid = (char *)calloc(strlen(eenheid)+1,sizeof (char));
    strcpy(data->eenheid,eenheid);
    return data;
}

void cleanStatistiek(struct statistiek* data){
    free(data->lijst);
    free(data->eenheid);
    free(data->naam);
    free(data);
}
