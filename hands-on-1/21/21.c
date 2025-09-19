/**
 * Program: 21.c
 * Author: Aieshah Nasir
 * Description: Write a program, call fork and print the parent
 *              and child process id.
 * Date: 05/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t p = fork();
	if(p == 0) {
		printf("child process id: %d\n", getpid());
		printf("parent process id: %d\n", getppid());
	}
	else {
		wait(0);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/21$ ./a.out
 * child process id: 20788
 * parent process id: 20787
 */
