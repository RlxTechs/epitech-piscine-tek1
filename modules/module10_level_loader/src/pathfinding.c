#include "level_loader.h"

typedef struct queue_s {
    position_t data[LEVEL_QUEUE_MAX];
    int start;
    int end;
} queue_t;

static void queue_init(queue_t *queue)
{
    queue->start = 0;
    queue->end = 0;
}

static int queue_empty(queue_t *queue)
{
    return queue->start == queue->end;
}

static int queue_push(queue_t *queue, position_t pos)
{
    if (queue->end >= LEVEL_QUEUE_MAX) {
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

static void visit(level_t *level, int visited[LEVEL_MAX_HEIGHT][LEVEL_MAX_WIDTH],
    queue_t *queue, int x, int y)
{
    position_t pos;

    if (level_is_inside(level, x, y) == 0) {
        return;
    }
    if (visited[y][x] == 1 || level_is_walkable(level, x, y) == 0) {
        return;
    }
    visited[y][x] = 1;
    pos.x = x;
    pos.y = y;
    queue_push(queue, pos);
}

int level_path_exists(level_t *level)
{
    int visited[LEVEL_MAX_HEIGHT][LEVEL_MAX_WIDTH];
    int y = 0;
    int x = 0;
    queue_t queue;
    position_t current;

    if (level == 0) {
        return 0;
    }
    while (y < LEVEL_MAX_HEIGHT) {
        x = 0;
        while (x < LEVEL_MAX_WIDTH) {
            visited[y][x] = 0;
            x = x + 1;
        }
        y = y + 1;
    }
    queue_init(&queue);
    visited[level->player.y][level->player.x] = 1;
    queue_push(&queue, level->player);
    while (queue_empty(&queue) == 0) {
        current = queue_pop(&queue);
        if (current.x == level->exit_pos.x && current.y == level->exit_pos.y) {
            return 1;
        }
        visit(level, visited, &queue, current.x + 1, current.y);
        visit(level, visited, &queue, current.x - 1, current.y);
        visit(level, visited, &queue, current.x, current.y + 1);
        visit(level, visited, &queue, current.x, current.y - 1);
    }
    return 0;
}
