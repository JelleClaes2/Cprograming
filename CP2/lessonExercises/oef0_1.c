#include <stdint.h>
#include <stdio.h>
#pragma pack(1)
struct statistiek
{
    char naam[64];
    char eenheid[8];
    uint8_t aantal;
    struct
    {
        struct
        {
            uint8_t dag : 5;
            uint8_t maand : 4;
            uint16_t jaar : 15;
        } datum;
        float waarde;
    } lijst[31];
};
float gemiddeldeTemp (struct statistiek *data);
float somNeerslag (struct statistiek *neerslag);
void addValue (struct statistiek *data,float value);

int main( void )
{
    struct statistiek temperatuur = { "Gemiddeld temperatuur",
                                      "°C",
                                      20,
                                      {
                                              { { 20, 2, 2023 }, 7 },
                                              { { 19, 2, 2023 }, 8.5 },
                                              { { 18, 2, 2023 }, 9.9 },
                                              { { 17, 2, 2023 }, 10.6 },
                                              { { 16, 2, 2023 }, 8.7 },
                                              { { 15, 2, 2023 }, 7.2 },
                                              { { 14, 2, 2023 }, 6.5 },
                                              { { 13, 2, 2023 }, 6.1 },
                                              { { 12, 2, 2023 }, 6.8 },
                                              { { 11, 2, 2023 }, 6.6 },
                                              { { 10, 2, 2023 }, 4 },
                                              { { 9, 2, 2023 }, 2.3 },
                                              { { 8, 2, 2023 }, 1.7 },
                                              { { 7, 2, 2023 }, 1.1 },
                                              { { 6, 2, 2023 }, 3.7 },
                                              { { 5, 2, 2023 }, 6.5 },
                                              { { 4, 2, 2023 }, 8.7 },
                                              { { 3, 2, 2023 }, 9.3 },
                                              { { 2, 2, 2023 }, 8.2 },
                                              { { 1, 2, 2023 }, 6.9 }
                                      }
    };
    struct statistiek neerslag = { "Neerslag",
                                   "mm",
                                   20,
                                   {
                                           { { 20, 2, 2023 }, 0 },
                                           { { 19, 2, 2023 }, 0 },
                                           { { 18, 2, 2023 }, 2.5 },
                                           { { 17, 2, 2023 }, 0.4 },
                                           { { 16, 2, 2023 }, 0.5 },
                                           { { 15, 2, 2023 }, 0 },
                                           { { 14, 2, 2023 }, 0 },
                                           { { 13, 2, 2023 }, 0 },
                                           { { 12, 2, 2023 }, 0 },
                                           { { 11, 2, 2023 }, 0 },
                                           { { 10, 2, 2023 }, 0 },
                                           { { 9, 2, 2023 }, 0.13 },
                                           { { 8, 2, 2023 }, 0 },
                                           { { 7, 2, 2023 }, 0.03 },
                                           { { 6, 2, 2023 }, 0 },
                                           { { 5, 2, 2023 }, 0.8 },
                                           { { 4, 2, 2023 }, 3.4 },
                                           { { 3, 2, 2023 }, 0.3 },
                                           { { 2, 2, 2023 }, 0.3 },
                                           { { 1, 2, 2023 }, 0 } }
    };
    addValue(&temperatuur,5.0);
    addValue(&neerslag,0);
    printf( "%lu %lu\n", sizeof( temperatuur.lijst[0].datum), sizeof(neerslag) );
    printf( "de gemiddelde temperatuur is %f \n", gemiddeldeTemp(&temperatuur) );
    printf( "som van de neerslag is %f \n", somNeerslag(&neerslag) );
    return 0;
}
float gemiddeldeTemp (struct statistiek *data)
{
    float gemiddelde=0;
    for(int x=0;x<data->aantal;x++)
    {
        gemiddelde=gemiddelde+data->lijst[x].waarde;
    }
    gemiddelde=gemiddelde/data->aantal;
    return gemiddelde;
}
float somNeerslag (struct statistiek *neerslag)
{
    float som=0;
    for(int x=0;x<neerslag->aantal;x++)
    {
        som=som+neerslag->lijst[x].waarde;
    }
    return som;
}

void addValue(struct statistiek *data,float value){
    data->aantal ++;
    data->lijst[data->aantal].waarde=value;
    data->lijst[data->aantal].datum.dag=data->aantal;//Aantal dagen == toe te voegen datum
    data->lijst[data->aantal].datum.maand=data->lijst[0].datum.maand;
    data->lijst[data->aantal].datum.jaar=data->lijst[0].datum.jaar;
}
