#ifndef __LOG_MACROS_H__
#define __LOG_MACROS_H__

#include <stdarg.h>
#include <stdio.h>

/**  A simple logger for debugging, these macros write error messages to stderr.
 *   Will consider making this more formal in the future by
 *      1. Write to a dedicated file in the project directory
 *      2. Add options like INFO, DEBUG, ERROR
 *      3. Include time stamps
 */

#define log_int(first_arg) fprintf(stderr, "%s == %d\n", (#first_arg), first_arg)
#define log_size_t(first_arg) fprintf(stderr, "%s == %zu\n", (#first_arg), first_arg)
#define log_uint(first_arg) fprintf(stderr, "%s == %ld\n", (#first_arg), first_arg)
#define log_char(first_arg) fprintf(stderr, "%s == '%c'\n", (#first_arg), first_arg)
#define log_str(first_arg) fprintf(stderr, "%s == \"%s\"\n", (#first_arg), first_arg)
#define log_addr(first_arg) fprintf(stderr, "%s == %p\n", (#first_arg), (void *)first_arg)
#define log_float(first_arg) fprintf(stderr, "%s == %.016f\n", (#first_arg), first_arg)
#define log_bool(first_arg)                                                              \
    fprintf(stderr, "%s == %s\n", #first_arg, (first_arg) ? "true" : "false")
#define log_hex_representation(arg) fprintf(stderr, "%s == %x\n", (#arg), arg)
#endif /* end __LOG_MACROS_H__ */
