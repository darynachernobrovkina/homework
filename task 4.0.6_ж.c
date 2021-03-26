#include <stdio.h>
#include <stdlib.h>

struct Sphere{
    double x;
    double y;
    double z;
    double radius;
};

struct Sphere enter_sphere()
{
    struct Sphere sph;
    printf("Enter position (x, y, z ) - ");
    scanf("%lf %lf %lf", &sph.x, &sph.y, &sph.z);
    printf("Enter sphere radius - ");
    scanf("%lf", &sph.radius);
    //printf(sphere->x);
    return sph;
}

void display(struct Sphere sph)
{
    printf("\nPosition: %lf %lf %lf\n", sph.x, sph.y, sph.z);
    printf("Radius: %lf", sph.radius);
}

int main()
{
    struct Sphere sphere;
    sphere = enter_sphere();
    display(sphere);
    return 0;
}
