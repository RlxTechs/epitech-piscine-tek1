#ifndef AI_GAME_H_
#define AI_GAME_H_

#define AI_WIDTH 18
#define AI_HEIGHT 10

typedef enum ai_mode_e {
    AI_CHASE,
    AI_FLEE,
    AI_PATROL,
    AI_RANDOM
} ai_mode_t;

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct enemy_s {
    position_t pos;
    ai_mode_t mode;
    int patrol_dir;
} enemy_t;

typedef struct ai_game_s {
    position_t player;
    enemy_t enemy;
    unsigned int rng_state;
    int turn;
} ai_game_t;

void ai_game_init(ai_game_t *game, ai_mode_t mode, unsigned int seed);
void ai_game_render(ai_game_t *game);
int ai_is_inside(int x, int y);
int ai_is_wall(int x, int y);
int ai_is_walkable(int x, int y);
int ai_abs(int value);
int ai_distance(position_t a, position_t b);
position_t ai_make_position(int x, int y);
position_t ai_step_towards(position_t from, position_t target);
position_t ai_step_away(position_t from, position_t threat);
position_t ai_step_patrol(enemy_t *enemy);
position_t ai_step_random(ai_game_t *game, position_t from);
position_t ai_choose_next(ai_game_t *game);
void ai_update(ai_game_t *game);
int ai_run_demo(void);

#endif
