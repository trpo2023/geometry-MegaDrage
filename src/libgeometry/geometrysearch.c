
#define _USE_MATH_DEFINES

#include <math.h>

float count_perimeter(float radius)
{
    return (2 * M_PI * radius);
}

float count_area(float radius)
{
    return (M_PI * radius * radius);
}