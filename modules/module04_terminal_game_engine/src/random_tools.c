#include "game_engine.h"

static unsigned int next_random(game_t *game)
{
    game->rng_state = game->rng_state * 1103515245u + 12345u;
    return game->rng_state;
}

static int random_range(game_t *game, int min, int max)
{
    unsigned int value = next_random(game);
    int range = max - min + 1;

    if (range <= 0) {
        return min;
    }
    return min + (int)(value % (unsigned int)range);
}

void game_spawn_coin(game_t *game)
{
    int tries = 0;
    position_t candidate;

    while (tries < 200) {
        candidate.x = random_range(game, 1, MAP_WIDTH - 2);
        candidate.y = random_range(game, 1, MAP_HEIGHT - 2);
        if (game_is_wall(candidate.x, candidate.y) == 0
            && game_position_equals(candidate, game->player) == 0
            && game_position_equals(candidate, game->enemy) == 0) {
            game->coin = candidate;
            return;
        }
        tries = tries + 1;
    }
    game->coin.x = 1;
    game->coin.y = 1;
}
