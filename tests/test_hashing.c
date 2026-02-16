#include "../include/log_macros.h"
#include "../include/miniunit.h"
#include "../include/hashing.h"

// first declare and define the test function above test_functions array, then add the name to it
// **function "standard" form**: int test_xxx(void)

// int64 hash tests
int test_hash_int64_empty(void)
{
    mu_start(); // test case init
    // test case setup (Act)
    char *test_case = "";
    ret_type result = hash_algo_hash(test_case);
    // asserts
    mu_check(result == 0x0); // a placeholder for now, maybe the final hash is a
                            // binary pattern expressed in hex
    mu_end();  // test case teardown (returning final result)
}

// string hash tests

// Array of all test, shall be accessible by test runner file(s)
int (*test_hash_ints[])(void) = {
    test_hash_int64_empty
};

// int (*test_hash_strings[])(void) = {};   // uncomment this when a hash_string test is implemented
