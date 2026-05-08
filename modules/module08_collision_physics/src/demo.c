#include <stdio.h>
#include "physics.h"

static void print_body(int frame, body_t body)
{
    printf("frame=%02d pos=(%.2f, %.2f) vel=(%.2f, %.2f)\\n",
        frame, body.position.x, body.position.y, body.velocity.x, body.velocity.y);
}

int physics_run_demo(void)
{
    world_t world;
    body_t ball;
    body_t wall;
    int frame = 0;

    world.width = 80.0;
    world.height = 30.0;
    world.gravity = 9.8;

    ball.position = vec2(5.0, 2.0);
    ball.velocity = vec2(12.0, 0.0);
    ball.acceleration = vec2(0.0, 0.0);
    ball.width = 2.0;
    ball.height = 2.0;
    ball.bounce = 0.75;

    wall.position = vec2(40.0, 20.0);
    wall.velocity = vec2(0.0, 0.0);
    wall.acceleration = vec2(0.0, 0.0);
    wall.width = 8.0;
    wall.height = 4.0;
    wall.bounce = 0.0;

    printf("=== RLX Collision Physics Demo ===\\n");
    while (frame < 12) {
        body_apply_gravity(&ball, world);
        body_update(&ball, 0.16);
        body_resolve_world_bounds(&ball, world);
        print_body(frame, ball);
        if (body_collides(ball, wall) == 1) {
            printf("collision with wall at frame %d\\n", frame);
        }
        frame = frame + 1;
    }
    return 0;
}
