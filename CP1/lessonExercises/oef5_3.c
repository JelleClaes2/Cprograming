/*
  Schrijf een programma dat de schuine zijde van een rechthoekige driehoek berekent als de rechthoekszijden gegeven zijn. Bereken ook de twee ontbrekende hoeken in graden.

     |\
     |  \
  a  |    \    c          Stelling van Pythagoras => c^2 = a^2 + b^2
     |      \
     |        \
     ----------
          b

  Schrijf een functie genaamd berekeningSchuineZijde(int a, int b) met als return type een float voor de berekening van de schuine zijde. Voor de berekening van de
  hoeken gebruik je de funties acos of asin of atan uit math.h.

  Voorbeeld:
  ----------
  Geef de waarden van de twee rechthoekszijden: 3 4
  De schuine zijde is gelijk aan: 5.00
  De hoek tussen a en c is gelijk aan 53.13 graden.
  De hoek tussen b en c is gelijk aan 36.87 graden.

*/
#include <stdio.h>
#include <math.h>

float berekeningSchuineZijde(int a, int b);
float berekeningHoek(int a,int b);


int main(void){
  int a=0;
  int b=0;
  printf("Geef de waarden van de twee rechthoekszijden: ");
  (void)scanf("%d %d",&a,&b);
  printf("De schuine zijde is gelijk aan: %.2f\n",berekeningSchuineZijde(a,b));
  printf("De hoek tussen a en c is gelijk aan: %.2f graden\n",berekeningHoek(a,b));
  printf("De hoek tussen a en c is gelijk aan: %.2f graden\n",berekeningHoek(b,a));
}

float berekeningSchuineZijde(int a, int b){
  return sqrt( pow(a,2)+pow(b,2) );
}

float berekeningHoek(int a, int b){
  return (atan((float)a/b)*(180/M_PI));
}
