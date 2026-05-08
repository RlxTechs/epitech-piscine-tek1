#include <stdio.h>
#include "math_game.h"

void print_vector(char *label, vector2_t v)
{
    printf("%s = (%.2f, %.2f)\\n", label, v.x, v.y);
}

int main(void)
{
    vector2_t player = vector2_create(10.0, 20.0);
    vector2_t enemy = vector2_create(40.0, 60.0);
    vector2_t direction = vector2_normalize(vector2_sub(enemy, player));
    rect_t player_box = {10.0, 20.0, 32.0, 32.0};
    rect_t wall_box = {25.0, 35.0, 20.0, 20.0};

    printf("=== RLX Math for Games Demo ===\\n");
    print_vector("player", player);
    print_vector("enemy", enemy);
    print_vector("direction", direction);

    printf("distance player/enemy = %.2f\\n", vector2_distance(player, enemy));
    printf("clamp 150 between 0 and 100 = %.2f\\n", clamp_double(150.0, 0.0, 100.0));
    printf("lerp 0 -> 100 at 0.25 = %.2f\\n", lerp(0.0, 100.0, 0.25));
    printf("90 degrees in radians = %.2f\\n", deg_to_rad(90.0));
    printf("rect collision = %d\\n", rects_collide(player_box, wall_box));

    rng_seed(42);
    printf("random int 1..10 = %d\\n", random_int(1, 10));
    printf("random double 0..1 = %.3f\\n", random_double(0.0, 1.0));

    return 0;
}
