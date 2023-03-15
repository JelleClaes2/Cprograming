#include <stdio.h>

int main (void)
{
    int getal = 0;
    int cumArray[21]={0};

    printf("Geef een getal: ");
    (void)scanf("%d",&getal);
    while((0 <= getal) && (getal <= 20))
    {
        cumArray[getal]++;
        printf("Geef een getal: ");
        (void)scanf("%d",&getal);
    }

    for(int i = 0; i < 21; i++)
    {
        printf("%d: ", i);
        for(int j = 0; j < cumArray[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}