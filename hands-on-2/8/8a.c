/**
 * Program: 8a.c
 * Author: Aieshah Nasir
 * Description: program using signal system call to catch the following signals
 * 		a. SIGSEGV
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
	printf("signal %d (SIGSEGV) caught!\n", sig); 
	exit(1);
}

int main(void) {
	if(signal(SIGSEGV, handler) == SIG_ERR) {
		perror("signal()");
		exit(1);
	}
	// raise(SIGSEGV);
	// dereferencing nullptr causes seg fault
	char *ptr = NULL;
	*ptr = 100;
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/8$ ./a.out
 * signal 11 (SIGSEGV) caught!
*/
