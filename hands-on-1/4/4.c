/*
 * Program: 4.c
 * Author: Aieshah Nasir
 * Description: Program to open an existing file with read write mode. 
 * 		Try O_EXCL flag also
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

extern int errno;

int main(void) {
	int fd = open("file.txt", O_RDWR | O_EXCL);
	printf("fd = %d\n", fd);
	if(fd == -1) {
		printf("error number %d\n", errno);
		perror("program");
	}
	return 0;
}

/*
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/4$ ./a.out
 * fd = 3
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/4$ rm file.txt
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/4$ ./a.out
 * fd = -1
 * error number 2
 * program: No such file or directory
 */
