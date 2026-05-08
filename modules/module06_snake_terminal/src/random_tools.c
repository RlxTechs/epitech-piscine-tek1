#include "snake.h"

static unsigned int snake_next_random(snake_game_t *game)
{
    game->rng_state = game->rng_state * 1103515245u + 12345u;
    return game->rng_state;
}

static int snake_random_range(snake_game_t *game, int min, int max)
{
    unsigned int value = snake_next_random(game);
    int range = max - min + 1;

    if (range <= 0) {
        return min;
    }
    return min + (int)(value % (unsigned int)range);
}

void snake_spawn_food(snake_game_t *game)
{
    position_t candidate;
    int tries = 0;

    if (game == 0) {
        return;
    }
    while (tries < 500) {
        candidate.x = snake_random_range(game, 1, SNAKE_WIDTH - 2);
        candidate.y = snake_random_range(game, 1, SNAKE_HEIGHT - 2);
        if (snake_contains_position(game, candidate, 0, game->length) == 0) {
            game->food = candidate;
            return;
        }
        tries = tries + 1;
    }
    game->running = 0;
    game->win = 1;
}
