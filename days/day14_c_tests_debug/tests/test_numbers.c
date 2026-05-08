#include "project.h"
#include "test_framework.h"

void run_number_tests(void)
{
    test_start("Number tests");

    test_assert_int_eq("atoi 42", 42, my_atoi("42"));
    test_assert_int_eq("atoi -2026", -2026, my_atoi("-2026"));
    test_assert_int_eq("atoi spaces", 123, my_atoi("   123"));
    test_assert_int_eq("atoi text after number", 12, my_atoi("12abc"));

    test_assert_int_eq("is_number 123", 1, my_is_number("123"));
    test_assert_int_eq("is_number -123", 1, my_is_number("-123"));
    test_assert_int_eq("is_number plus", 1, my_is_number("+99"));
    test_assert_int_eq("is_number abc", 0, my_is_number("abc"));
    test_assert_int_eq("is_number empty", 0, my_is_number(""));
}
