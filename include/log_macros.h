#ifndef __LOG_MACROS_H__
#define __LOG_MACROS_H__

#include <stdio.h>
#include <stdarg.h>

#define log_int(first_arg) printf("%s == %d\n", (#first_arg), first_arg)
#define log_size_t(first_arg) printf("%s == %zu\n", (#first_arg), first_arg)
#define log_uint(first_arg) printf("%s == %ld\n", (#first_arg), first_arg)
#define log_char(first_arg) printf("%s == '%c'\n", (#first_arg), first_arg)
#define log_str(first_arg) printf("%s == \"%s\"\n", (#first_arg), first_arg)
#define log_addr(first_arg) printf("%s == %p\n", (#first_arg), (void*) first_arg)
#define log_float(first_arg) printf("%s == %.016f\n", (#first_arg), first_arg)
#define log_bool(first_arg) printf("%s == %s\n", #first_arg, (first_arg) ? "true" : "false")

#endif /* end __LOG_MACROS_H__ */
