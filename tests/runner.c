#include "../include/miniunit.h"
#include "test_utils.h"
#include <stdio.h>
#include <stdlib.h>

// run-test functions
static inline int run_test_hashing(void);
static inline int run_test_allocator(void);
static inline int run_test_hash_list(void);

char *names[] = {"hashing module", "allocator module", "hash_list module"};

// test runners LUT
suite_runner_t runners[] = {run_test_hashing, run_test_allocator, run_test_hash_list};
size_t len_runners = sizeof(runners) / sizeof(runners[0]);

int main(void)
{
    int option = 0;
    int status;

    // ask input
    while (1) {
        printf("Select module(s) to test: \n"
               "1. hashing test\n"
               "2. allocator test\n"
               "3. hash_list test\n"
               "4. all of the above\n"
               "> ");

        status = scanf("%d", &option);
        if (status == 1) {
            break;
        } else if (status == EOF) {
            printf("entered EOF, program exit\n");
            goto error;
        } else {
            printf("invalid inpuut, try again\n");
            scanf("%*[^\n]");
            continue;
        }
    }

    // run tests
    if (option < 4) {
        printf("Testing %s...\n", names[option - 1]);
        runners[option - 1]();
        printf("Done.\n");
    } else {
        // run all test cases when options >= 4 (with fancy function pointers)
        int names_idx = 0;
        for (suite_runner_t *runner = runners; runner < runners + len_runners; runner++) {
            printf("Testing %s...\n", names[names_idx++]);
            (*runner)();
            printf("Done.\n");
        }
    }

    return EXIT_SUCCESS;
error:
    return EXIT_FAILURE;
}

static inline int run_test_hashing(void)
{
    int status = 1; // none passing because no test was run yet.
    printf("Running int64 hashing tests...\n");
    for (int i = 0; i < len_test_hash_ints; i++) {
        status = mu_run(test_hash_ints[i], hash_int_test_names[i]);
        if (status != 0) {
            goto failed;
        }
    }

    printf("Running string hashing tests...\n");
    for (int i = 0; i < len_test_hash_strings; i++) {
        status = mu_run(test_hash_strings[i], hash_string_test_names[i]);
        if (status != 0) {
            printf("Some tests failed\n");
            goto failed;
        }
    }
    printf("Done.\n");
    printf("All tests Passed.\n");
    return status;
failed:
    printf("Some tests failed\n");
    return status;
}

static inline int run_test_allocator(void)
{
    int status = 1; // none passing because no test was run yet.

    printf("Running tests on allocator_alloc...\n");
    for (int i = 0; i < len_allocator_alloc_tests; i++) {
        status = mu_run(allocator_alloc_tests[i], allocator_alloc_test_names[i]);
        if (status != 0) {
            goto failed;
        }
    }

    printf("Running tests on allocator_dealloc...\n");
    for (int i = 0; i < len_allocator_dealloc_tests; i++) {
        status = mu_run(allocator_dealloc_tests[i], allocator_dealloc_test_names[i]);
        if (status != 0) {
            goto failed;
        }
    }

    printf("Done.\n");
    printf("All tests Passed.\n");
    return status;
failed:
    printf("Some tests failed\n");
    return status;
}

static inline int run_test_hash_list(void) { return 0; }
