#ifndef __TEST_HASHING_H__
#define __TEST_HASHING_H__
// Declare all common data structures accessible to the runner.
// They are only **declared** (told the compiler existence of these symbols),
// the actual storage duration isn't set yet
//
// Will set them in corresponding .c files

// hash_int64
extern int (*test_hash_ints[])(void);
extern int len_test_hash_ints;

// hash_string
extern int (*test_hash_strings)[];
extern int len_test_hash_strings;

#endif // end of __TEST_HASHING_H__
