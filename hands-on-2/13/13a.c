/**
 * Program: 13a.c
 * Author: Aieshah Nasir
 * Description: Write 2 programs: first program is waiting to catch 
 * 		SIGSTOP signal, the second program will send the 
 * 		signal (using kill system call). Find out whether 
 * 		the first program is able to catch the signal or not.
 * Date: 28/09/2025
 */

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
	printf("signal %d SIGSTOP caught!\n", sig);
}

int main(void) {
	signal(SIGSTOP, handler);
	printf("waiting for SIGSTOP (PID: %d)...\n", getpid());
	while(1) {
		sleep(1);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/13$ ./a.out
 * waiting for SIGSTOP (PID: 35686)...
 * 
 * [1]+  Stopped                 ./a.out
 *
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/13$ kill -SIGCONT 35686
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/13$ fg
 * ./a.out
 * ^C
 *
 * The 1st program is NOT able to catch SIGSTOP signal as its non-catchable and non-ignorable signal. It immediately suspends the process, and the process has no way to intercept or respond to it. Only SIGCONT can resume it.
 */
