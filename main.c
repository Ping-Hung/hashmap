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

    printf("Experimenting...");
    float phi = PHI;
    log_float32(phi);
    log_hex_representation((*(unsigned int *)&phi));
    log_uint32((*(unsigned int *)&phi));
    log_uint64((*(unsigned long *)&phi));
    return EXIT_SUCCESS;
}
