#ifndef __TEST_UTILS_H__
#define __TEST_UTILS_H__

/**
 * Declaration of test case function format, common test-case data
 * structures, and types for both the runner.c and all test_xxx.c
 *  - function format: a function pointer, return type: int, takes no parameters
 *  - test-case data structure: arrays of function pointers, their names, and
 *  their lengths.
 */

// A test suite is a function that runs a bunch of test cases; it is a function
// that returns an int, with no parameter.
typedef int (*suite_runner_t)(void);

// Data structures here are **declared** with the extern keyword to tell the compiler:
//  - These variables exists, and are supposed to be shared across files which
//  includes test_utils.h.
//  - These variables do not have an actual storage address and initialize
//  values for now, and the actual storage location and value will be set in
//  corresponding .c files.

// --------hashing--------
extern test_case_t test_hash_ints[];
extern char *hash_int_test_names[];
extern int len_test_hash_ints;

extern test_case_t test_hash_strings[];
extern char *hash_string_test_names[];
extern int len_test_hash_strings;

// --------allocator--------
extern test_case_t allocator_alloc_tests[];
extern char *allocator_alloc_test_names[];
extern int len_allocator_alloc_tests;

extern test_case_t allocator_dealloc_tests[];
extern char *allocator_dealloc_test_names[];
extern int len_allocator_dealloc_tests;

#endif // end of __TEST_UTILS_H__
