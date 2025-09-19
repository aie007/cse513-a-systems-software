/**
 * Program: 23.c
 * Author: Aieshah Nasir
 * Description: Program to create a zombie state of the running program
 * Date: 05/09/2025
 */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	pid_t p = fork();
	// child
	if(p == 0) {
		exit(0);
	}
	// parent
	else {
		sleep(30);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/23$ ps aux | grep 'Z'
 * USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
 * nasir       5388  0.0  0.0      0     0 ?        Z    Sep05   0:00 [sd_espeak-ng-mb] <defunct>
 */
