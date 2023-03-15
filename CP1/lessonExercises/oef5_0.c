/*
  Maak een functie genaamd printHelloWorld() die 'Hello world!' print. Roep deze functie 10x op vanuit de main doormiddel van een for-loop.
*/
#include <stdio.h>
void helloWorld(void);

int main(){
  helloWorld();
  return 0;
}

void helloWorld(void)
{
  for(int i=0;i<=10;i++){
    printf("Hello World\n");
  }
}
