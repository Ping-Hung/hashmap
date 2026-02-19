#ifndef __HASHING_H__
#define __HASHING_H__

#include "../include/log_macros.h"
#include <stdlib.h>

/**
 * Common types, data structures, and publically accessible apis (functions) for hashing
 */

typedef long i64;
typedef unsigned short u16;

// As a starting point, hash tables will have 2^16 buckets maximum
#define MAX_TABLE_SIZE (1U << (sizeof(u16) * 8 - 1))

#define SHORT_MAX MAX_TABLE_SIZE - 1 // 2^16 - 1
#define SHORT_MIN -MAX_TABLE_SIZE    // -2^16
// Constant for multiplicative hashing
#define PHI 0.618034f
// functions and object/struct declarations for hashing

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

// static inline u16 hash_string(char *key);

#endif // end of __HASHING_H__
