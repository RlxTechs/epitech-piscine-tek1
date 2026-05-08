#ifndef LEVEL_LOADER_H_
#define LEVEL_LOADER_H_

#define LEVEL_MAX_WIDTH 40
#define LEVEL_MAX_HEIGHT 20
#define LEVEL_QUEUE_MAX 800

typedef struct position_s {
    int x;
    int y;
} position_t;

typedef struct level_s {
    char tiles[LEVEL_MAX_HEIGHT][LEVEL_MAX_WIDTH + 1];
    int width;
    int height;
    position_t player;
    position_t exit_pos;
    int coins;
} level_t;

void level_clear(level_t *level);
int level_load(level_t *level, const char *path);
int level_validate(level_t *level);
int level_is_inside(level_t *level, int x, int y);
int level_is_wall(level_t *level, int x, int y);
int level_is_walkable(level_t *level, int x, int y);
int level_count_char(level_t *level, char target);
int level_find_char(level_t *level, char target, position_t *out);
int level_path_exists(level_t *level);
void level_render(level_t *level);
int level_demo(const char *path);

#endif
