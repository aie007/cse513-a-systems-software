/**
 * Program: 12.c
 * Author: Aieshah Nasir
 * Description: program to create an orphan process. 
 * 		use kill system call to send SIGKILL signal to the 
 * 		parent process from the child process
 * Date: 28/09/2025
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	pid_t pid = fork();
	if(pid == -1) {
		perror("fork");
		return 1;
	}	
	// child
	else if(pid == 0) {
		printf("hii from the child (pid = %d, ppid = %d)\n", getpid(), getppid());
		if(kill(getppid(), SIGKILL) == -1) {
			perror("kill");
			return 1;
		} 
		printf("parent killed.\n");
		sleep(10);
		printf("child is an orphan now, adopted by init. Parent PID = %d\n", getppid());	
	}
	// parent
	else {
		sleep(15);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/12$ ./a.out
 * hii from the child (pid = 34103, ppid = 34102)
 * parent killed.
 * Killed
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/12$ child is an orphan now, adopted by init. Parent PID = 2079
 */
