/**
 * Program: 17c.c
 * Author: Aieshah Nasir
 * Description: write a program to execute ls -l | wc
 * 		c. use fcntl
 * Date: 30/09/2025
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	pid_t pid;
	int fd[2];
	pipe(fd);
	pid = fork();
	if(pid == 0) { // child
		close(0); // closing STDIN
		fcntl(fd[0], F_DUPFD, 0); 
		// fcntl will reassign fd[0] to fd >= 0 
		// now fd[0] will act as the STDIN
		close(fd[1]); // closing unused pipe write end
		execl("/usr/bin/wc", "wc", NULL);
		char* err_msg = "could not execute 'wc'\n";
		write(2, err_msg, sizeof(err_msg));
	}
	else {
		close(1); // closing STDOUT
		fcntl(fd[1], F_DUPFD, 1); 
		// reassign fd[1] >= 1, here 1 as its the lowest avbl fd
		// hence fd[1] is STDOUT
		close(fd[0]); // closing unused pipe read end
		execl("/usr/bin/ls", "ls", "-l", NULL);
		char *err_msg = "could not execute 'ls -l'\n";
		write(2, err_msg, sizeof(err_msg));  
	}
	return 0;
}

/**
 * Sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/17$ ./a.out
 *       5      38     209
 */
