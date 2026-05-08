#include "level_loader.h"

static int is_valid_symbol(char c)
{
    if (c == '#' || c == '.' || c == 'P' || c == '*' || c == 'X') {
        return 1;
    }
    return 0;
}

static int validate_symbols(level_t *level)
{
    int y = 0;
    int x = 0;

    while (y < level->height) {
        x = 0;
        while (x < level->width) {
            if (is_valid_symbol(level->tiles[y][x]) == 0) {
                return 0;
            }
            x = x + 1;
        }
        y = y + 1;
    }
    return 1;
}

static int validate_borders(level_t *level)
{
    int x = 0;
    int y = 0;

    while (x < level->width) {
        if (level->tiles[0][x] != '#' || level->tiles[level->height - 1][x] != '#') {
            return 0;
        }
        x = x + 1;
    }
    while (y < level->height) {
        if (level->tiles[y][0] != '#' || level->tiles[y][level->width - 1] != '#') {
            return 0;
        }
        y = y + 1;
    }
    return 1;
}

int level_validate(level_t *level)
{
    int players = 0;
    int exits = 0;

    if (level == 0 || level->width <= 0 || level->height <= 0) {
        return 0;
    }
    if (validate_symbols(level) == 0 || validate_borders(level) == 0) {
        return 0;
    }
    players = level_count_char(level, 'P');
    exits = level_count_char(level, 'X');
    level->coins = level_count_char(level, '*');
    if (players != 1 || exits != 1 || level->coins < 1) {
        return 0;
    }
    if (level_find_char(level, 'P', &level->player) == 0) {
        return 0;
    }
    if (level_find_char(level, 'X', &level->exit_pos) == 0) {
        return 0;
    }
    if (level_path_exists(level) == 0) {
        return 0;
    }
    return 1;
}
