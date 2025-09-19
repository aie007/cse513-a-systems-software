/**
 * Program: 3.c
 * Author: Aieshah Nasir
 * Description: program to create a file and print the file descriptor value.
 * 	     Use creat() system call
 * Date: 01/09/2025
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(void) {
	int fd = creat("file.txt", 0777);
	printf("file descriptor: %d\n", fd);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/3$ cc 3.c
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/3$ ./a.out
 * file descriptor: 3
 */
