#include <stdio.h>
#include <stdlib.h>
#include "game_engine.h"

int game_run_scripted(char *script)
{
    game_t game;
    int i = 0;

    game_init(&game, 42);
    printf("=== Scripted terminal game demo ===\\n");
    game_render(&game);
    while (script[i] != '\\0' && game.running == 1) {
        printf("\\nInput: %c\\n", script[i]);
        game_step(&game, script[i]);
        game_render(&game);
        i = i + 1;
    }
    printf("\\nFinal score: %d | Lives: %d\\n", game.score, game.lives);
    return 0;
}

int game_run_interactive(void)
{
    game_t game;
    char input[64];

    game_init(&game, 42);
    printf("=== RLX Terminal Game ===\\n");
    printf("Controls: w/a/s/d move, q quit\\n");
    while (game.running == 1) {
        game_render(&game);
        printf("Move> ");
        if (fgets(input, sizeof(input), stdin) == 0) {
            break;
        }
        game_step(&game, input[0]);
    }
    printf("Game over. Final score: %d\\n", game.score);
    return 0;
}
