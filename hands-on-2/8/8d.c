/**
 * Program: 8d.c
 * Author: Aieshah Nasir
 * Description: program using signal system call to catch the following signals
 * 		d. SIGALRM (use alarm system call)
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
	printf("signal %d (SIGALRM) caught!\n", sig); 
	exit(1);
}

int main(void) {
	if(signal(SIGALRM, handler) == SIG_ERR) {
		perror("signal()");
		exit(1);
	}
	// raise(SIGALRM);
	// using alarm() syscall
	printf("setting alarm for 5 seconds...\n");
	alarm(5);
	while(1)
		pause();
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/8$ ./a.out
setting alarm for 5 seconds...
 * signal 14 (SIGALRM) caught!
 */
