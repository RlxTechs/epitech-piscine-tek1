#include "snake.h"

int snake_is_inside(int x, int y)
{
    if (x <= 0 || x >= SNAKE_WIDTH - 1) {
        return 0;
    }
    if (y <= 0 || y >= SNAKE_HEIGHT - 1) {
        return 0;
    }
    return 1;
}

int snake_position_equals(position_t a, position_t b)
{
    return a.x == b.x && a.y == b.y;
}

int snake_contains_position(snake_game_t *game, position_t pos, int start, int end)
{
    int i = start;

    if (game == 0) {
        return 0;
    }
    if (start < 0) {
        start = 0;
    }
    if (end > game->length) {
        end = game->length;
    }
    i = start;
    while (i < end) {
        if (snake_position_equals(game->body[i], pos) == 1) {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

void snake_init(snake_game_t *game, unsigned int seed)
{
    if (game == 0) {
        return;
    }
    game->length = 3;
    game->body[0].x = 5;
    game->body[0].y = 5;
    game->body[1].x = 4;
    game->body[1].y = 5;
    game->body[2].x = 3;
    game->body[2].y = 5;
    game->direction = DIR_RIGHT;
    game->score = 0;
    game->running = 1;
    game->win = 0;
    game->rng_state = seed;
    snake_spawn_food(game);
}
