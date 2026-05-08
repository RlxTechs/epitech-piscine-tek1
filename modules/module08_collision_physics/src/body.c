#include "physics.h"

rect_t body_get_rect(body_t body)
{
    rect_t rect;

    rect.x = body.position.x;
    rect.y = body.position.y;
    rect.width = body.width;
    rect.height = body.height;
    return rect;
}

void body_apply_gravity(body_t *body, world_t world)
{
    if (body == 0) {
        return;
    }
    body->acceleration.y = body->acceleration.y + world.gravity;
}

void body_update(body_t *body, double delta_time)
{
    if (body == 0) {
        return;
    }
    body->velocity.x = body->velocity.x + body->acceleration.x * delta_time;
    body->velocity.y = body->velocity.y + body->acceleration.y * delta_time;
    body->position.x = body->position.x + body->velocity.x * delta_time;
    body->position.y = body->position.y + body->velocity.y * delta_time;
    body->acceleration.x = 0.0;
    body->acceleration.y = 0.0;
}

void body_resolve_world_bounds(body_t *body, world_t world)
{
    if (body == 0) {
        return;
    }
    if (body->position.x < 0.0) {
        body->position.x = 0.0;
        body->velocity.x = -body->velocity.x * body->bounce;
    }
    if (body->position.x + body->width > world.width) {
        body->position.x = world.width - body->width;
        body->velocity.x = -body->velocity.x * body->bounce;
    }
    if (body->position.y < 0.0) {
        body->position.y = 0.0;
        body->velocity.y = -body->velocity.y * body->bounce;
    }
    if (body->position.y + body->height > world.height) {
        body->position.y = world.height - body->height;
        body->velocity.y = -body->velocity.y * body->bounce;
    }
}
