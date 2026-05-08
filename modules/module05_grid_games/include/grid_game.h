#ifndef GRID_GAME_H_
#define GRID_GAME_H_

#define GRID_WIDTH 20
#define GRID_HEIGHT 10
#define GRID_MAX_QUEUE 256

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct grid_game_s {
    char map[GRID_HEIGHT][GRID_WIDTH + 1];
    position_t player;
    position_t exit_pos;
    int coins_total;
    int coins_collected;
    int moves;
    int running;
    int win;
} grid_game_t;

void grid_game_init(grid_game_t *game);
void grid_game_render(grid_game_t *game);
int grid_is_inside(int x, int y);
int grid_is_wall(grid_game_t *game, int x, int y);
int grid_is_walkable(grid_game_t *game, int x, int y);
int grid_count_coins(grid_game_t *game);
void grid_find_symbols(grid_game_t *game);
void grid_move_player(grid_game_t *game, int dx, int dy);
void grid_step(grid_game_t *game, char input);
int grid_run_interactive(void);
int grid_run_demo(char *script);
int grid_find_path_to_exit(grid_game_t *game);

#endif
