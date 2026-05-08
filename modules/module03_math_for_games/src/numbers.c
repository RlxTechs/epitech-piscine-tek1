#include "math_game.h"

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

double lerp(double start, double end, double t)
{
    return start + (end - start) * t;
}

double deg_to_rad(double degrees)
{
    return degrees * 3.14159265358979323846 / 180.0;
}

double rad_to_deg(double radians)
{
    return radians * 180.0 / 3.14159265358979323846;
}
