/*
Schrijf een programma waarbij een lijst van punten wordt ingelezen. In totaal worden er 15 punten ingelezen. De eerste drie punten zijn de hoekpunten van de eerste driehoek, de volgende drie punten zijn de hoekpunten van de volgende driehoek, ...
Aangezien er 15 punten worden ingelezen zijn er dus 5 driehoeken. Elke driehoek wordt gedefinieerd d.m.v. de struct triangle waarbij elk punt een pointer is naar het overeenkomstige punt in de lijst van punten.
*/
#include <stdio.h>

struct point3D
{
    float x, y, z;
};

struct triangle
{
    struct point3D *p1;
    struct point3D *p2;
    struct point3D *p3;
};

void addPoints( struct point3D *points, int numberOfPoints );
void linkPointsToTriangles( struct point3D *points, struct triangle *triangles, int numberOfTriangles );
void printResults( struct triangle *triangles, int numberOfTriangles );

int main( void )
{
    struct point3D points[15];
    struct triangle triangles[5];

    addPoints( points, sizeof( points ) / sizeof( points[0] ) );
    linkPointsToTriangles( points, triangles, sizeof( triangles ) / sizeof( triangles[0] ) );
    printResults( triangles, sizeof( triangles ) / sizeof( struct triangle ) );

    return 0;
}

/*
  This function asks the user three points each defined by a x, y and z value and stores them in the array of points.
*/
void addPoints( struct point3D *points, int numberOfPoints )
{
    for( int i = 0; i < numberOfPoints; i++ )
    {
        printf( "Give the coordinates of point %d = ", i );
        struct point3D tmpPoint;
        (void)scanf( "%f %f %f", &tmpPoint.x, &tmpPoint.y, &tmpPoint.z );
        points[i] = tmpPoint;
    }
}

/*
  This function iterates through the array of triangles and links each point of the triangle, which is a pointer, to the corresponding point in the array of points.
*/
void linkPointsToTriangles( struct point3D *points, struct triangle *triangles, int numberOfTriangles )
{
    int index=0;
    for(int i=0;i<numberOfTriangles;i++){
        struct triangle tmpTriangle;
        tmpTriangle.p1 = &points[index];
        index++;
        tmpTriangle.p2 = &points[index];
        index++;
        tmpTriangle.p3 = &points[index];
        index++;

        triangles[i] = tmpTriangle;
    }
}

/*
  This function prints the three points contained in each triangle. For formatting you can look at the tests.
*/
void printResults( struct triangle *triangles, int numberOfTriangles )
{

    for(int i=0;i<numberOfTriangles;i++){
        printf("Triangle %d -> (%2.2f, %2.2f, %2.2f), (%2.2f, %2.2f, %2.2f), (%2.2f, %2.2f, %2.2f)\n",i,triangles[i].p1->x,triangles[i].p1->y,triangles[i].p1->z,triangles[i].p2->x,triangles[i].p2->y,triangles[i].p2->z,triangles[i].p3->x,triangles[i].p3->y,triangles[i].p3->z);
    }
}
