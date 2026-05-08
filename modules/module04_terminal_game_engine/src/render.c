#include <stdio.h>
#include "game_engine.h"

static char get_cell(game_t *game, int x, int y)
{
    position_t pos;

    pos.x = x;
    pos.y = y;
    if (game_is_wall(x, y) == 1) {
        return '#';
    }
    if (game_position_equals(pos, game->player) == 1) {
        return 'P';
    }
    if (game_position_equals(pos, game->enemy) == 1) {
        return 'E';
    }
    if (game_position_equals(pos, game->coin) == 1) {
        return '*';
    }
    return '.';
}

void game_render(game_t *game)
{
    int x = 0;
    int y = 0;

    if (game == 0) {
        return;
    }
    printf("\\nScore: %d | Lives: %d\\n", game->score, game->lives);
    y = 0;
    while (y < MAP_HEIGHT) {
        x = 0;
        while (x < MAP_WIDTH) {
            putchar(get_cell(game, x, y));
            x = x + 1;
        }
        putchar('\\n');
        y = y + 1;
    }
}
