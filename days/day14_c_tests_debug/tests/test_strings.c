#include "project.h"
#include "test_framework.h"

void run_string_tests(void)
{
    test_start("String tests");

    test_assert_int_eq("strlen RlxTechs", 8, my_strlen("RlxTechs"));
    test_assert_int_eq("strlen empty", 0, my_strlen(""));
    test_assert_int_eq("strlen NULL", 0, my_strlen(0));

    test_assert_int_eq("strcmp same", 0, my_strcmp("abc", "abc"));
    test_assert_int_eq("strcmp abc abd", -1, my_strcmp("abc", "abd"));
    test_assert_int_eq("strcmp abd abc", 1, my_strcmp("abd", "abc"));
}
