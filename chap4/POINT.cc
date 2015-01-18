#include "POINT.h"

#include <stdlib.h>
#include <math.h>

POINT::POINT()
{
    x = 1.0 * rand() / RAND_MAX;
    y = 1.0 * rand() / RAND_MAX;
}

float POINT::distance(POINT a) const
{
    float dx = x - a.x, dy = y - a.y;
    return sqrt(dx * dx + dy * dy);
}
