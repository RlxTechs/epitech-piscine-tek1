#include <stdio.h>
#include "level_loader.h"

void level_render(level_t *level)
{
    int y = 0;

    if (level == 0) {
        return;
    }
    printf("Level size: %dx%d\\n", level->width, level->height);
    printf("Player: (%d, %d) | Exit: (%d, %d) | Coins: %d\\n",
        level->player.x, level->player.y, level->exit_pos.x, level->exit_pos.y, level->coins);
    while (y < level->height) {
        printf("%s\\n", level->tiles[y]);
        y = y + 1;
    }
}

int level_demo(const char *path)
{
    level_t level;

    printf("=== RLX Level Loader Demo ===\\n");
    printf("Loading: %s\\n", path);
    if (level_load(&level, path) == 0) {
        printf("Load failed.\\n");
        return 1;
    }
    if (level_validate(&level) == 0) {
        printf("Level invalid.\\n");
        level_render(&level);
        return 1;
    }
    printf("Level valid.\\n");
    level_render(&level);
    printf("Path exists: %d\\n", level_path_exists(&level));
    return 0;
}
