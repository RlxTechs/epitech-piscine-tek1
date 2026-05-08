#include "test_framework.h"

void run_string_tests(void);
void run_number_tests(void);
void run_array_tests(void);

int main(void)
{
    run_string_tests();
    run_number_tests();
    run_array_tests();
    return test_summary();
}
