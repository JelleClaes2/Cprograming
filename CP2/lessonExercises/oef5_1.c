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

float gemiddeldeTemp(struct statistiek *data);
float somNeerslag(struct statistiek *neerslag);
void addValue(struct statistiek *data, float value, const char *logbestand);
void addValueWithDate(struct statistiek *data, float value, struct date datum, const char *logbestand);
struct statistiek *createStatistiek(char *naam, char *eenheid);
void cleanStatistiek(struct statistiek *data);

int main(int argc, char *argv[])
{
    struct date datum = {1, 2, 2023};

    struct statistiek *temperatuur = NULL;
    struct statistiek *neerslag = NULL;
    struct statistiek *huidigeData = NULL;

    temperatuur = createStatistiek("Gemiddelde temperatuur", "°C");
    neerslag = createStatistiek("Neerslag", "mm");

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'd')
            {
                char *stringdatum = strtok(argv[i + 1], "-");
                char *dag = stringdatum;
                datum.dag = atoi(dag);
                int count = 1;
                while (stringdatum)
                {
                    stringdatum = strtok(NULL, "-");
                    if (count == 1)
                    {
                        char *maand = stringdatum;
                        datum.maand = atoi(maand);
                    }
                    else if (count == 2)
                    {
                        char *jaar = stringdatum;
                        datum.jaar = atoi(jaar);
                    }
                    count++;
                }
                addValueWithDate(temperatuur, 6.9, datum, "temperatuur.log");
                addValueWithDate(neerslag, 0, datum, "neerslag.log");
                i++;
            }
            else if (argv[i][1] == 'T')
            {
                huidigeData = temperatuur;
            }
            else if (argv[i][1] == 'N')
            {
                huidigeData = neerslag;
            }
        }
        else
        {
            addValue(huidigeData, atof(argv[i]), "neerslag.log");
        }
    }

    printf("%lu %lu\n", sizeof(temperatuur->lijst[0].datum), sizeof(neerslag));
    printf("de gemiddelde temperatuur is %f \n", gemiddeldeTemp(temperatuur));
    printf("som van de neerslag is %f \n", somNeerslag(neerslag));

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

void addValue(struct statistiek *data, float value, const char *logbestand)
{
    FILE *file = fopen(logbestand, "a");
    if (file == NULL)
    {
        printf("Fout bij het openen van het logbestand.\n");
        return;
    }

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

    fprintf(file, "%f\n", value);
    fclose(file);
}

void addValueWithDate(struct statistiek *data, float value, struct date datum, const char *logbestand)
{
    FILE *file = fopen(logbestand, "a");
    if (file == NULL)
    {
        printf("Fout bij het openen van het logbestand.\n");
        return;
    }

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

    fprintf(file, "%d-%d-%d %f\n", datum.dag, datum.maand, datum.jaar, value);
    fclose(file);
    addValue(data, value, logbestand);
}

struct statistiek *createStatistiek(char *naam, char *eenheid)
{
    struct statistiek *data = (struct statistiek *)calloc(1, sizeof(struct statistiek));
    data->naam = (char *)calloc(strlen(naam) + 1, sizeof(char));
    strcpy(data->naam, naam);
    data->eenheid = (char *)calloc(strlen(eenheid) + 1, sizeof(char));
    strcpy(data->eenheid, eenheid);
    return data;
}

void cleanStatistiek(struct statistiek *data)
{
    free(data->lijst);
    free(data->eenheid);
    free(data->naam);
    free(data);
}
