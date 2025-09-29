/**
 * Program: 10b.c
 * Author: Aieshah Nasir
 * Description: program using sigaction system call to catch the signals
 * 		b. SIGINT
 * Date: 28/09/2025
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static void pSigHandler(int sig) {
	printf("signal %d SIGINT caught!\n", sig);
	exit(1);
}

int main(void) {
	struct sigaction psa;
	psa.sa_handler = pSigHandler;
	sigaction(SIGINT, &psa, NULL);
	// ctrl+c on an infinite loop should cause an interrupt
	for(;;);
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/10$ ./a.out
 * ^Csignal 2 SIGINT caught!
 */
