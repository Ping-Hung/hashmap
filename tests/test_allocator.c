#include "../include/log_macros.h"
#include "../include/miniunit.h"
#include "test_utils.h"
/**
 *  Initialize a global allocator object object_pool, test if it is init. properly
 *  Allocate and deallocate tests will test this object's alloc and dealloc function.
 */
// Allocator areana = allocator_init();
static inline int test_allocator_init()
{
    mu_start(); /* Arrange */
    /* Act: already init. as a global variable */

    /**
     *  Asserts: Check if areana is init. properly, specifically
     *  1. areana has a valid storage address
     *  2. areana's fields/attributes are init. properly
     */

    mu_end(); // Teardown
}

// allocator_alloc tests
static inline int test_allocator_alloc_empty()
{
    mu_start(); /* Arrange */
    /* Act */
    // size_t bytes = 0;
    // void *obj = allocator_alloc(areana, bytes);

    /* Asserts: check if a valid address of 0 bytes is alloc'd to mem */

    mu_end(); // Teardown
}

// allocator_dealloc_tests
static inline int test_allocator_dealloc_NULL()
{
    mu_start(); /* Arrange */
    /* Act: Attempt to "return" a NULL object back to areana */

    /* Asserts */

    mu_end(); // Teardown
}

// Arrays of test_case functions, their names, and their lengths
test_case_t allocator_alloc_tests[] = {test_allocator_init, test_allocator_alloc_empty};
char *allocator_alloc_test_names[] = {"test_allocator_init",
                                      "test_allocator_alloc_empty"};
int len_allocator_alloc_tests =
    sizeof(allocator_alloc_tests) / sizeof(allocator_alloc_tests[0]);

test_case_t allocator_dealloc_tests[] = {test_allocator_dealloc_NULL};
char *allocator_dealloc_test_names[] = {"test_allocator_dealloc_NULL"};
int len_allocator_dealloc_tests =
    sizeof(allocator_dealloc_tests) / sizeof(allocator_alloc_tests[0]);
