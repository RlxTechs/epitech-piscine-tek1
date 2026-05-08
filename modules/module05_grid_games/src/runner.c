#include <stdio.h>
#include "grid_game.h"

int grid_run_demo(char *script)
{
    grid_game_t game;
    int i = 0;

    grid_game_init(&game);
    printf("=== Grid game demo ===\\n");
    grid_game_render(&game);
    while (script[i] != '\0' && game.running == 1) {
        printf("\\nInput: %c\\n", script[i]);
        grid_step(&game, script[i]);
        grid_game_render(&game);
        i = i + 1;
    }
    printf("\\nPath to exit available: %d\\n", grid_find_path_to_exit(&game));
    return 0;
}

int grid_run_interactive(void)
{
    grid_game_t game;
    char input[64];

    grid_game_init(&game);
    printf("=== RLX Grid Game ===\\n");
    printf("Controls: w/a/s/d move, q quit. Collect all coins then reach X.\\n");
    while (game.running == 1) {
        grid_game_render(&game);
        printf("Move> ");
        if (fgets(input, sizeof(input), stdin) == 0) {
            break;
        }
        grid_step(&game, input[0]);
    }
    grid_game_render(&game);
    return 0;
}
