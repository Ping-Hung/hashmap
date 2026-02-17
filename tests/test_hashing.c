#include "../include/hashing.h"
#include "../include/log_macros.h"
#include "../include/miniunit.h"

// first declare and define the test function above test_functions array, then add the
// name to it
// **function "standard" form**: int test_xxx(void)

// int64 hash tests
int test_hash_int64_0(void)
{
    mu_start(); // test case init (Arrange)

    // test case setup (Act)
    int64_t key = 0;
    int16_t result = hash_int64(key);

    // asserts
    mu_check(result == 0x0); // a placeholder for now, maybe the final hash is a
                             // binary pattern expressed in hex
    mu_end();                // test case teardown (returning final result)
}

// string hash tests

// Array of all test, shall be accessible by test runner file(s)
int (*test_hash_ints[])(void) = {test_hash_int64_0};

// int (*test_hash_strings[])(void) = {};   // uncomment this when a hash_string test is
// implemented
