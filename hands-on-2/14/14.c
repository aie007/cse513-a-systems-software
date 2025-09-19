/**
 * Program: 14.c
 * Author: Aieshah Nasir
 * Description: Write a simple program to create a pipe, write to the pipe, 
 * 		read from pipe and display on the monitor.
 * Date: 01/09/2025
 */

#include <unistd.h>
#include <stdio.h>

int main(void) {
	int fd[2];
	pipe(fd);
	char buf[15];
	int n = write(fd[1], "hello world\n", sizeof("hello world\n"));
	printf("%d bytes written to the pipe\n", n);
	read(fd[0], buf, n);
	printf("read o/p: %s\n", buf);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/14$ ./a.out
 * 13 bytes written to the pipe
 * read o/p: hello world
 */
