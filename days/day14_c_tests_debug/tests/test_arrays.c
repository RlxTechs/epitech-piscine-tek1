#include "project.h"
#include "test_framework.h"

void run_array_tests(void)
{
    int values[] = {10, 20, -5, 7};
    int single[] = {42};

    test_start("Array tests");

    test_assert_int_eq("array sum normal", 32, array_sum(values, 4));
    test_assert_int_eq("array sum single", 42, array_sum(single, 1));
    test_assert_int_eq("array sum size zero", 0, array_sum(values, 0));
    test_assert_int_eq("array sum NULL", 0, array_sum(0, 5));
}
