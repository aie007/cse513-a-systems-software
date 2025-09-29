/**
 * Program: 8e.c
 * Author: Aieshah Nasir
 * Description: program using signal system call to catch the following signals
 * 		e. SIGALRM (use setitimer system call)
 * Date: 27/09/2025
 */

#include <sys/time.h>
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
	struct itimerval it;
	it.it_interval.tv_sec = 0;
	it.it_interval.tv_usec = 0;
	it.it_value.tv_sec = 5;
	it.it_value.tv_usec = 0;
	printf("setting timer for 5 secs...\n");
	if(setitimer(ITIMER_REAL, &it, NULL) == -1) {
		perror("setitimer");
		exit(1);
	}
	while(1)
		pause();
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/8$ ./a.out
setting alarm for 5 secs...
 * signal 14 (SIGALRM) caught!
 */
