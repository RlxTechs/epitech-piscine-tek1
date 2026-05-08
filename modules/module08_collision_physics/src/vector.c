#include "physics.h"

vector2_t vec2(double x, double y)
{
    vector2_t result;

    result.x = x;
    result.y = y;
    return result;
}

vector2_t vec2_add(vector2_t a, vector2_t b)
{
    return vec2(a.x + b.x, a.y + b.y);
}

vector2_t vec2_sub(vector2_t a, vector2_t b)
{
    return vec2(a.x - b.x, a.y - b.y);
}

vector2_t vec2_scale(vector2_t v, double scale)
{
    return vec2(v.x * scale, v.y * scale);
}

double vec2_length_squared(vector2_t v)
{
    return v.x * v.x + v.y * v.y;
}

double clamp_double(double value, double min, double max)
{
    if (value < min) {
        return min;
    }
    if (value > max) {
        return max;
    }
    return value;
}
