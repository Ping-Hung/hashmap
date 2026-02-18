#include "../include/hashing.h"
#include "../include/log_macros.h"
#include "../include/miniunit.h"
#include "test_utils.h"
#include <limits.h>

/**
 *  Hash algorithm testing requirements:
 *      - Determinism: if key1 = key2, then hash(key1) = hash(key2)
 *      - Uniform Distribution: ...not sure how to test this
 *      - Fast Computation: O(1) requirement (maybe verify this with bench mark?)
 *      - Low collision probability: ...also not sure how to verify this
 */

// 1. define test cases (actual testing logic) first
// 2. Add test case and its name to the 2 arrays at the bottom of the file

// int64 hash tests
int test_hash_int64_0(void)
{
    mu_start(); // test case init (Arrange)

    // test case setup (Act)
    i64 key = 0;
    u16 result = hash_int64(key);

    // asserts
    mu_check(result == 0x0U);

    mu_end();
}

int test_MAX_TABLE_SIZE()
{
    mu_start();
    mu_check(MAX_TABLE_SIZE == (1U << 15));
    mu_end();
}

int test_SHORT_MAX()
{
    mu_start();
    mu_check(SHORT_MAX == SHRT_MAX);
    mu_end();
}

int test_SHORT_MIN()
{
    mu_start();
    mu_check(SHORT_MIN == SHRT_MIN);
    mu_end();
}

// string hash tests

// Array of all test, shall be accessible by test runner file(s)
// Add test (name + name as a string) in both arrays
test_case_t test_hash_ints[] = {test_hash_int64_0, test_MAX_TABLE_SIZE, test_SHORT_MAX,
                                test_SHORT_MIN};
char *hash_int_test_names[] = {"test_hash_int64_0", "test_MAX_TABLE_SIZE",
                               "test_SHORT_MAX", "test_SHORT_MIN"};
int len_test_hash_ints = sizeof(test_hash_ints) / sizeof(test_hash_ints[0]);
