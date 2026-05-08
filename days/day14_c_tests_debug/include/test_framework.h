#ifndef TEST_FRAMEWORK_H_
#define TEST_FRAMEWORK_H_

void test_start(char *name);
void test_assert_int_eq(char *label, int expected, int actual);
int test_summary(void);

#endif
