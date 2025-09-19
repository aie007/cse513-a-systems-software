/**
 * Program: 25.c
 * Author: Aieshah Nasir
 * Description: Write a program to create three child processes. 
 * 		The parent should wait for a particular child 
 * 		(use waitpid system call).
 * Date: 06/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
	pid_t cpid[3];
	
	for(int i = 0; i < 3; i++) {
		pid_t p = fork();
		if(p == -1) {
			perror("fork");
			exit(1);
		}
		if(p == 0) {
			printf("child %d running as pid=%d\n", i, getpid());
			sleep(2); // work simulation
			printf("exiting child %i with pid=%d\n", i, getpid());
			exit(100 + i); // exits with unique status
		}		
		else {
			cpid[i] = p;
		}
	}

	for(int i = 0; i < 3; i++) {
		int status;
		int r = waitpid(cpid[i], &status, 0);
		if(r  == -1) {
			perror("waitpid");
		} 
		else {
			if(WIFEXITED(status)) {
				printf("parent: child %d pid=%d exited with status %d\n", i, r, WEXITSTATUS(status));
			}
			else {
				printf("parent: child %d pid=%d did not exit normally\n", i, r);
			}
		}
	}
	printf("exiting parent\n");
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/25$ ./a.out
 * child 0 running as pid=52184
 * child 1 running as pid=52185
 * child 2 running as pid=52186
 * exiting child 0 with pid=52184
 * exiting child 1 with pid=52185
 * exiting child 2 with pid=52186
 * parent: child 0 pid=52184 exited with status 100
 * parent: child 1 pid=52185 exited with status 101
 * parent: child 2 pid=52186 exited with status 102
 * exiting parent
 */
