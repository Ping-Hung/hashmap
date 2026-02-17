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
 *      - A runner is supposed do mu_run(test_case); to run test_case
 */
#ifndef __MINI_UNIT_H__
#define __MINI_UNIT_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MU_SUCCESS 0
#define ANSI_RED "\x1b[1;31m"
#define ANSI_GREEN "\x1b[1;32m"
#define ANSI_RESET "\x1b[0m"

// Test case setup (a.k.a Arrange)
#define mu_start() int _mu_first_failure_line_number_or_0 = MU_SUCCESS
// Assert utilities
#define mu_check(condition)                                                              \
    do {                                                                                 \
        if (((condition) == false) && (_mu_first_failure_line_number_or_0 == 0)) {       \
            _mu_first_failure_line_number_or_0 = __LINE__;                               \
        }                                                                                \
    } while (false)

#define mu_run(function)                                                                 \
    do {                                                                                 \
        int result = function();                                                         \
        if (result == 0) {                                                               \
            printf("%sTest passed:%s %s\n", ANSI_GREEN, #function, ANSI_RESET);          \
        } else {                                                                         \
            printf("%sTest failed:%s %s", ANSI_RED, #function, ANSI_RESET);              \
            printf("%s at line %d%s\n", ANSI_RED, result, ANSI_RESET);                   \
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

#endif /* End of __MINI_UNIT_H__ */
