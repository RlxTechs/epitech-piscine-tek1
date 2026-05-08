#include <stdio.h>
#include "grid_game.h"

static int failures = 0;

void assert_int_eq(char *name, int expected, int actual)
{
    if (expected == actual) {
        printf("[OK] %s expected=%d actual=%d\\n", name, expected, actual);
    } else {
        printf("[FAIL] %s expected=%d actual=%d\\n", name, expected, actual);
        failures = failures + 1;
    }
}

void test_init(void)
{
    grid_game_t game;

    printf("\\n=== init tests ===\\n");
    grid_game_init(&game);
    assert_int_eq("running", 1, game.running);
    assert_int_eq("coins total", 3, game.coins_total);
    assert_int_eq("player x", 1, game.player.x);
    assert_int_eq("player y", 1, game.player.y);
}

void test_map(void)
{
    grid_game_t game;

    printf("\\n=== map tests ===\\n");
    grid_game_init(&game);
    assert_int_eq("inside", 1, grid_is_inside(1, 1));
    assert_int_eq("outside", 0, grid_is_inside(-1, 1));
    assert_int_eq("wall border", 1, grid_is_wall(&game, 0, 0));
    assert_int_eq("walkable player", 1, grid_is_walkable(&game, 1, 1));
}

void test_movement(void)
{
    grid_game_t game;

    printf("\\n=== movement tests ===\\n");
    grid_game_init(&game);
    grid_move_player(&game, 1, 0);
    assert_int_eq("move right x", 2, game.player.x);
    assert_int_eq("move right y", 1, game.player.y);
    grid_move_player(&game, -99, 0);
    assert_int_eq("blocked by wall/outside", 2, game.player.x);
}

void test_coin_and_path(void)
{
    grid_game_t game;

    printf("\\n=== coin and path tests ===\\n");
    grid_game_init(&game);
    game.map[1][2] = '*';
    game.coins_total = grid_count_coins(&game);
    grid_step(&game, 'd');
    assert_int_eq("coin collected", 1, game.coins_collected);
    assert_int_eq("path to exit exists", 1, grid_find_path_to_exit(&game));
}

int main(void)
{
    test_init();
    test_map();
    test_movement();
    test_coin_and_path();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
