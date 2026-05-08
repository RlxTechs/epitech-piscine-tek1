#include <stdio.h>
#include "grid_game.h"

void grid_game_render(grid_game_t *game)
{
    int y = 0;

    if (game == 0) {
        return;
    }
    printf("\\nMoves: %d | Coins: %d/%d\\n", game->moves, game->coins_collected, game->coins_total);
    while (y < GRID_HEIGHT) {
        printf("%s\\n", game->map[y]);
        y = y + 1;
    }
    if (game->win == 1) {
        printf("Victory!\\n");
    }
}
