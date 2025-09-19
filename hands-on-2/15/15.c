/**
 * Program: 15.c
 * Author: Aieshah NAsir
 * Description :  Program to send some data from parent to the child process.
 * Date: 02/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	int fd[2];
	char buf[15];
	pipe(fd);
	
	if(!fork()) {
		close(fd[1]);
		read(fd[0], buf, 5);
		printf("read in child (pid=%i, ppid=%i): %s\n", getpid(), getppid(), buf);
	}
	else {
		close(fd[0]);
		write(fd[1], "Hii\n", 5);
		wait(0);
	}
	return 0;
}

/**
 * Smaple Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/15$ ./a.out
 * read in child (pid=5309, ppid=5308): Hii
 */
