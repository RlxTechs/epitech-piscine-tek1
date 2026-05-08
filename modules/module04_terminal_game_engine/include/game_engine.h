#ifndef GAME_ENGINE_H_
#define GAME_ENGINE_H_

#define MAP_WIDTH 20
#define MAP_HEIGHT 10

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct game_s {
    position_t player;
    position_t enemy;
    position_t coin;
    int score;
    int lives;
    int running;
    unsigned int rng_state;
} game_t;

void game_init(game_t *game, unsigned int seed);
void game_render(game_t *game);
int game_is_inside(int x, int y);
int game_is_wall(int x, int y);
int game_position_equals(position_t a, position_t b);
void game_move_player(game_t *game, int dx, int dy);
void game_move_enemy(game_t *game);
void game_spawn_coin(game_t *game);
void game_step(game_t *game, char input);
int game_run_interactive(void);
int game_run_scripted(char *script);

#endif
