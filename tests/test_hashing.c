#include "../include/hashing.h"
#include "../include/log_macros.h"
#include "../include/miniunit.h"
#include "test_utils.h"

// first define the test function above test_functions array, then add the
// name to it

/**
 *  Hash algorithm testing requirements:
 *      - Determinism: if key1 = key2, then hash(key1) = hash(key2)
 *      - Uniform Distribution: ...not sure how to test this
 *      - Fast Computation: O(1) requirement (maybe verify this with bench mark?)
 *      - Low collision probability: ...also not sure how to verify this
 */

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

// string hash tests

// Array of all test, shall be accessible by test runner file(s)
int (*test_hash_ints[])(void) = {test_hash_int64_0};
int len_test_hash_ints = sizeof(test_hash_ints) / sizeof(test_hash_ints[0]);

// int (*test_hash_strings[])(void) = {};   // uncomment this when a hash_string test is
// implemented int len_test_hash_strings =
