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
runner_func_t runners[] = {run_test_hashing, run_test_allocator, run_test_hash_list};
size_t len_runners = sizeof(runners) / sizeof(runners[0]);

int main(void)
{
    int option = 0;
    int status;

    // ask input
    while (1) {
        printf("specify what module(s) to test: \n"
               "1. hashing test\n"
               "2. allocator test\n"
               "3. hash_list test\n"
               "4. all\n"
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
        printf("testing %s...\n", names[option - 1]);
        runners[option - 1]();
        printf("Done.\n");
    } else {
        // run all test cases when options >= 4 (with fancy function pointers)
        int names_idx = 0;
        for (runner_func_t *runner = runners; runner < runners + len_runners; runner++) {
            printf("testing %s...\n", names[names_idx++]);
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
    printf("Testing int64 hashing...\n");
    for (int i = 0; i < len_test_hash_ints; i++) {
        mu_run(test_hash_ints[i]);
    }
    printf("Done.\n");
    // uncomment the folloowing when string hashing is implemented
    // printf("testing string hashing...");
    // for (int (**test)(void) = test_hash_ints; test < test_hash_ints +
    // len_test_hash_ints; test++) {
    //     mu_run((*test));
    // }
    // printf("Done.");
    return 0;
}

static inline int run_test_allocator(void) { return 0; }

static inline int run_test_hash_list(void) { return 0; }
