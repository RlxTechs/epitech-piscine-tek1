#include <stdio.h>
#include "ai_game.h"

static void run_mode(char *label, ai_mode_t mode)
{
    ai_game_t game;
    int i = 0;

    printf("\\n=== Mode %s ===\\n", label);
    ai_game_init(&game, mode, 42);
    ai_game_render(&game);
    while (i < 6) {
        ai_update(&game);
        ai_game_render(&game);
        i = i + 1;
    }
}

int ai_run_demo(void)
{
    printf("=== RLX AI Game Logic Demo ===\\n");
    run_mode("CHASE", AI_CHASE);
    run_mode("FLEE", AI_FLEE);
    run_mode("PATROL", AI_PATROL);
    run_mode("RANDOM", AI_RANDOM);
    return 0;
}
