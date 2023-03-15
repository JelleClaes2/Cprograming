/*
  Define the functions:
  - struct point3D calculateNormal(struct triangle triangle);
  - struct point3D subtract(struct point3D p1, struct point3D p2);
  - float dotProduct(struct point3D p1, struct point3D p2);
  - struct point3D crossProduct(struct point3D p1, struct point3D p2);
*/
#include <stdio.h>

enum bool {TRUE, FALSE};

struct point3D
{
    float x, y, z;
};

struct vector
{
    struct point3D origin;
    struct point3D direction;
};

struct plane
{
    struct point3D point;
    struct point3D normal;
};

struct triangle
{
    struct point3D p1;
    struct point3D p2;
    struct point3D p3;
};

// Helper functions
struct point3D calculateNormal(struct triangle triangle);
struct point3D subtract(struct point3D p1, struct point3D p2);
float dotProduct(struct point3D p1, struct point3D p2);
struct point3D crossProduct(struct point3D p1, struct point3D p2);

// Intersection functions
enum bool rayPlaneIntersection(struct plane plane, struct vector ray);
enum bool rayTrianlgeIntersection(struct triangle triangle, struct vector ray);

int main( void )
{
    struct triangle triangle;
    printf("Give the coordinates of the triangle's vertices.\n");
    printf("p1 = ");
    (void) scanf("%f %f %f", &triangle.p1.x, &triangle.p1.y, &triangle.p1.z);
    printf("p2 = ");
    (void) scanf("%f %f %f", &triangle.p2.x, &triangle.p2.y, &triangle.p2.z);
    printf("p3 = ");
    (void) scanf("%f %f %f", &triangle.p3.x, &triangle.p3.y, &triangle.p3.z);

    struct vector ray;
    printf("Give the ray origin.\n");
    printf("origin = ");
    (void) scanf("%f %f %f", &ray.origin.x, &ray.origin.y, &ray.origin.z);

    printf("Give the ray direction\n");
    printf("direction = ");
    (void) scanf("%f %f %f", &ray.direction.x, &ray.direction.y, &ray.direction.z);

    struct plane plane = {triangle.p1, calculateNormal(triangle)};

    printf("%s\n", (rayPlaneIntersection(plane, ray) == FALSE) ? "No ray plane intersection" : "Ray plane intersection");
    printf("%s\n", (rayTrianlgeIntersection(triangle, ray) == FALSE) ? "No ray triangle intersection" : "Ray triangle intersection");

    return 0;
}

/*
  The normal of a triangle can be calculated as follows (x = cross product):
  (triangle point 1 - triangle point 2) x (triangle point 1 - triangle point 3)
*/
struct point3D calculateNormal(struct triangle triangle)
{
    struct point3D point1;
    point1.x = triangle.p1.x - triangle.p2.x;
    point1.y = triangle.p1.y - triangle.p2.y;
    point1.z = triangle.p1.z - triangle.p2.z;

    struct point3D point2;
    point2.x = triangle.p1.x - triangle.p3.x;
    point2.y = triangle.p1.y - triangle.p3.x;
    point2.z = triangle.p1.z - triangle.p3.z;

    struct point3D normal;
    normal.x = point1.y * point2.z - point1.z * point2.y;
    normal.y = point1.z * point2.x - point1.x * point2.z;
    normal.z = point1.x * point2.y - point1.y * point2.x;

    return normal;
}

/*
  Point p2 is subtracted from point p1.
*/
struct point3D subtract(struct point3D p1, struct point3D p2)
{
    struct point3D result;
    result.x = p1.x - p2.x;
    result.y = p1.y - p2.y;
    result.z = p1.z - p2.z;
    return result;
}

/*
  The dot product of two points (e.g. p1(x1, y1, z1) and p2(x2, y2, z2)) is the sum of the product of the x, y, z coordinates.
  x1*x2 + y1*y2 + z1*z2
*/
float dotProduct(struct point3D p1, struct point3D p2)
{
    float result = p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
    return result;
}

/*
 The cross product of two points (e.g. p1(x1, y1, z1) and p2(x2, y2, z2)) results in a new point (e.g. p(x, y, z)) and can be calculated as:
  x = y1*z2 - z1*y2
  y = z1*x2 - x1*z2
  z = x1*y2 - y1*x2
*/
struct point3D crossProduct(struct point3D p1, struct point3D p2)
{
    struct point3D result;
    result.x = p1.y*p2.z - p1.z*p2.y;
    result.y = p1.z*p2.x - p1.x*p2.z;
    result.z = p1.x*p2.y - p1.y*p2.x;
    return result;
}

/*
  d = (p0 - l0) . n / l.n

  p0 = point on plane
  n  = plane normal
  l0 = ray origin
  l  = ray direction

  Source = https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
*/
enum bool rayPlaneIntersection(struct plane plane, struct vector ray)
{
    float nom   = dotProduct(subtract(plane.point, ray.origin), plane.normal);
    float denom = dotProduct(ray.direction, plane.normal);

    if(denom != 0)
    {
        float d = nom / denom;
        return (d < 0) ? FALSE : TRUE;
    }
    else
        return (nom != 0) ? FALSE : TRUE;
}

/*
  Möller–Trumbore intersection algorithm

  Source = https://en.wikipedia.org/wiki/M%C3%B6ller%E2%80%93Trumbore_intersection_algorithm
*/
enum bool rayTrianlgeIntersection(struct triangle triangle, struct vector ray)
{
    const float EPSILON = 0.0000001;
    struct point3D vertex0 = triangle.p1;
    struct point3D vertex1 = triangle.p2;
    struct point3D vertex2 = triangle.p3;

    struct point3D edge1, edge2, h, s, q;
    float a,f,u,v;
    edge1 = subtract(vertex1, vertex2);
    edge2 = subtract(vertex2, vertex0);
    h = crossProduct(ray.direction, edge2);
    a = dotProduct(edge1, h);

    if (a > -EPSILON && a < EPSILON)
        return FALSE;    // This ray is parallel to this triangle.
    f = 1.0/a;
    s = subtract(ray.origin, vertex0);
    u = f * dotProduct(s, h);
    if (u < 0.0 || u > 1.0)
        return FALSE;
    q = crossProduct(s, edge1);
    v = f * dotProduct(ray.direction, q);
    if (v < 0.0 || u + v > 1.0)
        return FALSE;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * dotProduct(edge2, q);
    if (t > EPSILON) // ray intersection
    {
        return TRUE;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return FALSE;
}
