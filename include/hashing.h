#ifndef __HASHING_H__
#define __HASHING_H__

#include "../include/log_macros.h"
#include <assert.h>
#include <stdlib.h>
/**
 * Common types, data structures, and publically accessible apis (functions) for hashing
 */

typedef short i16;
typedef unsigned short u16;
typedef int i32;
typedef unsigned int u32;
typedef long i64;
typedef unsigned long u64;

// As a starting point, hash tables will have 2^16 buckets maximum
#define MAX_TABLE_SIZE (1U << (sizeof(u16) * 8 - 1))

// casting required because expr. in parentheses are uint32_t
#define SHORT_MAX (short)(MAX_TABLE_SIZE - 1) // 2^16 - 1
#define SHORT_MIN (short)(-MAX_TABLE_SIZE)    // -2^16
// Constant for multiplicative hashing
#define PHI 0.618034f

// APIs (functions) for hashing
static inline u16 hash_int64(i64 key)
{
    /**
     *              long -> unsigned short mapping
     *              [-2^63, 2^63 - 1] -> [0, 2^15 - 1]
     *   Some saturation is done on both endpoints of the interval, use
     *   chaining to resolve hash confilct
     */
    if (key <= SHORT_MIN) {
        return 0;
    }
    if (key > SHORT_MAX) {
        return MAX_TABLE_SIZE - 1; // **index** of 2^16-th bucket
    }
    // regular multiplicative hashing
    u16 hash = (u16)MAX_TABLE_SIZE * (key * PHI - (u16)(key * PHI));
    //         Casting  b/c MAX_TABLE_SIZE is defined as a bit pattern...
    return hash;
}

static inline u16 hash_string(char *key)
{
    /*          key (stream of int8_t) -> hash ∈ [0, MAX_TABLE_SIZE - 1]
     *  string := a large char (single byte) array
     *      - Use all char in the array
     *      - Somehow "condense" them into a single big number
     *      - mod with MAX_TABLE_SIZE (potential room for "clever" bit-level masking)
     */
    assert(key && "parameter key must be a valid char *");
    u64 weighted_sum = 0;
    u16 const base = 128;
    for (char *k = key; *k != '\0'; k++) {
        weighted_sum = base * weighted_sum + (u16)*k;
    }
    return (u16)weighted_sum % MAX_TABLE_SIZE;
}

#endif // end of __HASHING_H__
