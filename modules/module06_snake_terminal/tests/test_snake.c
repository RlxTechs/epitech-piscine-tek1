#include <stdio.h>
#include "snake.h"

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
    snake_game_t game;

    printf("\\n=== init tests ===\\n");
    snake_init(&game, 42);
    assert_int_eq("length", 3, game.length);
    assert_int_eq("score", 0, game.score);
    assert_int_eq("running", 1, game.running);
    assert_int_eq("head x", 5, game.body[0].x);
    assert_int_eq("head y", 5, game.body[0].y);
}

void test_movement(void)
{
    snake_game_t game;

    printf("\\n=== movement tests ===\\n");
    snake_init(&game, 42);
    snake_step(&game, 'd');
    assert_int_eq("move right x", 6, game.body[0].x);
    assert_int_eq("move right y", 5, game.body[0].y);
    snake_step(&game, 'a');
    assert_int_eq("no direct reverse x", 7, game.body[0].x);
}

void test_food_growth(void)
{
    snake_game_t game;

    printf("\\n=== food tests ===\\n");
    snake_init(&game, 42);
    game.food.x = 6;
    game.food.y = 5;
    snake_step(&game, 'd');
    assert_int_eq("score after food", 10, game.score);
    assert_int_eq("length after food", 4, game.length);
}

void test_wall_collision(void)
{
    snake_game_t game;

    printf("\\n=== wall collision tests ===\\n");
    snake_init(&game, 42);
    game.body[0].x = SNAKE_WIDTH - 2;
    game.body[0].y = 5;
    game.direction = DIR_RIGHT;
    snake_step(&game, 'd');
    assert_int_eq("running after wall", 0, game.running);
}

void test_body_collision(void)
{
    snake_game_t game;

    printf("\\n=== body collision tests ===\\n");
    snake_init(&game, 42);
    game.length = 4;
    game.body[0].x = 5;
    game.body[0].y = 5;
    game.body[1].x = 5;
    game.body[1].y = 6;
    game.body[2].x = 4;
    game.body[2].y = 6;
    game.body[3].x = 4;
    game.body[3].y = 5;
    game.direction = DIR_DOWN;
    snake_step(&game, 's');
    assert_int_eq("running after body collision", 0, game.running);
}

int main(void)
{
    test_init();
    test_movement();
    test_food_growth();
    test_wall_collision();
    test_body_collision();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
