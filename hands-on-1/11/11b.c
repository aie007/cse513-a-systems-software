/**
 * Program: 11b.c
 * Author: Aieshah Nasir
 * Description: Write a program to open a file, duplicate the file descriptor 
 * 		and append the file with both the descriptors and 
 * 		check whether the file is updated properly or not.
 * 		b. use dup2
 * Date: 01/09/2025
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	int fd = open("file.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
	if(fd == -1) {
		perror("open");
		exit(1);
	}
	int fd_dup2 = dup2(fd, 7); // 7 is newfd
	if(fd_dup2 == -1) {
		perror("dup2");
		close(fd);
		exit(1);
	}
	write(fd, "i am fd from 11b.c\n", sizeof("i am fd from 11b.c\n"));
	write(fd_dup2, "i am fd_dup2\n", sizeof("i am fd_dup2\n"));
	
	close(fd);
	close(fd_dup2);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/11$ cat file.txt
 * i am fd from 11a.c
 * i am fd_dup
 * i am fd from 11b.c
 * i am fd_dup2
 */
