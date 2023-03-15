#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "mineSweeper.h"

// vullen van het bommenveld met nullen(geen bommen)
uint8_t bommenveld[8][8]={0};

// vul het speelveld met de ascii waarden van #
uint8_t speelveld[8][8]={{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35},{35,35,35,35,35,35,35,35}};

void startSpel(void){

  // De gebruiker wordt welkom genoemd en gevraagd of hij een spel wilt laden of hoeveel bommen hij wilt in zijn spel
  
  char naam[20];
  char ladenOfAantalBommen[6];
  uint8_t aantalBommen=0;

  printf("Wat is je naam: ");
  fgets(naam,20,stdin);
  naam[strlen(naam)-1]='\0';// \n verwijderen
  printf("\n");
  printf("Welkom %s hoeveel bommen wilt u in het spel of wilt u een spel laden: ",naam);
  fgets(ladenOfAantalBommen,6,stdin);
  printf("\n");
  
  // door elke letter van de ingegeven string gaan en deze waar nodig naar een lower case veranderen
  for(int i=0;i<strlen(ladenOfAantalBommen);i++){ 
    if(isupper(ladenOfAantalBommen[i])==0){
      ladenOfAantalBommen[i]=tolower(ladenOfAantalBommen[i]);
    }
  }
  
  if(strcmp(ladenOfAantalBommen,"laden")==0){ // de functie laden oproepen als er laden wordt ingegeven
    spelLaden(); 
  } else {
    aantalBommen = atoi(ladenOfAantalBommen);// string naar een int veranderen en het bommenveld aanmaken
    
    while(aantalBommen>63){
      printf("%s er mogen niet meer bommen in het spel zitten als 63. Hoeveel bommen wilt u in het spel? ",naam);
      (void)scanf("%d",&aantalBommen);
    }
    
    bommenVeldAanmaken(aantalBommen);
  }
}

void bommenVeldAanmaken(uint8_t aantalBommen){

  // Het bommenveld wordt random gevuld met het aantal gevraagde bommen
  uint8_t xAs=0;
  uint8_t yAs=0;
  uint8_t count=0;

  //zolang er niet genoeg bommen in het veld staan worden er nieuwe bommen toegevoegd
  while(count!=aantalBommen){
    xAs = rand()%8; // maak een random getal tss 0 en 7
    yAs = rand()%8; // maak een random getal tss 0 en 7
    
    //plaatsen van de bommen op de random plaatsen
    if(bommenveld[xAs][yAs] == 0){ //checken of er al een bom staat op deze "random" plek
      bommenveld[xAs][yAs] = 1; //1 zetten op de random plek zodat hier een bom staat
      count++; // tellen hoeveel bommen er al geplaatst zijn
    }
  }
}

void spelLaden(void){ 

  // Een voorgaand spel wordt geladen aan de hand van 2 hexadecimalen getallen
  uint64_t vrijgespeeldeVelden=0;
  uint64_t positieBommen=0;
  uint8_t positieBitBom = 63;
  unsigned long long maskBom;
  uint8_t bitBom=0;
  uint8_t positieBitVeld = 63;
  unsigned long long maskVeld;
  uint8_t bitVeld=0;
  
  while(getchar()!='\n');// de stdin leeg halen

  //inlezen van de 2 hexadecimalen getallen
  printf("Geef het getal voor het vrijgespeelde veld: ");
  (void)scanf("%lx",&vrijgespeeldeVelden);
  printf("\n");
  printf("Geef het getal voor de positie van de bommen: ");
  while(getchar()!='\n');
  (void)scanf("%lx",&positieBommen);

  //de juiste bit uit het 64 bit getal halen en deze in het bommenveld steken
  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      maskBom = 1ULL<<positieBitBom; // mask met een 1 op de gewilde positie
      bitBom=(positieBommen & maskBom)>>positieBitBom; //de gewilde bit uit het getal halen
      positieBitBom --;
      bommenveld[i][j]=bitBom;// bit in de array steken
    }
  }

  //de juiste bit uit het 64 bit getal halen en het aantal bommen in het speelveld steken waar nodig
  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      maskVeld = 1ULL<<positieBitVeld;// mask met een 1 op de gewilde positie
      bitVeld=(vrijgespeeldeVelden & maskVeld)>>positieBitVeld;//de gewilde bit uit het getal halen
      positieBitVeld --;

      if(bitVeld==1){ // als bit gelijk is aan 1 dan is het veld vrijgespeeld en moet het aantal bommen rond dit vak berekend worden
        speelveld[i][j]=berekenAantalBommen(i,j);
      } else { // anders staat hier een #
        speelveld[i][j]=35;
      }
    }
  }
  while(getchar()!='\n');
}

void showSpeelveld(void){

  //functie om het speelveld te printen

  printf("   A   B   C   D   E   F   G   H\n");
  printf(" +---+---+---+---+---+---+---+---+\n");
  for(int i=0;i<8;i++){
    printf("%d|",i+1);
    for(int j=0;j<8;j++){

      //als er een # moet staan wordt de ascii waarden in een char afgeprint anders wordt het aantal bommen afgeprint
      
      if(speelveld[i][j]==35){
        printf(" %c |",speelveld[i][j]);
      } else {
        printf(" %d |",speelveld[i][j]);
      }
      
    }
    printf("\n");
  }
  printf(" +---+---+---+---+---+---+---+---+\n");
}


void showBommenveld(void){
  
  // om te laten zien waar er bommen zitten
  printf("   A   B   C   D   E   F   G   H\n");
  printf(" +---+---+---+---+---+---+---+---+\n");
  for(int i=0;i<8;i++){
    printf("%d|",i+1);
    for(int j=0;j<8;j++){
      printf(" %d |",bommenveld[i][j]);
    }
    printf("\n");
  }
  printf(" +---+---+---+---+---+---+---+---+\n");
}


uint8_t speelCoordinaatVrijOfBewaar(void){

  // vraagt de coordinaat die vrijgespeeld wilt worden en speelt deze vrij

  char coordinaatOfBewaar[10];
  int8_t rij;
  int8_t kolom;

  printf("Welke coordinaat wil je vrijspelen? Of wil je het spel bewaren? ");
  fgets(coordinaatOfBewaar,10,stdin);
  coordinaatOfBewaar[strlen(coordinaatOfBewaar)-1]='\0';// \n verwijderen
  // loopt door heel de string en verandert alle lowercase letters naar uppercase letters
  for(int i=0;i<strlen(coordinaatOfBewaar);i++){
    if (isupper(coordinaatOfBewaar[i])==0){
      coordinaatOfBewaar[i]=toupper(coordinaatOfBewaar[i]);
    }
    // als de character in de string een een letter is dan is dit de kolom
    if(strcmp("BEWAREN",coordinaatOfBewaar)==0){
      bewaar();
      return 1;
    }else if(isalpha(coordinaatOfBewaar[i])>0){
      kolom = coordinaatOfBewaar[i] -'A';//omrekenen van de letter waarde naar 0 tot 7 via de ascii waarden
    } else {
      rij = atoi(&coordinaatOfBewaar[i]) -1;//omzetten van het getal naar een int en omrekennen van 0 tot 7
    }
  }
  if(bommenveld[rij][kolom]==1){ //als een bom gekozen wordt ==> return 2
    return 2;
  } else { // anders wordt de floodfill opgeroepen en return 0
    floodFill(rij,kolom);
    return 0;
  }
}

void floodFill(int8_t rij,int8_t kolom){
 //als de gekozen positie in de array ligt
  if(rij>=0 && kolom>=0 && rij <=7 && kolom <=7){
    // aantal bommen wordt berekend rondom deze locatie 
    uint8_t counter = berekenAantalBommen(rij,kolom);
    // als het veld nog niet vrijgespeeld is
    if(speelveld[rij][kolom]==35){
      speelveld[rij][kolom] = counter; // plaatst het getal in het speelveld
      // als er 0 bommen zijn wordt er flood fill gedaan tot alle nullen open zijn
      if(counter == 0){
      floodFill(rij-1,kolom-1);
      floodFill(rij-1,kolom);
      floodFill(rij-1,kolom+1);
      floodFill(rij,kolom-1);
      floodFill(rij,kolom+1);
      floodFill(rij+1,kolom-1);
      floodFill(rij+1,kolom);
      floodFill(rij+1,kolom+1);
      }
    }
  }
}

uint8_t berekenAantalBommen(int8_t rij,int8_t kolom){

  //berekennen van het aantal bommen rondom de coordinaat

  uint8_t counter = 0;
  
  // ervoor zorgen dat er niet uit het veld wordt gegaan om te berekennen hoeveel bommen er zijn
  uint8_t minRij = (rij <= 0) ? 0 : rij-1; 
  uint8_t maxRij = (rij >= 7) ? 7 : rij+1;
  uint8_t minKolom = (kolom <= 0) ? 0 : kolom-1;
  uint8_t maxKolom = (kolom >= 7) ? 7 : kolom+1;

  //door elk mogelijk omligend vakje gaan en kijken of hier een bom aanwezig is
  for(int i=minRij;i<=maxRij;i++){
    for (int j=minKolom;j<=maxKolom;j++){
      counter += bommenveld[i][j];//counter met 1 of 0 optellen naar gelang er een bom staat
    }
  }
  return counter;
}



float berekeningVoortgangsPercentage(void){

  // berekening van hoeveel procent er vrijgespeeld is
  
  uint8_t aantalBommen = 0;
  uint8_t aantalVrijgespeeldeVelden = 0;
  uint8_t aantalVrijTeSpelenVelden = 0;
  float voortgangsPercentage = 0.0;

  // berekennen hoeveel bommen er in totaal in het veld zitten
  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      if(bommenveld[i][j] == 1){
        aantalBommen++;
      }
    }
  }
  
  // berekennen hoeveel velden er zijn vrijgespeeld
  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      if(speelveld[i][j] != 35){ // als het speelveld verschillend is van een # dan is hij vrijgespeeld
        aantalVrijgespeeldeVelden++;
      }
    }
  }
  
  aantalVrijTeSpelenVelden = 64 - aantalBommen; // berekening voor het aantal velden dat vrijgespeeld moeten worden in totaal
  // berekennen hoeveel % er al is vrijgespeeld van de vrij te spalen velden
  voortgangsPercentage = (aantalVrijgespeeldeVelden/(float)aantalVrijTeSpelenVelden)*100; 
  
  printf("Je hebt %.2f% vrijgespeeld\n",voortgangsPercentage);
  return voortgangsPercentage;
}

void bewaar(void){

  //functie voor het generen van 2 hexadecimale getallen om het spel op te slaan
  uint64_t vrijgespeeldeVelden64Bit=0;
  uint64_t locatieBommen64Bit=0;

  for(int i=0;i<=7;i++){
    for(int j=0;j<=7;j++){
      if(speelveld[i][j]!=35){
         vrijgespeeldeVelden64Bit |= (1ull << 63-(i * 8 + j)); // een 1 of een 0 inschuiven op de juiste plaats
      } 
      if (bommenveld[i][j]==1) {
      locatieBommen64Bit |= (1ull << 63-(i * 8 + j)); // een 1 of een 0 inschuiven op de juiste plaats
      }
    }
  }

  printf("hexadecimaal getal voor vrijgespeelde velden: %lx\nhexadecimaal getal voor locatie van de bommen: %lx\n",vrijgespeeldeVelden64Bit,locatieBommen64Bit);
}
