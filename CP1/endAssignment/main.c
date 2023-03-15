// link flowchart
// https://miro.com/app/board/uXjVP12HfkU=/ 

#include <time.h>
#include <stdint.h>
#include "mineSweeper.h"



int main(void) {
  //de random warrden laten bazeren op de tijd
  srand(time(NULL));

  uint8_t eindeSpel = 0;
  
  startSpel();
  showSpeelveld();

  // het spel blijft loopen zolang: er geen bom wordt geraakt, zolang het spel niet is gewonnen of het spel bewaard wordt
  while(eindeSpel == 0){
    eindeSpel = speelCoordinaatVrijOfBewaar();
    
    if(berekeningVoortgangsPercentage()==100){
      eindeSpel = 3;
    }
    
    // als er verder kan gespeeld worden wordt het speelveld geprint
    if(eindeSpel == 0){
      showSpeelveld();
    }
  }

  //bepaalt het einde van het spel
  switch(eindeSpel){
      case 1:// bewaren
        printf("HINT: schrijf de getallen ergens op voor volgende keer");
        break;
      case 2:// bom werdt geraakt
        printf("EINDE SPEL JE RAAKTE EEN BOM\n");
        printf("HIER STONDEN ALLE BOMMEN\n");
        showBommenveld(); 
        break;
      case 3:// alle velden op de bommen na zijn vrijgespeeld
        showSpeelveld();
        printf("Proficiat je hebt alle bommen gevonden\n");
        break;
    }
  return 0;
}


