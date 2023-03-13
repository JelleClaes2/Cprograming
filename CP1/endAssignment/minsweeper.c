//library's
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

//functies
int verwelkoming             (void);//begin menu waar je het aantal bommen kan kiezen en een spel kunt starten 
void verloren                (void);//gaat je het veld tonen als je verloren bent
void gewonnen                (void);
void printveld               (int aantalbommen);//gaat het aantal bommen random printen in het veld
void omliggendebommen        (void);//gaat berekenen hoeveel bommen er rondom je liggen
void spelverloop             (void);//gaat je telekens het vakje tonen dat je opvraagt en checken als er geen bom ligt
int invoer                   (void);//gaat je invoer inlezen en omzetten zodat we weten welke vakje we moeten tonen of wel het spel moeten opslaan 
void floodfill               (int x,int y);//als je een vakje aanduid met een nul gaat hij alle omliggende nullen zichtbaar maken met deze functie 
void speelveldprinten        (void);//print je het blankco speelveld
float voortgangspercentage   (void);// toont je hoever je het spel hebt vrijgespeeld 
void bewaren                 (void); // het spel opslaan zodat je de volgende keer hier verder mee kan gaan
void inladen                 (void);

//difine's
#define SIZE 8

//globale variabelen
char veld[SIZE][SIZE];
char speelveld[SIZE][SIZE];
int  xinvoer=0;
int  yinvoer=0;
int controle=0;
//main
int main(void) 
{
  printveld(verwelkoming());
  omliggendebommen();
  spelverloop();
  return 0;
}

//functies
int verwelkoming()
{
  //int aantal =0;
  char LadenOfNieuwSpel[6];
  int aantalbommen=0;
  
  printf("Welkom bij minesweeper :-)\n");
  printf("Geef het aantal bommen in waarmee je wilt spelen 'getal tussen 0-64' of \n'laden' Als je wilt verder gaan met de vorige game die bewaart is gebleven.\n'bewaren' word het spel gesaved om later mee verder te gaan\n");

  //zorgen dat ze max 5 karakters kunnen ingeven van karakters op het toetsenbord die in het array LadenOf... word opgeslagen:
  fgets(LadenOfNieuwSpel,6,stdin); 
//zorgen dat het niet hoofdlettergevoelig is:
  for(int x=0;x<strlen(LadenOfNieuwSpel);x++){
    if(isupper(LadenOfNieuwSpel[x]==0)){
      LadenOfNieuwSpel[x]=tolower(LadenOfNieuwSpel[x]);
    }
  }
  //kijken wat er in het array staat als dit overeenkomt met "laden" anders gaan we het bommenveld maken
  if(strcmp(LadenOfNieuwSpel,"laden")==0){ 
    inladen();
    omliggendebommen();
    spelverloop();}
  else{
    aantalbommen=atol(LadenOfNieuwSpel);
  }
  
  while(((aantalbommen>=0)&&(aantalbommen<64))!=1);
  printf("Veel succes!");
  return aantalbommen;
}
void printveld(int aantalbommen)
{
  int bommen = 0;
  int      x = 0;
  int      y = 0;
  srand(time(NULL));
  while (bommen < aantalbommen) 
  {
    x = rand() % (SIZE);
    y = rand() % (SIZE);
    if (veld[x][y] != 42)
    {
      veld[x][y] = 42;
      bommen++;
    }
  }
}
void omliggendebommen()
{
  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      if (42 == (veld[x][y])) {
        if (((veld[x - 1][y - 1]) != 42) &&
            ((x - 1) >= 0)&& ((x - 1) < 8) && ((y - 1) >= 0) && ((y - 1) < 8)) {
          veld[x - 1][y - 1] += 1;
        }
        if (((veld[x + 1][y + 1]) != 42) && ((x + 1) >= 0) && ((x + 1) < 8) &&
            ((y + 1) >= 0) && ((y + 1) < 8)) {
          veld[x + 1][y + 1] += 1;
        }
        if (((veld[x - 1][y]) != 42) && ((x - 1) >= 0) && ((x- 1) < 8) &&
            (y >= 0) && (y < 8)) {
          veld[x - 1][y] += 1;
        }
        if (((veld[x][y - 1]) != 42) && (x >= 0) && (x < 8) && ((y - 1) >= 0) &&
            ((y - 1) < 8)) {
          veld[x][y - 1] += 1;
        }
        if (((veld[x][y + 1]) != 42) && (x >= 0) && (x < 8) && ((y + 1) >= 0) &&
            ((y + 1) < 8)) {
          veld[x][y + 1] += 1;
        }
        if (((veld[x + 1][y]) != 42) && ((x + 1) >= 0) && ((x + 1) < 8) &&
            (y >= 0) && (y < 8)) {
          veld[x + 1][y] += 1;
        }
        if (((veld[x - 1][y + 1]) != 42) && ((x - 1) >= 0) && ((x - 1) < 8) &&
            ((y + 1) >= 0) && ((y + 1) < 8)) {
          veld[x - 1][y + 1] += 1;
        }
        if (((veld[x + 1][y - 1]) != 42) && ((x + 1) >= 0) && ((x + 1) < 8) &&
            ((y - 1) >= 0) & ((y - 1) < 8)) {
          veld[x + 1][y- 1] += 1;
        }
      }
    }
    printf("\n");
  }

  /*for (int A = 0; A < SIZE; A++) {
    for (int C = 0; C < SIZE; C++) {
      if (42 == veld[A][C]) {
        printf("|%1c|", veld[A][C]);
      } else {
        printf("|%1d|", veld[A][C]);
      }
    }
    printf("\n");
  }*/
  printf("\n");
}
void spelverloop()
{
  int x = 0;
  int y = 0;
  speelveldprinten();
  while (speelveld[x][y]!= 42) 
  { 
    invoer();
    //if (invoer()==1)
    //{
    x=xinvoer;
    y=yinvoer;
    if (((x >= 0) && (x < 9)) && (y >= 0) && (y < 9))
    {
      floodfill(x, y);
      speelveld[x][y] = veld[x][y];
      printf("  ");
      for (int i = 0; i < SIZE; i++) 
      {
       printf("%c",'A'+i);
       printf("  ");
      }
       printf("\n");
      for (int x = 0; x < SIZE; x++) 
      {
         printf("%c",'1'+x);
        for (int y = 0; y < SIZE; y++) 
        {
          if (veld[x][y] == 42) 
          {
            printf("|%c|", speelveld[x][y]);
          } 
          else if (veld[x][y] != 42)
          {
            if (speelveld[x][y] < 9)
            {
              printf("|%d|", speelveld[x][y]);
            } 
            else 
            {
              printf("|%c|", speelveld[x][y]);
            }
          }
          }
        printf("\n");
      }
      printf("\nJe hebt %.2f%% vrijgespeeld.\n\n" 
      ,voortgangspercentage());
    }
    //  }
    else 
    {
      printf("Geef een getal in binnen de range!\n");
    }
  }
  verloren();
}
int invoer()
{
  controle=0;
  char invoer[8]={0};
  int x=0;
  int y=0;
  int enter=0;
  fgets(invoer,8,stdin);
  if ((strcmp(invoer,"bewaren")==0)||(strcmp(invoer,"BEWAREN")==0))
  {
    bewaren();
  }
  //else //hier nog iets verzinnen dat het programma de eerste keer niet gelijk het veld al print maar wacht tot er voor de eerste keer coordinaten worden ingegeven
  else
  {
   // int x=0;
   // int y=0;
    if(invoer[0]>='0' && invoer[0]<='9')
    {
      if((invoer[1]>=65)&&(invoer[1]<=72))
      {
        invoer[1]=invoer[1]+32;
      }
      x = invoer[0]-49;
      y = invoer[1]-97;
    }
    else
    {
      if(invoer[1]>='0' && invoer[1]<='9')
      {
        if((invoer[0]>=65)&&(invoer[0]<=72))
        {
          invoer[0]=invoer[0]+32;
        }
        x = invoer[1]-49;
        y = invoer[0]-97;
      }
      }
    xinvoer=x;
    yinvoer=y;
    }
   return 1; 
   // printf("%d %d",x,y);
}  
void floodfill(int x,int y)
{
  if ((speelveld[x][y] != '-') || (veld[x][y] != 0))
  {
    speelveld[x][y] = veld[x][y];
    return;
  }
  speelveld[x][y] = veld[x][y];
  for (int xtest = -1; xtest <= 1; xtest++) 
  {
    for (int ytest = -1; ytest <= 1; ytest++)
    {
      if (((x + xtest) >= 0) && ((x + xtest) < 8) && ((y + ytest) >= 0) && ((y + ytest) < 8)) 
      {
        floodfill(x + xtest, y + ytest);
      }
    }
  }
  //return;
}
float voortgangspercentage(void)
{
  int aantalspeelveld=0;
  int aantalveld=0;
  float percentage=0;
  for (int x = 0; x < SIZE; x++) 
  {
        for (int y = 0; y < SIZE; y++) {
          if ((speelveld[x][y]>=0)&&(speelveld[x][y]<=8))
          {
            aantalspeelveld++;
          }
          if ((veld[x][y]>=0)&&(veld[x][y]<=8))
          {
            aantalveld++;
          } 
        }
}
  percentage=(((float)aantalspeelveld/(float)aantalveld)*100);
  if(percentage==100)
  {
    gewonnen();
  }
  return percentage;
}
void verloren()
{
  printf("\nBOOOOMMM YOU LOSE \n ");
  
  printf("  ");
  for (int i = 0; i < SIZE; i++) 
  {
    printf("%c",'A'+i);
    printf("  ");
  }
  printf("\n");
  for (int x = 0; x < SIZE; x++) 
  {
     printf("%c",'1'+x);
    for (int y = 0; y < SIZE; y++) 
    {
      if (42 == veld[x][y]) 
      {
        printf("|%c|", veld[x][y]);
      } 
      else
      {
        printf("|%d|", veld[x][y]);
      }
    }
    printf("\n");
  }
}
void speelveldprinten()
{
   printf("  ");
  for (int i = 0; i < SIZE; i++) 
  {
    printf("%c",'A'+i);
    printf("  ");
  }
  printf("\n");
  for (int x = 0; x < SIZE; x++) 
  {
    printf("%c",'1'+x);
    for (int y = 0; y < SIZE; y++) 
    {
      printf("|-|");
      speelveld[x][y] = 45;
    }
   printf("\n");
  }
}
void gewonnen()
{
  printf("\nJE HEBT GEWONNEN TOPPER!\n\n");
  printf("  ");
  for (int i = 0; i < SIZE; i++) 
  {
    printf("%c",'A'+i);
    printf("  ");
  }
  printf("\n");
  for (int x = 0; x < SIZE; x++) 
  {
     printf("%c",'1'+x);
    for (int y = 0; y < SIZE; y++) 
    {
      if (42 == veld[x][y]) 
      {
        printf("|%c|", veld[x][y]);
      } 
      else
      {
        printf("|%d|", veld[x][y]);
      }
    }
    printf("\n");
  }
}
void bewaren(void)
{
  uint64_t bommen_bitmask=0;
  uint64_t gespeeldevelden_bitmask=0;
  
  for (int x=0; x<SIZE; x++)
  {
    for (int y=0; y<SIZE; y++)
    {
      if (speelveld[x][y] != 45)
      {
        gespeeldevelden_bitmask |= (1ull << (63-(x * SIZE + y)));
        printf("0");
      }
       if(veld[x][y] == 42)
      {
        bommen_bitmask |= (1ull << (63-(x * SIZE + y)));
        printf("1");
      }
    }
    printf("\n");
  }
printf("hexadecimale waarde voor de gespeelde velden: %lx \n", gespeeldevelden_bitmask);
printf("hexadecimale waarde voor de locatie van de bommen: %lx \n", bommen_bitmask);
printf("Het spel is gesaved om later mee verder te gaan \n\n");
  
} 
 void inladen(void)
{
  uint64_t gespeeldevelden=0;
  uint8_t positiebit_gespeeldevelden=63;
  uint8_t gespeeldevelden_bit=0;
  unsigned long long gespeeldevelden_mask;

  uint64_t bommen=0;
  uint8_t positiebit_bommen=63;
  uint8_t bommen_bit=0;
  unsigned long long bommen_mask;

  printf("Geef de hexadecimale waarde voor de gespeelde velden:");
  (void)scanf("%lx",&gespeeldevelden);
  printf("Geef de hexadecimale waarde voor de locatie van de bommen:");
  (void)scanf("%lx",&bommen);
  
  for (int x=0; x<SIZE; x++){
    for (int y=0; y<SIZE; y++){
      bommen_mask = 1ull << positiebit_bommen;
      bommen_bit = (bommen & bommen_mask) >> positiebit_bommen;
      positiebit_bommen--;
      printf("%d",bommen_bit);
      //veld[x][y] = bommen_bit;}
      if(bommen_bit == 1)
      {
      veld[x][y] = 42;
      }
      else
      {
      veld[x][y] = 0;
      }
      }
    }
  omliggendebommen();
    for (int x=0; x<SIZE; x++)
    {
      for (int y=0; y<SIZE; y++)
      {
      gespeeldevelden_mask = 1ull << positiebit_gespeeldevelden;
      gespeeldevelden_bit = (gespeeldevelden & gespeeldevelden_mask) >> positiebit_gespeeldevelden;
      positiebit_gespeeldevelden--;
        if(gespeeldevelden_bit == 1)
        {
          speelveld[x][y] = veld[x][y];
        }
        else
        {
          speelveld[x][y] = 45;
        }
        }
      }
    
    spelverloop();
    
  //verloren();
  }


// to do van belangerijk naar minder belangerijk geordend
// flowchart maken.
// het welkom gebeuren enzo 
// code mooi maken in de zin van inspringingen.;

