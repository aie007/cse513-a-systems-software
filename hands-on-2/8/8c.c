/**
 * Program: 8c.c
 * Author: Aieshah Nasir
 * Description: program using signal system call to catch the following signals
 * 		c. SIGFPE
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
	printf("signal %d (SIGFPE) caught!\n", sig); 
	exit(1);
}

int main(void) {
	if(signal(SIGFPE, handler) == SIG_ERR) {
		perror("signal()");
		exit(1);
	}
	// raise(SIGFPE);
	// divide by zero, overflow can cause floating point exception
	int z = 1 / 0;
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/8$ ./a.out
 * signal 8 (SIGFPE) caught!
*/
