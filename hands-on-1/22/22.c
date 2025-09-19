/**
 * Program: 22.c
 * Author: Aieshah nasir
 * Description: Write a program, open a file, call fork,
 * 		and then write to the file by both the child 
 * 		as well as the parent processes. Check o/p of the file
 * Date: 05/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
	int fd = open("file.txt", O_WRONLY | O_CREAT, 0644);
	if(fd == -1) {
		perror("open");
		return 1;
	}
	// child process
	if(!fork()) {
		write(fd, "hiii! i am the child!!\n", sizeof("hiii! i am the child!!\n"));
	}
	// parent process
	else {
		write(fd, "hello from the parent\n", sizeof("hello from the parent\n"));
		wait(0); 
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/22$ cat file.txt
 * hello from the parent
 * hiii! i am the child!!
 */
