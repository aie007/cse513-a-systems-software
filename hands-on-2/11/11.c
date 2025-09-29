/**
 * Program: 11.c
 * Author: Aieshah Nasir
 * Description: program to ignore a SIGINT signal then reset the deafult action 
 * 		of SIGINT signal. use sigaction system call
 * Date: 28/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>

int main(void) {
	struct sigaction psa;
	printf("ignoring SIGINT for 5 secs...\n");
	psa.sa_handler = SIG_IGN;
	psa.sa_flags = 0;
	if(sigaction(SIGINT, &psa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}
	sleep(5);
	printf("\nresetting the default action of SIGINT\n");
	psa.sa_handler = SIG_DFL;
	if(sigaction(SIGINT, &psa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}
	while(1);
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/11$ ./a.out
 * ignoring SIGINT for 5 secs...
 * ^C^C^C^C^C^C^C
 * resetting the default action of SIGINT
 * ^C
 */
