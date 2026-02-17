#ifndef __HASHING_H__
#define __HASHING_H__

#include "../include/log_macros.h"
#include <stdlib.h>

typedef long i64;
typedef unsigned short u16;

// As a starting point, hash tables will have 2^16 buckets maximum

// functions and object/struct declarations for hashing
u16 hash_int64(i64 key); // long -> [0, 2^16 - 1]
u16 hash_string(char *key);

#endif // end of __HASHING_H__
