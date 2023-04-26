
#define _USE_MATH_DEFINES

#include "geometrysearch.h"

#include <math.h>

float circle_perimeter(float radius)
{
    return (2 * M_PI * radius);
}

float circle_area(float radius)
{
    return (M_PI * radius * radius);
}
