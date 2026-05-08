#include <stdio.h>
#include "snake.h"

int snake_run_demo(char *script)
{
    snake_game_t game;
    int i = 0;

    snake_init(&game, 42);
    printf("=== Snake scripted demo ===\\n");
    snake_render(&game);
    while (script[i] != '\0' && game.running == 1) {
        printf("\\nInput: %c\\n", script[i]);
        snake_step(&game, script[i]);
        snake_render(&game);
        i = i + 1;
    }
    printf("\\nFinal score: %d\\n", game.score);
    return 0;
}

int snake_run_interactive(void)
{
    snake_game_t game;
    char input[64];

    snake_init(&game, 42);
    printf("=== RLX Snake Terminal ===\\n");
    printf("Controls: w/a/s/d move, q quit. Press Enter after each move.\\n");
    while (game.running == 1) {
        snake_render(&game);
        printf("Move> ");
        if (fgets(input, sizeof(input), stdin) == 0) {
            break;
        }
        snake_step(&game, input[0]);
    }
    snake_render(&game);
    return 0;
}
