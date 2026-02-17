#ifndef __HASHING_H__
#define __HASHING_H__

#include "../include/log_macros.h"
#include <stdint.h>
#include <stdlib.h>

// As a starting point, hash tables will have 2^16 buckets maximum

// functions and object/struct declarations for hashing
uint16_t hash_int64(int64_t key); // long -> [0, 2^16 - 1]
uint16_t hash_string(int8_t *key);

#endif // end of __HASHING_H__
