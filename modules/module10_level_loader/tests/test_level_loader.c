#include <stdio.h>
#include "level_loader.h"

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

void test_load_valid(void)
{
    level_t level;

    printf("\\n=== load valid tests ===\\n");
    assert_int_eq("load valid", 1, level_load(&level, "levels/level_valid.txt"));
    assert_int_eq("width", 20, level.width);
    assert_int_eq("height", 10, level.height);
    assert_int_eq("validate valid", 1, level_validate(&level));
    assert_int_eq("coins", 3, level.coins);
}

void test_invalid_levels(void)
{
    level_t level;

    printf("\\n=== invalid level tests ===\\n");
    assert_int_eq("load no exit", 1, level_load(&level, "levels/level_invalid_no_exit.txt"));
    assert_int_eq("validate no exit", 0, level_validate(&level));
    assert_int_eq("load open border", 1, level_load(&level, "levels/level_invalid_open_border.txt"));
    assert_int_eq("validate open border", 0, level_validate(&level));
    assert_int_eq("load missing file", 0, level_load(&level, "levels/missing.txt"));
}

void test_core_functions(void)
{
    level_t level;
    position_t pos;

    printf("\\n=== core function tests ===\\n");
    level_load(&level, "levels/level_valid.txt");
    level_validate(&level);
    assert_int_eq("inside", 1, level_is_inside(&level, 1, 1));
    assert_int_eq("outside", 0, level_is_inside(&level, -1, 1));
    assert_int_eq("wall", 1, level_is_wall(&level, 0, 0));
    assert_int_eq("walkable player", 1, level_is_walkable(&level, level.player.x, level.player.y));
    assert_int_eq("count player", 1, level_count_char(&level, 'P'));
    assert_int_eq("find exit", 1, level_find_char(&level, 'X', &pos));
    assert_int_eq("path exists", 1, level_path_exists(&level));
}

int main(void)
{
    test_load_valid();
    test_invalid_levels();
    test_core_functions();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
