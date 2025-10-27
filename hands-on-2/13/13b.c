/**
 * Program: 13b.c
 * Author: Aieshah Nasir
 * Description: write 2 programs: first program is waiting to catch 
 * 		SIGSTOP signal, the second program will send the
 * 		signal (using kill system call). Find  out whether 
 * 		the first program is able to catch the signal or not
 * Date: 28/09/2025 
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
	pid_t target;
	printf("Enter PID of target process: ");
	scanf("%d", &target);
	if(kill(target, SIGSTOP) == -1) {
		perror("KILL");
		exit(1);
	}
	printf("sent SIGSTOP signal to process %d\n", target);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/13$ cc 13b.c
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/13$ ./a.out
 * Enter PID of target process: 35686
 * sent SIGSTOP signal to process 35686
 */
