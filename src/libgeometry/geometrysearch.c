
#define _USE_MATH_DEFINES

#include "geometrysearch.h"

#include <math.h>

float circle_perimeter(float radius)
{
    if (radius > 0)
        return (2 * M_PI * radius);

    return 0;
}

float circle_area(float radius)
{
    if (radius > 0)
        return (M_PI * radius * radius);

    return 0;
}
