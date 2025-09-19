/**
 * Program: 16.c
 * Author: Aieshah Nasir
 * Description: Program to send and receive data from parent to child 
 * 		and vice versa. use two array communication.
 * Date: 02/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int fd[2][2];
	char buf1[1024];
	char buf2[1024];
	pipe(fd[0]); // fd1
	pipe(fd[1]); // fd2
	if(!fork()) {
		close(fd[0][1]); // close write of fd1
		close(fd[1][0]); // close read of fd2
		read(fd[0][0], buf1, sizeof(buf1)); // reads from fd1
		printf("%s\n", buf1);
		write(fd[1][1], buf2, sizeof(buf2));// writes to fd2
	}
	else {
		close(fd[0][0]); // close read of fd1
		close(fd[1][1]); // close write of fd2
		write(fd[1][0], buf2, sizeof(buf2)); // writes to fd1
		read(fd[0][1], buf1, sizeof(buf1));// reads from fd2
		printf("%s\n", buf1);
		wait(0);
	}
	return 0;
}

/**
 * Smaple Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/15$ ./a.out
 * read in child (pid=5309, ppid=5308): Hii
 */

