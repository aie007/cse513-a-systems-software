/**
 * Program: 18.c
 * Author: Aieshah Nasir
 * Description: program to find out total number of directories on the pwd
 * 		execute ls -l | grep ^d | wc (use dup2 only)
 * Date: 30/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	int fd1[2], fd2[2];
	pid_t c1, c2;
	pipe(fd1);
	pipe(fd2);
	c2 = fork();
	if(c2 == 0) {
		c1 = fork();
		if(c1 == 0) {
			close(fd1[0]); // read of fd1
			close(fd1[1]); // write of fd1
			close(fd2[1]); // write of fd2
			close(0); // stdin
			dup2(fd2[0], 0); // fd2[0] = stdin
			execl("/usr/bin/wc", "wc", NULL);
		}
		else {
			close(fd1[1]); // read of fd1
			close(fd2[0]); // write of fd2
			close(0); // stdin
			dup2(fd1[0], 0); // fd1[0] = stdin
			
			close(1); // stdout
			dup2(fd2[1], 1); // fd2[1] = stdout
			
			execl("/usr/bin/grep", "grep", "^d", NULL); 
		}	
	}
	else {
		close(fd1[0]); // read of pipefd1
		close(fd2[0]); // read of fd2
		close(fd2[1]); // write of fd2
		close(1); // stdout
		dup2(fd1[1], 1); // fd1[1] = stdout
		// write o/p of 'ls -l' (stdout) into fd1[1]
		execl("/usr/bin/ls", "ls", "-l", NULL);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/18$ mkdir 1 2 3 4 5 46
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/18$ ./a.out
 *       6      54     277
 */
