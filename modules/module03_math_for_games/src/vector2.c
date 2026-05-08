#include <math.h>
#include "math_game.h"

vector2_t vector2_create(double x, double y)
{
    vector2_t result;

    result.x = x;
    result.y = y;
    return result;
}

vector2_t vector2_add(vector2_t a, vector2_t b)
{
    return vector2_create(a.x + b.x, a.y + b.y);
}

vector2_t vector2_sub(vector2_t a, vector2_t b)
{
    return vector2_create(a.x - b.x, a.y - b.y);
}

vector2_t vector2_scale(vector2_t v, double scale)
{
    return vector2_create(v.x * scale, v.y * scale);
}

double vector2_dot(vector2_t a, vector2_t b)
{
    return a.x * b.x + a.y * b.y;
}

double vector2_length(vector2_t v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

double vector2_distance(vector2_t a, vector2_t b)
{
    return vector2_length(vector2_sub(a, b));
}

vector2_t vector2_normalize(vector2_t v)
{
    double length = vector2_length(v);

    if (length == 0.0) {
        return vector2_create(0.0, 0.0);
    }
    return vector2_create(v.x / length, v.y / length);
}
