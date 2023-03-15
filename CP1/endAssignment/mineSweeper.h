
#include <stdint.h>

void startSpel(void);
void bommenVeldAanmaken(uint8_t aantalBommen);
void spelLaden(void);
void showSpeelveld(void);
void showBommenveld(void);
uint8_t speelCoordinaatVrijOfBewaar(void);
void floodFill(int8_t rij,int8_t kolom);
uint8_t berekenAantalBommen(int8_t rij,int8_t kolom);
float berekeningVoortgangsPercentage(void);
void bewaar(void);

