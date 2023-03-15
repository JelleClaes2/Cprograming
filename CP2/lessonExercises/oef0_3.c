#include <stdio.h>

struct geolocatie{
    char land[10];
    char stad[10];
    float lattitude;
    float longitude;
};

int main(){
    struct geolocatie locatie[10];
    for(int i=0;i<10;i++){

        printf("In welk land zit je?\n");
        //while(getchar() != '\n');
        fgets(locatie[i].land,10,stdin);

        printf("In welke stad zit je?\n");
        //while(getchar() !='\n');
        fgets(locatie[i].stad,10,stdin);

        printf("Wat is uw lattitude?\n");
        (void)scanf("%f",&locatie[i].lattitude);

        printf("Wat is uw longitude?\n");
        (void) scanf("%f",&locatie[i].longitude);
        while(getchar() != '\n');
    }
    return 0;
}
