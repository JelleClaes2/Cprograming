#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUMBER_OF_POLYGONS 12
#define NUMBER_OF_POLYGON_TYPES 6

enum polygon
{
    TRIANGLE,
    QUADRILATERAL,
    PENTAGON,
    HEXAGON,
    HEPTAGON,
    OCTAGON
};

struct point3D
{
    float x, y, z;
};

struct point3D getPoint( struct point3D center, int corner, enum polygon polygon );
void generatePolygon (enum polygon enumPolygonValue,struct point3D **pointList);
void sortRaggedArray(enum polygon *enumList,struct point3D **list);
void printRaggedArray(enum polygon *enumList,struct point3D **list);





/*
  Maak de functie "printRaggedArray()" die de meegegeven ragged array print m.b.v. de lijst van enums.
  In de enum lijst staat het type en bepaald hoeveel punten er in elke lijst zitten die door de ragged array wordt gereferenced.
  Print steeds in volgend formaat `%d) -> (%f, %f, %f) (%f, %f, %f) (%f, %f, %f) ...` waarbij eerste %d voor aantal punten staat en elke groep van 3 %f voor de coordinaten van x, y, z van elk punt.
  Het aantal punten is minstens 3 voor een driehoek, maar kan tot 8 oplopen voor een achthoek.
*/

int main( void )
{
    { // Make configurable random
        int seed = 0;
        printf( "Enter the seed that you want to use for creating the points: " );
        (void)scanf( "%d", &seed );
        srand( seed ? seed : time( NULL ) );
    }

    // Initialization
    struct point3D *polygonLists[NUMBER_OF_POLYGONS];

    // Generate polygons
    enum polygon polygonEnumList[NUMBER_OF_POLYGONS];
    for( int i = 0; i < NUMBER_OF_POLYGONS; i++ )
    {
        polygonEnumList[i] = rand() % 6;
        generatePolygon( polygonEnumList[i], &polygonLists[i] );
    }

    // Print ragged array
    printf( "Ragged array with genererated polygons\n" );
    printf( "=======================================\n" );
    printRaggedArray( polygonEnumList, polygonLists );

    // Sort ragged array
    sortRaggedArray( polygonEnumList, polygonLists );

    // Print ragged array
    printf( "Ragged array after sorting the polygons\n" );
    printf( "=======================================\n" );
    printRaggedArray( polygonEnumList, polygonLists );

    return 0;
}

struct point3D getPoint( struct point3D center, int corner, enum polygon polygon )
{
    int numberOfPoints = polygon + 3;
    float angle = 2 * M_PI / numberOfPoints;
    struct point3D point;
    point.x = center.x + cos( corner * angle );
    point.y = center.y + sin( corner * angle );
    point.z = center.z;
    return point;
}

/*
  Maak de functie "generatePolygon()" die de meegegeven ragged array vult met een pointer naar een lijst van punten die de gevraagde polygon voorstelt.
  Alloceer het aantal punten dat nodig is om de polygon te kunnen voorstellen (TRIANGLE -> 3, QUADRILATERAL -> 4, PENTAGON -> 5, HEXAGON -> 6, HEPTAGON -> 7, OCTAGON -> 8) en vraag voor elk punt via getPoint() de coordinaten op.
  Het middelpunt wordt bepaald door 3 random getallen voor x, y en z. `struct point3D center = {rand() % 10, rand() % 10, rand() % 10};`
*/
void generatePolygon (enum polygon enumPolygonValue,struct point3D **pointList){
    *pointList = (struct point3D*)calloc(enumPolygonValue+3,sizeof(struct point3D));
    struct point3D center = {rand() % 10, rand() % 10, rand() % 10};
    for(int i=0;i<(int)enumPolygonValue+3;i++){
        (*pointList)[i]=getPoint(center, i, enumPolygonValue);
    }
}

/*
  Maak de functie "sortRaggedArray()" die de meegegeven ragged array sorteert a.d.h.v. de lijst van enums.
  Na het sorteren is de volgorde van veelhoeken de volgende: TRIANGLE, QUADRILATERAL, PENTAGON, HEXAGON, HEPTAGON, OCTAGON.
  Dit betekent dus dat eerst alle driehoeken komen, gevolgd door de vierhoeken, ...
  Om de ragged array te sorteren loop je per polygon type door de ragged array van polygonen en swap je elke keer dat je dat type tegenkomt met een juiste positie waar ze zou moeten komen.
  De juiste positie start vanaf het begin van de array en gaat naar de volgende in lijn elke keer dat er een swap uitgevoerd wordt.
*/
void sortRaggedArray(enum polygon *enumList,struct point3D **list){
    int currentTypeIndex = 0;
    for (int i = 0; i < NUMBER_OF_POLYGON_TYPES; i++) {

        for (int j = 0; j < NUMBER_OF_POLYGONS; j++) {
            if ((int)enumList[j] == i) {
                struct point3D *temp = list[j];
                list[j] = list[currentTypeIndex];
                list[currentTypeIndex] = temp;
                enumList [j] = enumList[currentTypeIndex];
                enumList[currentTypeIndex] = i;
                currentTypeIndex++;
            }
        }
    }
}

/*
  Maak de functie "printRaggedArray()" die de meegegeven ragged array print m.b.v. de lijst van enums.
  In de enum lijst staat het type en bepaald hoeveel punten er in elke lijst zitten die door de ragged array wordt gereferenced.
  Print steeds in volgend formaat `%d) -> (%f, %f, %f) (%f, %f, %f) (%f, %f, %f) ...` waarbij eerste %d voor aantal punten staat en elke groep van 3 %f voor de coordinaten van x, y, z van elk punt.
  Het aantal punten is minstens 3 voor een driehoek, maar kan tot 8 oplopen voor een achthoek.
*/
void printRaggedArray(enum polygon *enumList,struct point3D **list){
    for(int i=0;i<NUMBER_OF_POLYGONS;i++){
        printf ("%d) ->",enumList[i]+3);
        for (int j=0; j<(int)enumList[i]+3 ; j++) {
            printf (" (%f, %f, %f)",list[i][j].x,list[i][j].y,list[i][j].z);
        }
        printf("\n");
    }

}
