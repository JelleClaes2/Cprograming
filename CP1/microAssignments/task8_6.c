/*
  Gebruik de gedefinieerde enum voor X, Y, Z en gebruik ze als index voor X = 0, Y = 1 en Z = 2.
  Bereken de afstand tussen 2 punten in een 3D ruimte, deze is de vierkantswortel over de som van de kwadratische verschillen.
  Dit wordt ook wel de euclidische afstand afstand genoemd: https://en.wikipedia.org/wiki/Euclidean_distance.

*/
#include <stdio.h>
#include <math.h>

enum coord
{
    X,
    Y,
    Z,
    COORD_SIZE
};

int main( void )
{
    int pointA[COORD_SIZE];
    int pointB[COORD_SIZE];
    printf( "Give x, y and z coordinate of point 1 : " );
    (void)scanf( "%d %d %d", &pointA[X], &pointA[Y], &pointA[Z] );
    printf( "Give x, y and z coordinate of point 2 : " );
    (void)scanf( "%d %d %d", &pointB[X], &pointB[Y], &pointB[Z] );
    double distance = sqrt(pow(pointA[X] - pointB[X],2)+pow(pointA[Y]-pointB[Y],2)+pow(pointA[Z]-pointB[Z],2));
    // afstand = vierkantswortel( 2demacht( X_a - X_b ) + 2demacht( Y_a - Y_b ) + 2demacht( Z_a - Z_b ) )
    printf( "The distance between these points = %lf\n", distance );
    return 0;
}
