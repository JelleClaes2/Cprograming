/*
 * Maak een programma, van scratch, dat de geboorte datum van een persoon neemt en het volgende doet.
 * Als de geboorte datum voor 1987 is          print "Dinosaurus".
 * Als de geboorte datum na 1987 is            print "Baby".
 * Als de geboorte datum gelijk is aan 1987 is print "Birthyear of God".
 *
 *       | "Dinosaurus"         if X < 1987
 * |X| = | "Baby"               if X > 1987
 *       | "Birthyear of God"   if X = 1987
 *
 * Om input te krijgen gebruik de volgende snippet code.
 * int geboorte_jaar = 0;
 * (void)scanf("%d", &geboorte_jaar);
 *
 * Om de output te printen kan je printf("..."); in de truthy statement block gebruiken.
 */
#include <stdio.h>

int geboorte_jaar = 0;
int main()
{
  printf("Geef je geboorte jaar in: ");
  (void)scanf("%d", &geboorte_jaar);

  if (geboorte_jaar < 1987)
  {
    printf("Dinosaurus\n");
  }
  else if(geboorte_jaar > 1987)
  {
    printf("Baby\n");
  }
  else
  {
    printf("Birthyear of God\n");
  }
}
