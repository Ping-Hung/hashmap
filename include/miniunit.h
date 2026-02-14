#ifndef MINIMIUNIT_H
#define MINIUNIT_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MU_SUCCESS 0
#define ANSI_RED "\x1b[1;31m"
#define ANSI_GREEN "\x1b[1;32m"
#define ANSI_RESET "\x1b[0m"

#define mu_start() int _mu_first_failure_line_number_or_0 = MU_SUCCESS
#define mu_check(condition)								                                \
	do { 										                                        \
		if(((condition) == false) && (_mu_first_failure_line_number_or_0 == 0)) {       \
			_mu_first_failure_line_number_or_0 = __LINE__; 			                    \
		}									                                            \
	} while(false)
	
#define mu_run(function)									                    \
	do { 											                            \
		int result = function(); 							                    \
		if(result == 0) {		 						                        \
			printf("%sTest passed:%s %s\n",ANSI_GREEN, #function, ANSI_RESET);	\
		} else {									                            \
			printf("%sTest failed:%s %s",ANSI_RED, #function, ANSI_RESET); 		\
			printf("%s at line %d%s\n", ANSI_RED, result, ANSI_RESET);    		\
		}										                                \
	} while(false)

/* mu_check_strings_equal is potentially unsafe with the use of strcmp */				
#define mu_check_strings_equal(s1, s2)								                \
	do {											                                \
		if(strcmp(s1, s2) != 0) {							                        \
			printf("s1 is different from s2\ns1 is %s while s2 is %s\n", s1, s2);   \
			_mu_first_failure_line_number_or_0 = __LINE__;                          \
		} else {									                                \
			printf("s1 and s2 are identical\n");					                \
		}										                                    \
	} while(false)

#define mu_end() return _mu_first_failure_line_number_or_0

#endif /* End of MINIUNIT_H */
