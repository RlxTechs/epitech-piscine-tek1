#include "grid_game.h"

static const char *default_map[GRID_HEIGHT] = {
    "####################",
    "#P...#.............#",
    "#.##.#.####.#####..#",
    "#..#...#..#.....#..#",
    "##.#####..###.#.#..#",
    "#..*......#...#....#",
    "#.#######.#.#####.##",
    "#.......#.#.....*..#",
    "#..*....#.......X..#",
    "####################"
};

void grid_game_init(grid_game_t *game)
{
    int y = 0;
    int x = 0;

    if (game == 0) {
        return;
    }
    while (y < GRID_HEIGHT) {
        x = 0;
        while (x < GRID_WIDTH) {
            game->map[y][x] = default_map[y][x];
            x = x + 1;
        }
        game->map[y][GRID_WIDTH] = '\0';
        y = y + 1;
    }
    game->coins_collected = 0;
    game->moves = 0;
    game->running = 1;
    game->win = 0;
    grid_find_symbols(game);
}

int grid_is_inside(int x, int y)
{
    if (x < 0 || x >= GRID_WIDTH) {
        return 0;
    }
    if (y < 0 || y >= GRID_HEIGHT) {
        return 0;
    }
    return 1;
}

int grid_is_wall(grid_game_t *game, int x, int y)
{
    if (game == 0 || grid_is_inside(x, y) == 0) {
        return 1;
    }
    return game->map[y][x] == '#';
}

int grid_is_walkable(grid_game_t *game, int x, int y)
{
    if (grid_is_wall(game, x, y) == 1) {
        return 0;
    }
    return 1;
}

int grid_count_coins(grid_game_t *game)
{
    int y = 0;
    int x = 0;
    int count = 0;

    if (game == 0) {
        return 0;
    }
    while (y < GRID_HEIGHT) {
        x = 0;
        while (x < GRID_WIDTH) {
            if (game->map[y][x] == '*') {
                count = count + 1;
            }
            x = x + 1;
        }
        y = y + 1;
    }
    return count;
}

void grid_find_symbols(grid_game_t *game)
{
    int y = 0;
    int x = 0;

    if (game == 0) {
        return;
    }
    game->coins_total = 0;
    while (y < GRID_HEIGHT) {
        x = 0;
        while (x < GRID_WIDTH) {
            if (game->map[y][x] == 'P') {
                game->player.x = x;
                game->player.y = y;
            }
            if (game->map[y][x] == 'X') {
                game->exit_pos.x = x;
                game->exit_pos.y = y;
            }
            if (game->map[y][x] == '*') {
                game->coins_total = game->coins_total + 1;
            }
            x = x + 1;
        }
        y = y + 1;
    }
}
