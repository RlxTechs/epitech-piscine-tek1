#include "grid_game.h"

static int is_exit(grid_game_t *game, int x, int y)
{
    return game->exit_pos.x == x && game->exit_pos.y == y;
}

static void check_win(grid_game_t *game)
{
    if (game->coins_collected >= game->coins_total
        && game->player.x == game->exit_pos.x
        && game->player.y == game->exit_pos.y) {
        game->win = 1;
        game->running = 0;
    }
}

void grid_move_player(grid_game_t *game, int dx, int dy)
{
    int next_x = 0;
    int next_y = 0;

    if (game == 0 || game->running == 0) {
        return;
    }
    next_x = game->player.x + dx;
    next_y = game->player.y + dy;
    if (grid_is_walkable(game, next_x, next_y) == 0) {
        return;
    }
    if (is_exit(game, game->player.x, game->player.y) == 1) {
        game->map[game->player.y][game->player.x] = 'X';
    } else {
        game->map[game->player.y][game->player.x] = '.';
    }
    if (game->map[next_y][next_x] == '*') {
        game->coins_collected = game->coins_collected + 1;
    }
    game->player.x = next_x;
    game->player.y = next_y;
    game->map[next_y][next_x] = 'P';
    game->moves = game->moves + 1;
    check_win(game);
}

void grid_step(grid_game_t *game, char input)
{
    if (game == 0 || game->running == 0) {
        return;
    }
    if (input == 'q') {
        game->running = 0;
        return;
    }
    if (input == 'w') {
        grid_move_player(game, 0, -1);
    } else if (input == 's') {
        grid_move_player(game, 0, 1);
    } else if (input == 'a') {
        grid_move_player(game, -1, 0);
    } else if (input == 'd') {
        grid_move_player(game, 1, 0);
    }
}
