/**
 * Program: 26a.c
 * Author: Aieshah Nasir
 * Description: Write a program to execute an executable program.
 * 		a. use some executable program
 * Date: 06/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
	pid_t p = fork();
	if(p == -1) {
		perror("fork");
		return 1;
	}	
	if(p > 0) {
		wait(0);
		printf("parent: child process finished\n");
	}
	else {
		execl("./hello", "./hello", NULL);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/26$ ./a.out
 * hello world! today's the last day to submit
 * parent: child process finished
 */
