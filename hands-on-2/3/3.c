/**
 * Program: 3.c
 * Author: Aieshah Nasir
 * Description: Program to set any one system resource limit.
 * 		use setrlimit system call
 * Date: 27/09/2025
 */

#include <sys/resource.h>
#include <stdio.h>
#include <stdlib.h>

void printLimits(int resource, const char *name) {
	struct rlimit limit;
	if(getrlimit(resource, &limit) == -1) {
                perror(name);
                exit(1);
        }
	printf("%s:\n", name); 
        if(limit.rlim_cur == RLIM_INFINITY) {
                printf("\tSoft: Unlimited\n");
        } else {
                printf("\tSoft: %ld\n", limit.rlim_cur);
        }
        if(limit.rlim_max == RLIM_INFINITY) {
                printf("\tHard: Unlimited\n");
	} else {
                printf("\tHard: %ld\n", limit.rlim_max);
        }
}

int main(void) {
	struct rlimit limit;
	printf("original limits:\n");
	printLimits(RLIMIT_STACK, "Stack Size");
	// update new values in rlimit structure
	limit.rlim_cur = 1024000;
	limit.rlim_max = RLIM_INFINITY;
	if(setrlimit(RLIMIT_STACK, &limit) == -1) {
		perror("setrlimit");
	}
	printf("updated limits:\n");
	printLimits(RLIMIT_STACK, "Stack Size");
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/3$ ./a.out
 * original limits:
 * Stack Size:
 * 	Soft: 8388608
 * 	Hard: Unlimited
 * updated limits:
 * Stack Size:
 * 	Soft: 1024000
 * 	Hard: Unlimited
 */
