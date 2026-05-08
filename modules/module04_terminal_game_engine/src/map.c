#include "game_engine.h"

int game_is_inside(int x, int y)
{
    if (x < 0 || x >= MAP_WIDTH) {
        return 0;
    }
    if (y < 0 || y >= MAP_HEIGHT) {
        return 0;
    }
    return 1;
}

int game_is_wall(int x, int y)
{
    if (game_is_inside(x, y) == 0) {
        return 1;
    }
    if (x == 0 || y == 0 || x == MAP_WIDTH - 1 || y == MAP_HEIGHT - 1) {
        return 1;
    }
    if (x == 8 && y >= 2 && y <= 7 && y != 5) {
        return 1;
    }
    if (y == 4 && x >= 11 && x <= 16) {
        return 1;
    }
    return 0;
}

int game_position_equals(position_t a, position_t b)
{
    return a.x == b.x && a.y == b.y;
}
