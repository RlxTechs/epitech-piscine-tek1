#include "snake.h"

static position_t get_next_head(snake_game_t *game)
{
    position_t head = game->body[0];

    if (game->direction == DIR_UP) {
        head.y = head.y - 1;
    } else if (game->direction == DIR_DOWN) {
        head.y = head.y + 1;
    } else if (game->direction == DIR_LEFT) {
        head.x = head.x - 1;
    } else if (game->direction == DIR_RIGHT) {
        head.x = head.x + 1;
    }
    return head;
}

void snake_change_direction(snake_game_t *game, char input)
{
    if (game == 0) {
        return;
    }
    if (input == 'w' && game->direction != DIR_DOWN) {
        game->direction = DIR_UP;
    } else if (input == 's' && game->direction != DIR_UP) {
        game->direction = DIR_DOWN;
    } else if (input == 'a' && game->direction != DIR_RIGHT) {
        game->direction = DIR_LEFT;
    } else if (input == 'd' && game->direction != DIR_LEFT) {
        game->direction = DIR_RIGHT;
    }
}

static void shift_body(snake_game_t *game, int new_length)
{
    int i = new_length - 1;

    while (i > 0) {
        game->body[i] = game->body[i - 1];
        i = i - 1;
    }
}

void snake_step(snake_game_t *game, char input)
{
    position_t next;
    int grow = 0;
    int collision_end = 0;

    if (game == 0 || game->running == 0) {
        return;
    }
    if (input == 'q') {
        game->running = 0;
        return;
    }
    snake_change_direction(game, input);
    next = get_next_head(game);
    if (snake_is_inside(next.x, next.y) == 0) {
        game->running = 0;
        game->win = 0;
        return;
    }
    grow = snake_position_equals(next, game->food);
    collision_end = game->length;
    if (grow == 0) {
        collision_end = game->length - 1;
    }
    if (snake_contains_position(game, next, 0, collision_end) == 1) {
        game->running = 0;
        game->win = 0;
        return;
    }
    if (grow == 1 && game->length < SNAKE_MAX_CELLS) {
        game->length = game->length + 1;
        game->score = game->score + 10;
    }
    shift_body(game, game->length);
    game->body[0] = next;
    if (grow == 1) {
        snake_spawn_food(game);
    }
}
