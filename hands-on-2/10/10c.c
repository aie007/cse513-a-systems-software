/**
 * Program: 10c.c
 * Author: Aieshah Nasir
 * Description: program using sigaction system call to catch the signals
 * 		c. SIGFPE
 * Date: 28/09/2025
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void pSigHandler(int sig) {
	printf("signal %d SIGFPE caught!\n", sig);
	exit(1);
}

int main(void) {
	struct sigaction psa;
	psa.sa_handler = pSigHandler;
	sigaction(SIGFPE, &psa, NULL);
	// div by 0, overflow can cause floating pt exception
	int z = 1 / 0;
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/10$ ./a.out
 * signal 8 SIGFPE caught!
 */
