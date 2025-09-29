/**
 * Program: 8b.c
 * Author: Aieshah Nasir
 * Description: program using signal system call to catch the following signals
 * 		b. SIGINT
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
	printf("signal %d (SIGINT) caught!\n", sig); 
	exit(1);
}

int main(void) {
	if(signal(SIGINT, handler) == SIG_ERR) {
		perror("signal()");
		exit(1);
	}
	// raise(SIGINT);
	// ctrl+c on an infinite loop should cause an interrupt
	for(;;);
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/8$ ./a.out
 * ^Csignal 2 (SIGINT) caught!
 */
