#ifndef SNAKE_H_
#define SNAKE_H_

#define SNAKE_WIDTH 24
#define SNAKE_HEIGHT 14
#define SNAKE_MAX_CELLS 336

typedef enum direction_e {
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} direction_t;

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct snake_game_s {
    position_t body[SNAKE_MAX_CELLS];
    int length;
    direction_t direction;
    position_t food;
    int score;
    int running;
    int win;
    unsigned int rng_state;
} snake_game_t;

void snake_init(snake_game_t *game, unsigned int seed);
void snake_render(snake_game_t *game);
int snake_is_inside(int x, int y);
int snake_position_equals(position_t a, position_t b);
int snake_contains_position(snake_game_t *game, position_t pos, int start, int end);
void snake_spawn_food(snake_game_t *game);
void snake_change_direction(snake_game_t *game, char input);
void snake_step(snake_game_t *game, char input);
int snake_run_interactive(void);
int snake_run_demo(char *script);

#endif
