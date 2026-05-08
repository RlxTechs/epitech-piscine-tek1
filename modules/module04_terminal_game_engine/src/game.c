#include "game_engine.h"

void game_init(game_t *game, unsigned int seed)
{
    if (game == 0) {
        return;
    }
    game->player.x = 2;
    game->player.y = 2;
    game->enemy.x = MAP_WIDTH - 3;
    game->enemy.y = MAP_HEIGHT - 3;
    game->coin.x = 5;
    game->coin.y = 5;
    game->score = 0;
    game->lives = 3;
    game->running = 1;
    game->rng_state = seed;
    game_spawn_coin(game);
}

void game_move_player(game_t *game, int dx, int dy)
{
    int next_x = 0;
    int next_y = 0;

    if (game == 0 || game->running == 0) {
        return;
    }
    next_x = game->player.x + dx;
    next_y = game->player.y + dy;
    if (game_is_wall(next_x, next_y) == 0) {
        game->player.x = next_x;
        game->player.y = next_y;
    }
}

void game_move_enemy(game_t *game)
{
    int dx = 0;
    int dy = 0;
    int next_x = 0;
    int next_y = 0;

    if (game == 0 || game->running == 0) {
        return;
    }
    if (game->player.x > game->enemy.x) {
        dx = 1;
    } else if (game->player.x < game->enemy.x) {
        dx = -1;
    }
    if (game->player.y > game->enemy.y) {
        dy = 1;
    } else if (game->player.y < game->enemy.y) {
        dy = -1;
    }
    next_x = game->enemy.x + dx;
    next_y = game->enemy.y;
    if (game_is_wall(next_x, next_y) == 0) {
        game->enemy.x = next_x;
    } else {
        next_x = game->enemy.x;
    }
    next_y = game->enemy.y + dy;
    if (game_is_wall(game->enemy.x, next_y) == 0) {
        game->enemy.y = next_y;
    }
}

static void check_coin(game_t *game)
{
    if (game_position_equals(game->player, game->coin) == 1) {
        game->score = game->score + 10;
        game_spawn_coin(game);
    }
}

static void check_enemy(game_t *game)
{
    if (game_position_equals(game->player, game->enemy) == 1) {
        game->lives = game->lives - 1;
        game->player.x = 2;
        game->player.y = 2;
        game->enemy.x = MAP_WIDTH - 3;
        game->enemy.y = MAP_HEIGHT - 3;
        if (game->lives <= 0) {
            game->running = 0;
        }
    }
}

void game_step(game_t *game, char input)
{
    if (game == 0 || game->running == 0) {
        return;
    }
    if (input == 'q') {
        game->running = 0;
        return;
    }
    if (input == 'w') {
        game_move_player(game, 0, -1);
    } else if (input == 's') {
        game_move_player(game, 0, 1);
    } else if (input == 'a') {
        game_move_player(game, -1, 0);
    } else if (input == 'd') {
        game_move_player(game, 1, 0);
    }
    check_coin(game);
    game_move_enemy(game);
    check_enemy(game);
}


