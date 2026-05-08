#include "ai_game.h"

int ai_abs(int value)
{
    if (value < 0) {
        return -value;
    }
    return value;
}

int ai_distance(position_t a, position_t b)
{
    return ai_abs(a.x - b.x) + ai_abs(a.y - b.y);
}

position_t ai_make_position(int x, int y)
{
    position_t pos;

    pos.x = x;
    pos.y = y;
    return pos;
}
