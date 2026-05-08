#include "math_game.h"

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

int rects_collide(rect_t a, rect_t b)
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
