#include "include/hashing.h"
#include "include/log_macros.h"
#include <stdio.h>
#include <stdlib.h>

// this now feels a lot more like a experiment sandbox XD
int main(int argc, char *argv[])
{
    log_uint64(sizeof(short));
    log_uint64(sizeof(int));
    log_uint64(sizeof(long));

    printf("\nExperimenting with \"accessing casted address\" trick...\n"
           "This trick might cause memory accessing issues as the cast \"converts\" a "
           "type to another: \n"
           "When cast a smaller address to a longer one and accessing it, the program is "
           "accessing uninitialized memory\n");
    float phi = PHI;
    log_float32(phi);
    log_uint32((*(unsigned int *)&phi));
    // log_uint64((*(unsigned long *)&phi));    // memory access issue
    log_hex_representation((*(unsigned int *)&phi));

    printf("\nA handy union trick to examine what happened above.\n"
           "uintUfloat.as_unsigned and uintUfloat.as_float shared the same "
           "4-byte (32-bits) memory block on the stack\n");

    union {
        // this 32-bit (4 byte memory block on the call stack is shared by
        // as_unsigned and as_float
        unsigned as_unsigned;
        float as_float;
    } uintUfloat = {.as_float = PHI};

    log_float32(uintUfloat.as_float);
    log_uint32(uintUfloat.as_unsigned);

    return EXIT_SUCCESS;
}
