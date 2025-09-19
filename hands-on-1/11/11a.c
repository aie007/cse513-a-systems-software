/**
 * Program: 11a.c
 * Author: Aieshah Nasir
 * Description: Write a program to open a file, duplicate the file descriptor 
 * 		and append the file with both the descriptors and 
 * 		check whether the file is updated properly or not.
 * 		a. use dup
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
	int fd_dup = dup(fd);
	if(fd_dup == -1) {
		perror("dup");
		close(fd);
		exit(1);
	}
	write(fd, "i am fd from 11a.c\n", sizeof("i am fd from 11a.c\n"));
	write(fd_dup, "i am fd_dup\n", sizeof("i am fd_dup\n"));
	
	close(fd);
	close(fd_dup);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/11$ more file.txt
 * i am fd from 11a.c
 * i am fd_dup
 */
