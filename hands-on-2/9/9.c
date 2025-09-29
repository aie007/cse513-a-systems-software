/**
 * Program: 9.c
 * Author: Aieshah Nasir
 * Description: program to ignore a SIGINT signal then reset the default action
 * 		of the SIGINT signal (use signal syscall)
 * Date: 28/09/2025
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void) {
	printf("ignoring SIGINT for 5 secs\n");
	signal(SIGINT, SIG_IGN);
	sleep(10);
	printf("\nresetting SIGINT to default\n");
	signal(SIGINT, SIG_DFL);
	while(1);
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/9$ ./a.out
 * ignoring SIGINT for 5 secs
 * ^C^C^C^C^C
 * resetting SIGINT to default
 * ^C
 */
