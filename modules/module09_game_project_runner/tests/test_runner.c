#include <stdio.h>
#include "game_runner.h"

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

void test_module_count(void)
{
    printf("\\n=== module count tests ===\\n");
    assert_int_eq("module count", 5, runner_count_modules());
}

void test_choices(void)
{
    printf("\\n=== choice tests ===\\n");
    assert_int_eq("choice 1 index", 0, runner_choice_to_index("1"));
    assert_int_eq("choice 5 index", 4, runner_choice_to_index("5"));
    assert_int_eq("choice 9 invalid", -1, runner_choice_to_index("9"));
    assert_int_eq("choice abc invalid", -1, runner_choice_to_index("abc"));
    assert_int_eq("all choice", 1, runner_is_all_choice("all"));
    assert_int_eq("valid 3", 1, runner_is_valid_choice("3"));
    assert_int_eq("valid all", 1, runner_is_valid_choice("all"));
    assert_int_eq("invalid x", 0, runner_is_valid_choice("x"));
}

void test_get_module(void)
{
    game_module_t module;

    printf("\\n=== get module tests ===\\n");
    module = runner_get_module(0);
    assert_int_eq("first module id", 1, module.id);
    module = runner_get_module(4);
    assert_int_eq("last module id", 5, module.id);
    module = runner_get_module(99);
    assert_int_eq("invalid module id", 0, module.id);
}

int main(void)
{
    test_module_count();
    test_choices();
    test_get_module();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
