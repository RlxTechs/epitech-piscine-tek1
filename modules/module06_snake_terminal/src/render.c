#include <stdio.h>
#include "snake.h"

static char get_cell(snake_game_t *game, int x, int y)
{
    position_t pos;

    pos.x = x;
    pos.y = y;
    if (x == 0 || y == 0 || x == SNAKE_WIDTH - 1 || y == SNAKE_HEIGHT - 1) {
        return '#';
    }
    if (snake_position_equals(pos, game->body[0]) == 1) {
        return 'O';
    }
    if (snake_contains_position(game, pos, 1, game->length) == 1) {
        return 'o';
    }
    if (snake_position_equals(pos, game->food) == 1) {
        return '*';
    }
    return '.';
}

void snake_render(snake_game_t *game)
{
    int x = 0;
    int y = 0;

    if (game == 0) {
        return;
    }
    printf("\\nScore: %d | Length: %d\\n", game->score, game->length);
    y = 0;
    while (y < SNAKE_HEIGHT) {
        x = 0;
        while (x < SNAKE_WIDTH) {
            putchar(get_cell(game, x, y));
            x = x + 1;
        }
        putchar('\n');
        y = y + 1;
    }
    if (game->running == 0 && game->win == 0) {
        printf("Game over.\\n");
    }
    if (game->win == 1) {
        printf("Victory.\\n");
    }
}
