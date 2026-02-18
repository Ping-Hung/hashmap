#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

/**
 * Declaration of test case function format, common test-case data
 * structures, and types for both the runner.c and all test_xxx.c
 *  - function format: a function pointer, return type: int, takes no parameters
 *  - test-case data structure: array of function pointers and their length
 */

// Data structures are only **declared** with the extern keyword (i.e. compiler
// only knows their existence, but don't know where they are stored, and what
// values they store.)
//
// The actual storage location and value will be set in corresponding .c files.

// test case function "format"
typedef int (*test_case_t)(void);
// runner function "format" (same as test_case_t for now)
typedef int (*runner_func_t)(void);

// hash_int64
extern test_case_t test_hash_ints[];
extern int len_test_hash_ints;

// hash_string
extern test_case_t test_hash_strings[];
extern int len_test_hash_strings;

#endif // end of __TEST_UTILS_H__
