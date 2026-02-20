#include <limits.h>
#include <stdlib.h>
#include <time.h>
// #include <unistd.h>  // DON'T use sleep to generate distinct numbers!
#include "../include/hashing.h"
#include "../include/log_macros.h"
#include "../include/miniunit.h"
#include "test_utils.h"

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

int test_hash_int64_min(void)
{
    mu_start();

    i64 min = (i64)(-(1ULL << 63));
    u16 hash = hash_int64(min);

    mu_check(hash == 0);

    mu_end();
}

int test_hash_int64_max(void)
{
    mu_start();

    i64 max = (i64)((1ULL << 63) - 1);
    u16 hash = hash_int64(max);

    mu_check(hash == (u16)MAX_TABLE_SIZE - 1);

    mu_end();
}

int test_hash_int64_regular(void)
{
    /* regular cases:
     *  - keys should satisfy: SHORT_MIN< key < SHORT_MAX
     *  - hashes should satisfy 0 < hash < MAX_TABLE_SIZE
     *
     *  Will use srand and rand to do some fuzzing withing the range
     */
    mu_start(); // Arrange
    i64 random;
    i64 keys[3] = {0};
    u16 hashes[3] = {0};

    // Act
    srand(time(NULL));                             // rand seed setup
    random = rand() % (SHORT_MAX - SHORT_MIN + 1); // 0 ≤ random ≤ SHORT_MAX
    // generate keys and hashes
    keys[0] = SHORT_MIN + random;
    for (int i = 1; i < sizeof(keys) / sizeof(keys[0]); i++) {
        do {
            random = rand() % (SHORT_MAX - SHORT_MIN + 1);
            keys[i] = SHORT_MIN + random;
        } while (keys[i] == keys[i - 1]);
        hashes[i] = hash_int64(keys[i]);
    }
    hashes[0] = hash_int64(keys[0]);

#ifdef DEBUG
    log_int64(keys[0]);
    log_int64(keys[1]);
    log_int64(keys[2]);
#endif

    // Asserts
    // case 1
#ifdef DEBUG
    log_int32(hashes[0]);
#endif
    mu_check(0 <= hashes[0] && hashes[0] < MAX_TABLE_SIZE);
    // case 2
#ifdef DEBUG
    log_int32(hashes[1]);
#endif
    mu_check(0 <= hashes[1] && hashes[1] < MAX_TABLE_SIZE);
    // case 3
#ifdef DEBUG
    log_int32(hashes[2]);
#endif
    mu_check(0 <= hashes[2] && hashes[2] < MAX_TABLE_SIZE);

    mu_end();
}

// constant setup tests
int test_MAX_TABLE_SIZE()
{
    mu_start();
    mu_check(MAX_TABLE_SIZE == (1U << 15));
    mu_end();
}

int test_SHORT_MAX()
{
    mu_start();
    mu_check(SHORT_MAX > 0);
    mu_check(SHORT_MAX == SHRT_MAX);
    mu_end();
}

int test_SHORT_MIN()
{
    mu_start();
    mu_check((short)SHORT_MIN < 0);
    mu_check(SHORT_MIN < 0);
    mu_check(SHORT_MIN == SHRT_MIN);
#ifdef DEBUG
    log_hex_representation(SHORT_MIN);
    log_int32(SHORT_MIN);
#endif
    mu_end();
}

// string hash tests
static inline int test_hash_string_empty()
{
    mu_start(); // Arrange
    // Act
    char *key = "";
    u16 hash = hash_string(key);
    // Asert
    mu_check(0 <= hash && hash <= MAX_TABLE_SIZE - 1);
    mu_check(hash == 0);
#ifdef DEBUG
    log_hex_representation(hash);
    log_uint32(hash);
#endif
    mu_end(); // Teardown
}

static inline int test_hash_string_1_char()
{
    mu_start();
    mu_end();
}
// Array of all test, shall be accessible by test runner file(s)
// Add test (name + name as a string) in both arrays
test_case_t test_hash_ints[] = {
    test_hash_int64_0,   test_MAX_TABLE_SIZE, test_SHORT_MAX,         test_SHORT_MIN,
    test_hash_int64_min, test_hash_int64_max, test_hash_int64_regular};

char *hash_int_test_names[] = {"test_hash_int64_0",      "test_MAX_TABLE_SIZE",
                               "test_SHORT_MAX",         "test_SHORT_MIN",
                               "test_hash_int64_min",    "test_hash_int64_max",
                               "test_hash_int64_regular"};

int len_test_hash_ints = sizeof(test_hash_ints) / sizeof(test_hash_ints[0]);

test_case_t test_hash_strings[] = {test_hash_string_empty, test_hash_string_1_char};
char *hash_string_test_names[] = {"test_hash_string_empty", "test_hash_string_1_char"};
int len_test_hash_strings = sizeof(test_hash_strings) / sizeof(test_hash_strings[0]);
