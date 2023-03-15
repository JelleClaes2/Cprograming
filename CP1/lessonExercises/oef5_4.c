/*
  Maak het spel hoger lager waarbij een random geheel getal tussen 0 en 100 gegenereerd wordt en de gebruiker dit getal moet raden. Schrijf de game logic in een aparte functie genaamd hogerLagerSpel() die je oproept vanuit de main. Het return type van de functie
  hogerLagerSpel() dient een integer te zijn die aangeeft hoeveel pogingen nodig waren om het getal te raden.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int hogerLagerSpel(void);

int main(void){
  srand(time(NULL));
  int counter = hogerLagerSpel();
  printf("Je hebt %d gokken gedaan",counter);
}

int hogerLagerSpel(){
  int random =rand()%100;
  int gok = 0;
  int counter =0;
  do{
    printf("Doe een gok");
    (void)scanf("%d",&gok);
    counter ++;
    if(gok>random){
      printf("Lager\n");
    }
    else if(gok<random){
      printf("Hoger\n");
    }
    else{
      printf("Juist\n");
    }
  }
    while(gok!=random);
  return counter;
}
