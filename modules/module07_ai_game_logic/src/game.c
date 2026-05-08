#include <stdio.h>
#include "ai_game.h"

void ai_game_init(ai_game_t *game, ai_mode_t mode, unsigned int seed)
{
    if (game == 0) {
        return;
    }
    game->player = ai_make_position(2, 2);
    game->enemy.pos = ai_make_position(15, 7);
    game->enemy.mode = mode;
    game->enemy.patrol_dir = 1;
    game->rng_state = seed;
    game->turn = 0;
}

static char get_cell(ai_game_t *game, int x, int y)
{
    if (ai_is_wall(x, y) == 1) {
        return '#';
    }
    if (game->player.x == x && game->player.y == y) {
        return 'P';
    }
    if (game->enemy.pos.x == x && game->enemy.pos.y == y) {
        return 'E';
    }
    return '.';
}

void ai_game_render(ai_game_t *game)
{
    int x = 0;
    int y = 0;

    if (game == 0) {
        return;
    }
    printf("\\nTurn: %d | Distance: %d\\n", game->turn, ai_distance(game->player, game->enemy.pos));
    y = 0;
    while (y < AI_HEIGHT) {
        x = 0;
        while (x < AI_WIDTH) {
            putchar(get_cell(game, x, y));
            x = x + 1;
        }
        putchar('\n');
        y = y + 1;
    }
}
