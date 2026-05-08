#include "ai_game.h"

int ai_is_inside(int x, int y)
{
    if (x < 0 || x >= AI_WIDTH) {
        return 0;
    }
    if (y < 0 || y >= AI_HEIGHT) {
        return 0;
    }
    return 1;
}

int ai_is_wall(int x, int y)
{
    if (ai_is_inside(x, y) == 0) {
        return 1;
    }
    if (x == 0 || y == 0 || x == AI_WIDTH - 1 || y == AI_HEIGHT - 1) {
        return 1;
    }
    if (x == 7 && y >= 2 && y <= 7) {
        return 1;
    }
    if (y == 4 && x >= 10 && x <= 14) {
        return 1;
    }
    return 0;
}

int ai_is_walkable(int x, int y)
{
    if (ai_is_wall(x, y) == 1) {
        return 0;
    }
    return 1;
}
