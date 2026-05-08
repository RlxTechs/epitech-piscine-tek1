#include "grid_game.h"

typedef struct queue_s {
    position_t data[GRID_MAX_QUEUE];
    int start;
    int end;
} queue_t;

static void queue_init(queue_t *queue)
{
    queue->start = 0;
    queue->end = 0;
}

static int queue_is_empty(queue_t *queue)
{
    return queue->start == queue->end;
}

static int queue_push(queue_t *queue, position_t pos)
{
    if (queue->end >= GRID_MAX_QUEUE) {
        return 0;
    }
    queue->data[queue->end] = pos;
    queue->end = queue->end + 1;
    return 1;
}

static position_t queue_pop(queue_t *queue)
{
    position_t result = queue->data[queue->start];

    queue->start = queue->start + 1;
    return result;
}

static void visit_neighbor(grid_game_t *game, int visited[GRID_HEIGHT][GRID_WIDTH],
    queue_t *queue, int x, int y)
{
    position_t pos;

    if (grid_is_inside(x, y) == 0) {
        return;
    }
    if (visited[y][x] == 1 || grid_is_walkable(game, x, y) == 0) {
        return;
    }
    visited[y][x] = 1;
    pos.x = x;
    pos.y = y;
    queue_push(queue, pos);
}

int grid_find_path_to_exit(grid_game_t *game)
{
    int visited[GRID_HEIGHT][GRID_WIDTH];
    int y = 0;
    int x = 0;
    queue_t queue;
    position_t current;

    if (game == 0) {
        return 0;
    }
    while (y < GRID_HEIGHT) {
        x = 0;
        while (x < GRID_WIDTH) {
            visited[y][x] = 0;
            x = x + 1;
        }
        y = y + 1;
    }
    queue_init(&queue);
    visited[game->player.y][game->player.x] = 1;
    queue_push(&queue, game->player);
    while (queue_is_empty(&queue) == 0) {
        current = queue_pop(&queue);
        if (current.x == game->exit_pos.x && current.y == game->exit_pos.y) {
            return 1;
        }
        visit_neighbor(game, visited, &queue, current.x + 1, current.y);
        visit_neighbor(game, visited, &queue, current.x - 1, current.y);
        visit_neighbor(game, visited, &queue, current.x, current.y + 1);
        visit_neighbor(game, visited, &queue, current.x, current.y - 1);
    }
    return 0;
}
