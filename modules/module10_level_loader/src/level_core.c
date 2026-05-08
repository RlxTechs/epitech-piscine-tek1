#include "level_loader.h"

void level_clear(level_t *level)
{
    int y = 0;
    int x = 0;

    if (level == 0) {
        return;
    }
    level->width = 0;
    level->height = 0;
    level->player.x = 0;
    level->player.y = 0;
    level->exit_pos.x = 0;
    level->exit_pos.y = 0;
    level->coins = 0;
    while (y < LEVEL_MAX_HEIGHT) {
        x = 0;
        while (x <= LEVEL_MAX_WIDTH) {
            level->tiles[y][x] = '\0';
            x = x + 1;
        }
        y = y + 1;
    }
}

int level_is_inside(level_t *level, int x, int y)
{
    if (level == 0) {
        return 0;
    }
    if (x < 0 || x >= level->width) {
        return 0;
    }
    if (y < 0 || y >= level->height) {
        return 0;
    }
    return 1;
}

int level_is_wall(level_t *level, int x, int y)
{
    if (level_is_inside(level, x, y) == 0) {
        return 1;
    }
    return level->tiles[y][x] == '#';
}

int level_is_walkable(level_t *level, int x, int y)
{
    if (level_is_wall(level, x, y) == 1) {
        return 0;
    }
    return 1;
}

int level_count_char(level_t *level, char target)
{
    int y = 0;
    int x = 0;
    int count = 0;

    if (level == 0) {
        return 0;
    }
    while (y < level->height) {
        x = 0;
        while (x < level->width) {
            if (level->tiles[y][x] == target) {
                count = count + 1;
            }
            x = x + 1;
        }
        y = y + 1;
    }
    return count;
}

int level_find_char(level_t *level, char target, position_t *out)
{
    int y = 0;
    int x = 0;

    if (level == 0 || out == 0) {
        return 0;
    }
    while (y < level->height) {
        x = 0;
        while (x < level->width) {
            if (level->tiles[y][x] == target) {
                out->x = x;
                out->y = y;
                return 1;
            }
            x = x + 1;
        }
        y = y + 1;
    }
    return 0;
}
