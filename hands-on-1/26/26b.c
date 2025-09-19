/**
 * Program: 26b.c
 * Author: Aieshah Nasir
 * Description: Write a program to execute an executable program.
 * 		b. pass some i/p to an executable program
 * 		(e.g. execute an executable $./a.out name)
 * Date: 06/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage: %s <executable-name>", argv[0]);
		return 1;
	}

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
		execl(argv[1], argv[1], NULL);
		perror("execl");
		return 1;
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/26$ ./a.out hello
 * hello world! this is for b part :)
 * parent: child process finished
 */
