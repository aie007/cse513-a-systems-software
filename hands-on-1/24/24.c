/**
 * Program: 24.c
 * Author: Aieshah Nasir
 * Description: Program to create an orphan process
 * Date: 06/09/2025
 */

#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t p = fork();
	// child
	if(p == 0) {
		sleep(50);
		printf("in the child process\n");
	}
	else if (p > 0) {
		printf("in the parent process\n");
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/24$ ./a.out
 * in the parent process
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/24$ in the child process
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/24$ ps -ef | grep orphan
 * nasir      26674    3028  0 21:34 pts/0    00:00:00 grep --color=auto orphan
 */
