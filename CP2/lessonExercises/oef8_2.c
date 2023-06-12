#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct point3D
{
    float x, y, z;
};

int compare_euclidean(const void* a, const void* b)
{
    struct point3D* pointA = (struct point3D*)a;
    struct point3D* pointB = (struct point3D*)b;

    float distanceA = sqrt(pow(pointA->x, 2) + pow(pointA->y, 2) + pow(pointA->z, 2));
    float distanceB = sqrt(pow(pointB->x, 2) + pow(pointB->y, 2) + pow(pointB->z, 2));

    if (distanceA < distanceB)
        return -1;
    else if (distanceA > distanceB)
        return 1;
    else
        return 0;
}

int compare_manhattan(const void* a, const void* b)
{
    struct point3D* pointA = (struct point3D*)a;
    struct point3D* pointB = (struct point3D*)b;

    float distanceA = fabs(pointA->x) + fabs(pointA->y) + fabs(pointA->z);
    float distanceB = fabs(pointB->x) + fabs(pointB->y) + fabs(pointB->z);

    if (distanceA < distanceB)
        return -1;
    else if (distanceA > distanceB)
        return 1;
    else
        return 0;
}

int main()
{
    srand(time(NULL));

    struct point3D points[100];

    // Generate random points
    for (int i = 0; i < 100; i++)
    {
        points[i].x = (float)rand();
        points[i].y = (float)rand();
        points[i].z = (float)rand();
    }

    // Choose a random point as the origin
    struct point3D origin = points[rand() % 100];

    // Sort the points by Euclidean distance
    qsort(points, 100, sizeof(struct point3D), compare_euclidean);

    // Sort the points by Manhattan distance
    qsort(points, 100, sizeof(struct point3D), compare_manhattan);

    // Print the sorted points
    for (int i = 0; i < 100; i++)
    {
        printf("Point %d: x=%.2f, y=%.2f, z=%.2f\n", i+1, points[i].x, points[i].y, points[i].z);
    }

    return 0;
}
