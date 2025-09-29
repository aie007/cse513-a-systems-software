/**
 * Program: 8g.c
 * Author: Aieshah Nasir
 * Description: program using signal system call to catch the following signals
 * 		g. SIGPROF (use setitimer system call)
 * Date: 27/09/2025
 */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) {
	printf("signal %d (SIGPROF) caught!\n", sig); 
	exit(1);
}

int main(void) {
	if(signal(SIGPROF, handler) == SIG_ERR) {
		perror("signal()");
		exit(1);
	}
	// raise(SIGVTALRM);
	struct itimerval it;
	it.it_interval.tv_sec = 2;
	it.it_interval.tv_usec = 0;
	it.it_value.tv_sec = 2;
	it.it_value.tv_usec = 0;
	printf("setting timer for 2 secs...\n");
	if(setitimer(ITIMER_PROF, &it, NULL) == -1) {
		perror("setitimer");
		exit(1);
	}
	while(1);
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/8$ ./a.out
 * setting timer for 2 secs...
 * signal 27 (SIGPROF) caught!
 */
