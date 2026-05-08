#include <stdio.h>
#include "memory_lab.h"

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

void assert_not_null(char *name, void *ptr)
{
    if (ptr != NULL) {
        printf("[OK] %s is not NULL\\n", name);
    } else {
        printf("[FAIL] %s is NULL\\n", name);
        failures = failures + 1;
    }
}

void assert_null(char *name, void *ptr)
{
    if (ptr == NULL) {
        printf("[OK] %s is NULL\\n", name);
    } else {
        printf("[FAIL] %s is not NULL\\n", name);
        failures = failures + 1;
    }
}

void test_memory(void)
{
    void *ptr = NULL;

    printf("\\n=== memory tests ===\\n");
    ptr = safe_malloc(16);
    assert_not_null("safe_malloc 16", ptr);
    SAFE_FREE(ptr);
    assert_null("SAFE_FREE pointer", ptr);
    assert_null("safe_malloc zero", safe_malloc(0));
}

void test_strings(void)
{
    char *copy = NULL;
    char *joined = NULL;

    printf("\\n=== string tests ===\\n");
    assert_int_eq("strlen NULL", 0, my_strlen_safe(NULL));
    assert_int_eq("strlen RlxTechs", 8, my_strlen_safe("RlxTechs"));
    assert_int_eq("equals same", 1, my_str_equals("abc", "abc"));
    assert_int_eq("equals diff", 0, my_str_equals("abc", "abd"));

    copy = safe_strdup("Memory");
    assert_not_null("safe_strdup", copy);
    assert_int_eq("safe_strdup content", 1, my_str_equals(copy, "Memory"));
    SAFE_FREE(copy);
    assert_null("copy after free", copy);

    joined = safe_join("Hello ", "RLX");
    assert_not_null("safe_join", joined);
    assert_int_eq("safe_join content", 1, my_str_equals(joined, "Hello RLX"));
    SAFE_FREE(joined);
    assert_null("joined after free", joined);

    assert_null("safe_strdup NULL", safe_strdup(NULL));
    assert_null("safe_join NULL", safe_join(NULL, "x"));
}

void test_arrays(void)
{
    int *array = NULL;

    printf("\\n=== array tests ===\\n");
    array = create_int_array(5, 0);
    assert_not_null("create_int_array", array);
    assert_int_eq("array sum initial", 0, array_sum(array, 5));
    fill_sequence(array, 5);
    assert_int_eq("array sum sequence 1..5", 15, array_sum(array, 5));
    SAFE_FREE(array);
    assert_null("array after free", array);

    assert_null("create_int_array zero", create_int_array(0, 0));
    assert_int_eq("array_sum NULL", 0, array_sum(NULL, 5));
}

int main(void)
{
    test_memory();
    test_strings();
    test_arrays();

    printf("\\nFailures: %d\\n", failures);
    if (failures == 0) {
        printf("RESULT: OK\\n");
        return 0;
    }
    printf("RESULT: FAIL\\n");
    return 1;
}
