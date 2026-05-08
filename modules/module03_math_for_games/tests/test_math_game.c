#include <stdio.h>
#include <math.h>
#include "math_game.h"

static int failures = 0;
static const double EPSILON = 0.0001;

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
    if (fabs(expected - actual) < EPSILON) {
        printf("[OK] %s expected=%.4f actual=%.4f\\n", name, expected, actual);
    } else {
        printf("[FAIL] %s expected=%.4f actual=%.4f\\n", name, expected, actual);
        failures = failures + 1;
    }
}

void test_numbers(void)
{
    printf("\\n=== number tests ===\\n");
    assert_double_eq("clamp low", 0.0, clamp_double(-5.0, 0.0, 10.0));
    assert_double_eq("clamp high", 10.0, clamp_double(25.0, 0.0, 10.0));
    assert_double_eq("clamp middle", 5.0, clamp_double(5.0, 0.0, 10.0));
    assert_double_eq("lerp middle", 50.0, lerp(0.0, 100.0, 0.5));
    assert_double_eq("deg to rad 180", 3.1415926535, deg_to_rad(180.0));
    assert_double_eq("rad to deg pi", 180.0, rad_to_deg(3.14159265358979323846));
}

void test_vectors(void)
{
    vector2_t a = vector2_create(3.0, 4.0);
    vector2_t b = vector2_create(1.0, 2.0);
    vector2_t c = vector2_add(a, b);
    vector2_t n = vector2_normalize(a);

    printf("\\n=== vector tests ===\\n");
    assert_double_eq("vector add x", 4.0, c.x);
    assert_double_eq("vector add y", 6.0, c.y);
    assert_double_eq("vector length 3/4", 5.0, vector2_length(a));
    assert_double_eq("vector dot", 11.0, vector2_dot(a, b));
    assert_double_eq("vector normalize x", 0.6, n.x);
    assert_double_eq("vector normalize y", 0.8, n.y);
    assert_double_eq("vector distance", sqrt(8.0), vector2_distance(a, b));
}

void test_collisions(void)
{
    rect_t a = {0.0, 0.0, 10.0, 10.0};
    rect_t b = {5.0, 5.0, 10.0, 10.0};
    rect_t c = {20.0, 20.0, 5.0, 5.0};
    vector2_t p1 = vector2_create(5.0, 5.0);
    vector2_t p2 = vector2_create(99.0, 99.0);

    printf("\\n=== collision tests ===\\n");
    assert_int_eq("rects collide", 1, rects_collide(a, b));
    assert_int_eq("rects do not collide", 0, rects_collide(a, c));
    assert_int_eq("point in rect", 1, point_in_rect(p1, a));
    assert_int_eq("point outside rect", 0, point_in_rect(p2, a));
}

void test_random(void)
{
    int value = 0;
    double d = 0.0;

    printf("\\n=== random tests ===\\n");
    rng_seed(42);
    value = random_int(1, 10);
    assert_int_eq("random int in range", 1, value >= 1 && value <= 10);
    d = random_double(0.0, 1.0);
    assert_int_eq("random double in range", 1, d >= 0.0 && d <= 1.0);
}

int main(void)
{
    test_numbers();
    test_vectors();
    test_collisions();
    test_random();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
