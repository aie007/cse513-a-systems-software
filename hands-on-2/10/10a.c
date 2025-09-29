/**
 * Program: 10a.c
 * Author: Aieshah Nasir
 * Description: program using sigaction system call to catch the signals
 * 		a. SIGSEGV
 * Date: 28/09/2025
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void pSigHandler(int sig) {
	printf("signal %d SIGSEGV caught!\n", sig);
	exit(1);
}

int main(void) {
	struct sigaction psa;
	psa.sa_handler = pSigHandler;
	sigaction(SIGSEGV, &psa, NULL);
	// causing a segmentation fault by dereferencing nullptr
	char *ptr = NULL;
	*ptr = 100;
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/10$ ./a.out
 * signal 11 SIGSEGV caught!
 */
