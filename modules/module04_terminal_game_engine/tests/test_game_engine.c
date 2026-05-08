#include <stdio.h>
#include "game_engine.h"

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

void test_map(void)
{
    printf("\\n=== map tests ===\\n");
    assert_int_eq("inside 1 1", 1, game_is_inside(1, 1));
    assert_int_eq("outside -1 1", 0, game_is_inside(-1, 1));
    assert_int_eq("wall border", 1, game_is_wall(0, 0));
    assert_int_eq("not wall", 0, game_is_wall(2, 2));
}

void test_init(void)
{
    game_t game;

    printf("\\n=== init tests ===\\n");
    game_init(&game, 42);
    assert_int_eq("player x", 2, game.player.x);
    assert_int_eq("player y", 2, game.player.y);
    assert_int_eq("score", 0, game.score);
    assert_int_eq("lives", 3, game.lives);
    assert_int_eq("running", 1, game.running);
}

void test_movement(void)
{
    game_t game;

    printf("\\n=== movement tests ===\\n");
    game_init(&game, 42);
    game_move_player(&game, 1, 0);
    assert_int_eq("move right x", 3, game.player.x);
    assert_int_eq("move right y", 2, game.player.y);
    game_move_player(&game, -99, 0);
    assert_int_eq("blocked by wall", 3, game.player.x);
}

void test_coin(void)
{
    game_t game;

    printf("\\n=== coin tests ===\\n");
    game_init(&game, 42);
    game.coin.x = game.player.x + 1;
    game.coin.y = game.player.y;
    game_step(&game, 'd');
    assert_int_eq("score after coin", 10, game.score);
}

void test_quit(void)
{
    game_t game;

    printf("\\n=== quit tests ===\\n");
    game_init(&game, 42);
    game_step(&game, 'q');
    assert_int_eq("running after q", 0, game.running);
}

int main(void)
{
    test_map();
    test_init();
    test_movement();
    test_coin();
    test_quit();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
