#include <stdio.h>
#include "physics.h"

static int failures = 0;
static const double EPS = 0.0001;

static double abs_double(double value)
{
    if (value < 0.0) {
        return -value;
    }
    return value;
}

void assert_int_eq(char *name, int expected, int actual)
{
    if (expected == actual) {
        printf("[OK] %s expected=%d actual=%d\\n", name, expected, actual);
    } else {
        printf("[FAIL] %s expected=%d actual=%d\\n", name, expected, actual);
        failures = failures + 1;
    }
}

void assert_double_eq(char *name, double expected, double actual)
{
    if (abs_double(expected - actual) < EPS) {
        printf("[OK] %s expected=%.4f actual=%.4f\\n", name, expected, actual);
    } else {
        printf("[FAIL] %s expected=%.4f actual=%.4f\\n", name, expected, actual);
        failures = failures + 1;
    }
}

void test_vectors(void)
{
    vector2_t a = vec2(3.0, 4.0);
    vector2_t b = vec2(1.0, 2.0);
    vector2_t c;

    printf("\\n=== vector tests ===\\n");
    c = vec2_add(a, b);
    assert_double_eq("add x", 4.0, c.x);
    assert_double_eq("add y", 6.0, c.y);
    c = vec2_sub(a, b);
    assert_double_eq("sub x", 2.0, c.x);
    assert_double_eq("sub y", 2.0, c.y);
    c = vec2_scale(a, 2.0);
    assert_double_eq("scale x", 6.0, c.x);
    assert_double_eq("scale y", 8.0, c.y);
    assert_double_eq("length squared", 25.0, vec2_length_squared(a));
}

void test_collision(void)
{
    rect_t a = {0.0, 0.0, 10.0, 10.0};
    rect_t b = {5.0, 5.0, 10.0, 10.0};
    rect_t c = {30.0, 30.0, 5.0, 5.0};
    vector2_t p = vec2(2.0, 2.0);
    circle_t ca;
    circle_t cb;

    printf("\\n=== collision tests ===\\n");
    assert_int_eq("point in rect", 1, point_in_rect(p, a));
    assert_int_eq("rect overlap", 1, rects_overlap(a, b));
    assert_int_eq("rect no overlap", 0, rects_overlap(a, c));
    ca.center = vec2(0.0, 0.0);
    ca.radius = 5.0;
    cb.center = vec2(8.0, 0.0);
    cb.radius = 5.0;
    assert_int_eq("circles overlap", 1, circles_overlap(ca, cb));
    cb.center = vec2(20.0, 0.0);
    assert_int_eq("circles no overlap", 0, circles_overlap(ca, cb));
}

void test_body_update(void)
{
    body_t body;
    world_t world;

    printf("\\n=== body tests ===\\n");
    world.width = 100.0;
    world.height = 50.0;
    world.gravity = 10.0;
    body.position = vec2(0.0, 0.0);
    body.velocity = vec2(10.0, 0.0);
    body.acceleration = vec2(0.0, 0.0);
    body.width = 5.0;
    body.height = 5.0;
    body.bounce = 0.5;
    body_apply_gravity(&body, world);
    body_update(&body, 1.0);
    assert_double_eq("position x after update", 10.0, body.position.x);
    assert_double_eq("position y after gravity", 10.0, body.position.y);
    assert_double_eq("velocity y after gravity", 10.0, body.velocity.y);
}

void test_world_bounds(void)
{
    body_t body;
    world_t world;

    printf("\\n=== world bounds tests ===\\n");
    world.width = 100.0;
    world.height = 50.0;
    world.gravity = 0.0;
    body.position = vec2(98.0, 10.0);
    body.velocity = vec2(20.0, 0.0);
    body.acceleration = vec2(0.0, 0.0);
    body.width = 5.0;
    body.height = 5.0;
    body.bounce = 0.5;
    body_resolve_world_bounds(&body, world);
    assert_double_eq("x clamped right", 95.0, body.position.x);
    assert_double_eq("velocity reversed", -10.0, body.velocity.x);
}

int main(void)
{
    test_vectors();
    test_collision();
    test_body_update();
    test_world_bounds();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
