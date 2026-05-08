#include <stdio.h>
#include "test_framework.h"

static int total_tests = 0;
static int failed_tests = 0;

void test_start(char *name)
{
    printf("\\n=== %s ===\\n", name);
}

void test_assert_int_eq(char *label, int expected, int actual)
{
    total_tests = total_tests + 1;
    if (expected == actual) {
        printf("[OK] %s -> expected=%d actual=%d\\n", label, expected, actual);
    } else {
        failed_tests = failed_tests + 1;
        printf("[FAIL] %s -> expected=%d actual=%d\\n", label, expected, actual);
    }
}

int test_summary(void)
{
    printf("\\n=== TEST SUMMARY ===\\n");
    printf("Total tests : %d\\n", total_tests);
    printf("Failed      : %d\\n", failed_tests);
    printf("Success     : %d\\n", total_tests - failed_tests);
    if (failed_tests == 0) {
        printf("RESULT      : OK\\n");
        return 0;
    }
    printf("RESULT      : FAIL\\n");
    return 1;
}
