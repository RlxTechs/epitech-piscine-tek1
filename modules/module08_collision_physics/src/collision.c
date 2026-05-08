#include "physics.h"

int point_in_rect(vector2_t point, rect_t rect)
{
    if (point.x < rect.x) {
        return 0;
    }
    if (point.x > rect.x + rect.width) {
        return 0;
    }
    if (point.y < rect.y) {
        return 0;
    }
    if (point.y > rect.y + rect.height) {
        return 0;
    }
    return 1;
}

int rects_overlap(rect_t a, rect_t b)
{
    if (a.x + a.width < b.x) {
        return 0;
    }
    if (b.x + b.width < a.x) {
        return 0;
    }
    if (a.y + a.height < b.y) {
        return 0;
    }
    if (b.y + b.height < a.y) {
        return 0;
    }
    return 1;
}

int circles_overlap(circle_t a, circle_t b)
{
    vector2_t diff = vec2_sub(a.center, b.center);
    double radius_sum = a.radius + b.radius;

    return vec2_length_squared(diff) <= radius_sum * radius_sum;
}

int body_collides(body_t a, body_t b)
{
    return rects_overlap(body_get_rect(a), body_get_rect(b));
}
