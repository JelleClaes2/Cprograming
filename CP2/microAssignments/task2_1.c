// Read me !

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

struct point3D *generatePoints( int numberOfTrianglesX, int numberOfTrianglesY );
struct triangle *linkPointsToTriangles( int numberOfTrianglesX, int numberOfTrianglesY, struct point3D *points );
void printResults( struct triangle *triangles, int numberOfTriangles );

int main( void )
{
    { // Make configurable random
        int seed = 0;
        printf( "Enter the seed that you want to use for creating the points: " );
        (void)scanf( "%d", &seed );
        srand( seed ? seed : time( NULL ) );
    }

    int numberOfTrianglesX = 0, numberOfTrianglesY = 0;
    struct point3D *points = NULL;
    struct triangle *triangles = NULL;

    printf( "Enter the amount of triangles that you want to generate in the x- and y-direction: " );
    (void)scanf( "%d %d", &numberOfTrianglesX, &numberOfTrianglesY );

    points = generatePoints( numberOfTrianglesX, numberOfTrianglesY );
    triangles = linkPointsToTriangles( numberOfTrianglesX, numberOfTrianglesY, points );
    printResults( triangles, 2 * numberOfTrianglesX * numberOfTrianglesY );

    return 0;
}

/*
  This function generates a 2D grid of points. The points are stored in an array of the data type struct point3D. You need to add one point more than the number of triangles in each direction (i.e. if the number of triangles in the x-direction is 3 then 4
  points need to be created in the x-direction). The range in each direction goes from 0 to 1. For example:

  2 triangles in the x-direction and 2 triangles in the y-direction results in the points:
  (0.000000, 0.000000, 0.549922)
  (0.000000, 0.500000, 0.903748)
  (0.000000, 1.000000, 0.240916)
  (0.500000, 0.000000, 0.534169)
  (0.500000, 0.500000, 0.454029)
  (0.500000, 1.000000, 0.724658)
  (1.000000, 0.000000, 0.288663)
  (1.000000, 0.500000, 0.704045)
  (1.000000, 1.000000, 0.468132)
  The value of the z-direction is a random point between 0 and 1. Note that the points are sorted based on increasing values in the x-direction first and then on increasing values in the y-direction.
HINT : z = rand() / (float)RAND_MAX;
*/
struct point3D *generatePoints( int numberOfTrianglesX, int numberOfTrianglesY )
{
    // Allocate memory for the points
    int numberOfPointsX = numberOfTrianglesX + 1;
    int numberOfPointsY = numberOfTrianglesY + 1;
    int numberOfPoints = numberOfPointsX * numberOfPointsY;
    struct point3D *points = malloc( numberOfPoints * sizeof( struct point3D ) );

    // Generate the points
    for( int tx = 0; tx < numberOfPointsX; tx++ )
    {
        for( int ty = 0; ty < numberOfPointsY; ty++ )
        {
            points[ty + tx * numberOfPointsY].x = tx / (float)numberOfTrianglesX;
            points[ty + tx * numberOfPointsY].y = ty / (float)numberOfTrianglesY;
            points[ty + tx * numberOfPointsY].z = rand() / (float)RAND_MAX;
        }
    }

    // Sort the points based on increasing values in the x-direction first and then on increasing values in the y-direction
    for( int i = 0; i < numberOfPoints - 1; i++ )
    {
        for( int j = i + 1; j < numberOfPoints; j++ )
        {
            if( points[i].x > points[j].x || ( points[i].x == points[j].x && points[i].y > points[j].y ) )
            {
                struct point3D temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }

    return points;
}


/*
  This function iterates through the array of points and creates a height map based on these points.
*/
struct triangle *linkPointsToTriangles( int numberOfTrianglesX, int numberOfTrianglesY, struct point3D *points )
{
    int numberOfTriangles = 2 * numberOfTrianglesX * numberOfTrianglesY;
    struct triangle *triangles = (struct triangle*)malloc(numberOfTriangles * sizeof(struct triangle));

    for( int tx = 0; tx < numberOfTrianglesX; tx++ )
    {
        for( int ty = 0; ty < numberOfTrianglesY; ty++ )
        {
            int index = 2 * ( tx * numberOfTrianglesY + ty );

            triangles[index].p1 = &points[ty + tx * ( numberOfTrianglesY + 1 )];
            triangles[index].p2 = &points[( ty + 1 ) + ( tx + 1 ) * ( numberOfTrianglesY + 1 )];
            triangles[index].p3 = &points[ty + ( tx + 1 ) * ( numberOfTrianglesY + 1 )];

            index++;

            triangles[index].p1 = &points[ty + tx * ( numberOfTrianglesY + 1 )];
            triangles[index].p2 = &points[( ty + 1 ) + tx * ( numberOfTrianglesY + 1 )];
            triangles[index].p3 = &points[( ty + 1 ) + ( tx + 1 ) * ( numberOfTrianglesY + 1 )];
        }
    }

    return triangles;
}

/*
  This function prints the three points contained in each triangle.
*/
void printResults( struct triangle *triangles, int numberOfTriangles )
{
    for( int i = 0; i < numberOfTriangles; i++ )
    {
        printf( "Triangle %d -> (%.2f, %.2f, %.2f), (%.2f, %.2f, %.2f), (%.2f, %.2f, %.2f)\n", i, triangles[i].p1->x, triangles[i].p1->y, triangles[i].p1->z, triangles[i].p2->x, triangles[i].p2->y, triangles[i].p2->z, triangles[i].p3->x,
                triangles[i].p3->y, triangles[i].p3->z );
    }
}
