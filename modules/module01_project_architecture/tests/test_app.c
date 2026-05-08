#include <stdio.h>
#include "app.h"

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

void test_strings(void)
{
    printf("\\n=== string tests ===\\n");
    assert_int_eq("strlen RlxTechs", 8, my_strlen_safe("RlxTechs"));
    assert_int_eq("strlen empty", 0, my_strlen_safe(""));
    assert_int_eq("strlen null", 0, my_strlen_safe(0));
    assert_int_eq("equals same", 1, my_str_equals("abc", "abc"));
    assert_int_eq("equals different", 0, my_str_equals("abc", "abd"));
}

void test_math(void)
{
    printf("\\n=== math tests ===\\n");
    assert_int_eq("add", 15, add_numbers(10, 5));
    assert_int_eq("add negative", 5, add_numbers(10, -5));
    assert_int_eq("multiply", 50, multiply_numbers(10, 5));
    assert_int_eq("multiply zero", 0, multiply_numbers(10, 0));
}

int main(void)
{
    test_strings();
    test_math();
    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
