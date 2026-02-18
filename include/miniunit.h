/**
 *          A MINImal UNIT-testing framework
 *  Usage Pattern:
 *     - A test case should look like
 *          int test_func(void)
 *          {
 *              // Arrange
 *              mu_start(); // test case setup
 *              // Act
 *              // Assert
 *              mu_check(...)
 *              mu_end(); // test case teardown
 *          }
 *      - A runner is supposed to invoke mu_run(test_case_x); to run test_case_x
 */
#ifndef __MINI_UNIT_H__
#define __MINI_UNIT_H__

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MU_SUCCESS 0
#define ANSI_RED "\x1b[1;31m"
#define ANSI_GREEN "\x1b[1;32m"
#define ANSI_RESET "\x1b[0m"

// test case function type: a function returning an int, taking no parameter.
typedef int (*test_case_t)(void);

// Test case setup macro (a.k.a Arrange)
#define mu_start() int _mu_first_failure_line_number_or_0 = MU_SUCCESS

// Assert utilities macro
#define mu_check(condition)                                                              \
    do {                                                                                 \
        if (!(condition) && (_mu_first_failure_line_number_or_0 == 0)) {                 \
            _mu_first_failure_line_number_or_0 = __LINE__;                               \
        }                                                                                \
    } while (false)

/* mu_check_strings_equal is potentially unsafe with the use of strcmp */
#define mu_check_strings_equal(s1, s2)                                                   \
    do {                                                                                 \
        if (strcmp(s1, s2) != 0) {                                                       \
            printf("s1 is different from s2\ns1 is %s while s2 is %s\n", s1, s2);        \
            _mu_first_failure_line_number_or_0 = __LINE__;                               \
        } else {                                                                         \
            printf("s1 and s2 are identical\n");                                         \
        }                                                                                \
    } while (false)
// end of Asserts

// Test case teardown
#define mu_end() return _mu_first_failure_line_number_or_0

// test runner function (returns the return value of test)
// this is called by mu_run
static inline int _run_test(test_case_t test, char *test_name)
{
    assert(test && "parameter test must be a valid function address");
    assert(test_name && "parameter test_name must be a valid function address");
    int result = test();
    if (result == 0) {
        printf("%sTest passed:%s %s\n", ANSI_GREEN, test_name, ANSI_RESET);
    } else {
        printf("%sTest failed:%s %s", ANSI_RED, test_name, ANSI_RESET);
        printf("%s at line %d%s\n", ANSI_RED, result, ANSI_RESET);
    }
    return result;
}

// a function call to _run_test. I.e. will have a return value
#define mu_run(test, name) _run_test(test, name)

#endif /* End of __MINI_UNIT_H__ */
