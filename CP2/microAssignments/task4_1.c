/*
    Driehoeken opsplitsen LIFO algoritme waarbij de driehoeken steeds verder
   worden opgedeeld. En deze kleinere driehoek op de stack worden geplaatst.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct point3D
{
	float x, y, z;
};

struct triangle
{
	struct point3D p1;
	struct point3D p2;
	struct point3D p3;
	struct triangle *next;
};

struct triangle *breakDownTriangle( struct triangle *triangle, float maxSize );
void splitTriangle( struct triangle *triangle, struct triangle **trianglePartOne, struct triangle **trianglePartTwo );
float surfaceArea( struct triangle *triangle );
struct point3D add( struct point3D p1, struct point3D p2 );
struct point3D subtract( struct point3D p1, struct point3D p2 );
struct point3D multiply( float scalar, struct point3D p );
struct point3D crossProduct( struct point3D p1, struct point3D p2 );
float dotProduct( struct point3D p1, struct point3D p2 );
void printResults( struct triangle *triangles );

int main( void )
{
	// Set maximum area size
	float maxAreaSize = 0;
	printf( "Enter maximum triangle area: " );
	(void)scanf( "%f", &maxAreaSize );

	// Initialization
	struct triangle *triangle = (struct triangle *)malloc( sizeof( struct triangle ) );
	triangle->next = NULL;

	triangle->p1 = ( struct point3D ){ -5, 0, 0 };
	triangle->p2 = ( struct point3D ){ 5, 0, 0 };
	triangle->p3 = ( struct point3D ){ 0, 5, 0 };

	// Call split triangle algorithm
	triangle = breakDownTriangle( triangle, maxAreaSize );

	// Print results
	printResults( triangle );

	return 0;
}

/* Break Down the given triangle into smaller triangles of which the surface area is not bigger than the given maxSurfaceArea. To do this, make use of a linked-list LIFO buffer for the todo-list and the returning solution-list.
Start by creating a pointer to the final solution and one to the todo-list which points to the given triangle.
As long as there is work todo in the todo-list, take the next triangle :
- if its area is larger than the threshold, split the triangle with the function splitTriangle(), add the two returned pointers onto the todo-list (LIFO-style : push one before two) and free the memory of the processed triangle.
- if its area is not bigger, add that triangle onto the solution-list (LIFO-style : push triangle).
*/
struct triangle *breakDownTriangle(struct triangle *triangle, float maxSurfaceArea)
{
    struct triangle *solutionList = NULL; // Solution list for triangles with surface area <= maxSurfaceArea
    struct triangle *todoList = NULL; // Todo list for triangles with surface area > maxSurfaceArea

    // Start with the given triangle in the todo list
    todoList = triangle;

    while (todoList != NULL)
    {
        struct triangle *currentTriangle = todoList; // Get the next triangle from the todo list
        todoList = todoList->next; // Move to the next triangle in the todo list

        // Check if current triangle's surface area is greater than maxSurfaceArea
        if (surfaceArea(currentTriangle) > maxSurfaceArea)
        {
            struct triangle *trianglePartOne = NULL;
            struct triangle *trianglePartTwo = NULL;

            // Split the triangle into two parts
            splitTriangle(currentTriangle, &trianglePartOne, &trianglePartTwo);

            // Add the two parts onto the todo list in LIFO order
            trianglePartOne->next = todoList;
            todoList = trianglePartOne;

            trianglePartTwo->next = todoList;
            todoList = trianglePartTwo;

            // Free the memory of the current triangle
            free(currentTriangle);
        }
        else
        {
            // Add the current triangle onto the solution list in LIFO order
            currentTriangle->next = solutionList;
            solutionList = currentTriangle;
        }
    }

    return solutionList;
}



void splitTriangle( struct triangle *triangle, struct triangle **trianglePartOne, struct triangle **trianglePartTwo )
{
	// Set new point along longest edge
	struct point3D ab = subtract( triangle->p2, triangle->p1 );
	struct point3D ac = subtract( triangle->p3, triangle->p1 );
	struct point3D bc = subtract( triangle->p3, triangle->p2 );

	float lengthAB = dotProduct( ab, ab );
	float lengthAC = dotProduct( ac, ac );
	float lengthBC = dotProduct( bc, bc );

	struct triangle *triangle1 = (struct triangle *)malloc( sizeof( struct triangle ) );
	struct triangle *triangle2 = (struct triangle *)malloc( sizeof( struct triangle ) );

	triangle1->next = NULL;
	triangle2->next = NULL;

	struct point3D newPoint = { 0, 0, 0 };
	if( lengthAB > lengthAC && lengthAB > lengthBC )
	{
		newPoint = add( triangle->p1, multiply( 0.5, ab ) );

		triangle1->p1 = triangle->p1;
		triangle1->p2 = newPoint;
		triangle1->p3 = triangle->p3;

		triangle2->p1 = newPoint;
		triangle2->p2 = triangle->p2;
		triangle2->p3 = triangle->p3;
	}
	else if( lengthAC > lengthBC )
	{
		newPoint = add( triangle->p1, multiply( 0.5, ac ) );

		triangle1->p1 = triangle->p1;
		triangle1->p2 = triangle->p2;
		triangle1->p3 = newPoint;

		triangle2->p1 = newPoint;
		triangle2->p2 = triangle->p2;
		triangle2->p3 = triangle->p3;
	}
	else
	{
		newPoint = add( triangle->p2, multiply( 0.5, bc ) );

		triangle1->p1 = triangle->p1;
		triangle1->p2 = triangle->p2;
		triangle1->p3 = newPoint;

		triangle2->p1 = triangle->p1;
		triangle2->p2 = newPoint;
		triangle2->p3 = triangle->p3;
	}

	*trianglePartOne = triangle1;
	*trianglePartTwo = triangle2;
}

float surfaceArea( struct triangle *triangle )
{
	// Calculate surface of given triangle
	struct point3D ab = subtract( triangle->p2, triangle->p1 );
	struct point3D ac = subtract( triangle->p3, triangle->p1 );
	struct point3D acCrossAb = crossProduct( ab, ac );
	float surface = 0.5 * sqrt( acCrossAb.x * acCrossAb.x + acCrossAb.y * acCrossAb.y + acCrossAb.z * acCrossAb.z );

	// printf( "Cross product = (%f, %f, %f)\n", acCrossAb.x, acCrossAb.y, acCrossAb.z );
	// printf( "Triangle surface = %f\n", surface );
	return surface;
}

struct point3D add( struct point3D p1, struct point3D p2 )
{
	struct point3D p;
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	p.z = p1.z + p2.z;

	return p;
}

struct point3D subtract( struct point3D p1, struct point3D p2 )
{
	struct point3D p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	p.z = p1.z - p2.z;

	return p;
}

struct point3D multiply( float scalar, struct point3D p )
{
	struct point3D tmpP;
	tmpP.x = scalar * p.x;
	tmpP.y = scalar * p.y;
	tmpP.z = scalar * p.z;

	return tmpP;
}

struct point3D crossProduct( struct point3D p1, struct point3D p2 )
{
	struct point3D p;

	p.x = p1.y * p2.z - p1.z * p2.y;
	p.y = p1.z * p2.x - p1.x * p2.z;
	p.z = p1.x * p2.y - p1.y * p2.x;

	return p;
}

float dotProduct( struct point3D p1, struct point3D p2 )
{
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

void printResults( struct triangle *triangles )
{
	int counter = 0;
	struct triangle *triangle = triangles;

	while( triangle != NULL )
	{
		printf( "%d) (%f, %f, %f) (%f, %f, %f) (%f, %f, %f)\n", counter + 1, triangle->p1.x, triangle->p1.y, triangle->p1.z, triangle->p2.x, triangle->p2.y, triangle->p2.z, triangle->p3.x, triangle->p3.y, triangle->p3.z );
		counter++;
		triangle = triangle->next;
	}
}
