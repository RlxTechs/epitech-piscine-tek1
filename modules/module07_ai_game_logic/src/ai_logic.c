#include "ai_game.h"

static position_t try_axis_move(position_t from, int dx, int dy)
{
    position_t next;

    next.x = from.x + dx;
    next.y = from.y + dy;
    if (ai_is_walkable(next.x, next.y) == 1) {
        return next;
    }
    return from;
}

position_t ai_step_towards(position_t from, position_t target)
{
    int dx = 0;
    int dy = 0;
    position_t next;

    if (target.x > from.x) {
        dx = 1;
    } else if (target.x < from.x) {
        dx = -1;
    }
    if (target.y > from.y) {
        dy = 1;
    } else if (target.y < from.y) {
        dy = -1;
    }
    next = try_axis_move(from, dx, 0);
    if (next.x != from.x || next.y != from.y) {
        return next;
    }
    return try_axis_move(from, 0, dy);
}

position_t ai_step_away(position_t from, position_t threat)
{
    int dx = 0;
    int dy = 0;
    position_t next;

    if (threat.x > from.x) {
        dx = -1;
    } else if (threat.x < from.x) {
        dx = 1;
    }
    if (threat.y > from.y) {
        dy = -1;
    } else if (threat.y < from.y) {
        dy = 1;
    }
    next = try_axis_move(from, dx, 0);
    if (next.x != from.x || next.y != from.y) {
        return next;
    }
    return try_axis_move(from, 0, dy);
}

position_t ai_step_patrol(enemy_t *enemy)
{
    position_t next;
    int dx = 0;

    if (enemy->patrol_dir == 0) {
        enemy->patrol_dir = 1;
    }
    dx = enemy->patrol_dir;
    next.x = enemy->pos.x + dx;
    next.y = enemy->pos.y;
    if (ai_is_walkable(next.x, next.y) == 0) {
        enemy->patrol_dir = enemy->patrol_dir * -1;
        next.x = enemy->pos.x + enemy->patrol_dir;
        next.y = enemy->pos.y;
    }
    if (ai_is_walkable(next.x, next.y) == 0) {
        return enemy->pos;
    }
    return next;
}

position_t ai_choose_next(ai_game_t *game)
{
    if (game->enemy.mode == AI_CHASE) {
        return ai_step_towards(game->enemy.pos, game->player);
    }
    if (game->enemy.mode == AI_FLEE) {
        return ai_step_away(game->enemy.pos, game->player);
    }
    if (game->enemy.mode == AI_PATROL) {
        return ai_step_patrol(&game->enemy);
    }
    return ai_step_random(game, game->enemy.pos);
}

void ai_update(ai_game_t *game)
{
    if (game == 0) {
        return;
    }
    game->enemy.pos = ai_choose_next(game);
    game->turn = game->turn + 1;
}
