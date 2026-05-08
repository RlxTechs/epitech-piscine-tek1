#include <stdio.h>
#include "ai_game.h"

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

void test_distance(void)
{
    position_t a = ai_make_position(2, 2);
    position_t b = ai_make_position(5, 6);

    printf("\\n=== distance tests ===\\n");
    assert_int_eq("abs positive", 5, ai_abs(5));
    assert_int_eq("abs negative", 5, ai_abs(-5));
    assert_int_eq("manhattan distance", 7, ai_distance(a, b));
}

void test_chase(void)
{
    ai_game_t game;
    int before = 0;
    int after = 0;

    printf("\\n=== chase tests ===\\n");
    ai_game_init(&game, AI_CHASE, 42);
    before = ai_distance(game.player, game.enemy.pos);
    ai_update(&game);
    after = ai_distance(game.player, game.enemy.pos);
    assert_int_eq("chase gets closer", 1, after < before);
}

void test_flee(void)
{
    ai_game_t game;
    int before = 0;
    int after = 0;

    printf("\\n=== flee tests ===\\n");
    ai_game_init(&game, AI_FLEE, 42);
    game.player = ai_make_position(10, 5);
    game.enemy.pos = ai_make_position(11, 5);
    before = ai_distance(game.player, game.enemy.pos);
    ai_update(&game);
    after = ai_distance(game.player, game.enemy.pos);
    assert_int_eq("flee goes away", 1, after > before);
}

void test_patrol(void)
{
    ai_game_t game;
    int old_x = 0;

    printf("\\n=== patrol tests ===\\n");
    ai_game_init(&game, AI_PATROL, 42);
    old_x = game.enemy.pos.x;
    ai_update(&game);
    assert_int_eq("patrol moves", 1, game.enemy.pos.x != old_x);
}

void test_random(void)
{
    ai_game_t game;

    printf("\\n=== random tests ===\\n");
    ai_game_init(&game, AI_RANDOM, 42);
    ai_update(&game);
    assert_int_eq("random inside x", 1, ai_is_inside(game.enemy.pos.x, game.enemy.pos.y));
    assert_int_eq("random walkable", 1, ai_is_walkable(game.enemy.pos.x, game.enemy.pos.y));
}

int main(void)
{
    test_distance();
    test_chase();
    test_flee();
    test_patrol();
    test_random();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
