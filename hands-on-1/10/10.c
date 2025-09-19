/**
 * Program: 10.c
 * Author: Aieshah Nasir
 * Description: Write a program to open a file with read write mode, 
 * 		write 10 bytes, move the file pointer by 10 bytes (use lseek) 
 * 		and write again 10 bytes.
 * 		a. check the return value of lseek
 * 		b. open the file with od and check the empty spaces in between the data.
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	int fd = open("file.txt", O_RDWR | O_CREAT, 0644);
	if(fd < 0) {
		perror("open");
		exit(1);
	}
	
	char *buff = "0123456789";
	if(write(fd, buff, 10) != 10) {
		perror("write");
		close(fd);
		exit(1);
	}
	
	lseek(fd, 10, SEEK_CUR);
	
	if(write(fd, buff, 10) != 10) {
		perror("write");
		close(fd);
		exit(1);
	}
	
	close(fd);
	return 0;
}

/**
 * Sample Output: 
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/10$ od -c file.txt
 * 0000000   0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
 * 0000020  \0  \0  \0  \0   0   1   2   3   4   5   6   7   8   9
 * 0000036
 */
