#include "ai_game.h"

static unsigned int ai_next_random(ai_game_t *game)
{
    game->rng_state = game->rng_state * 1103515245u + 12345u;
    return game->rng_state;
}

static int ai_random_range(ai_game_t *game, int min, int max)
{
    unsigned int value = ai_next_random(game);
    int range = max - min + 1;

    if (range <= 0) {
        return min;
    }
    return min + (int)(value % (unsigned int)range);
}

position_t ai_step_random(ai_game_t *game, position_t from)
{
    position_t options[4];
    int count = 0;
    int index = 0;

    options[0] = ai_make_position(from.x + 1, from.y);
    options[1] = ai_make_position(from.x - 1, from.y);
    options[2] = ai_make_position(from.x, from.y + 1);
    options[3] = ai_make_position(from.x, from.y - 1);
    while (index < 4) {
        if (ai_is_walkable(options[index].x, options[index].y) == 1) {
            options[count] = options[index];
            count = count + 1;
        }
        index = index + 1;
    }
    if (count == 0) {
        return from;
    }
    return options[ai_random_range(game, 0, count - 1)];
}
