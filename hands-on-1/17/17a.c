/**
 * Program: 17a.c
 * Author: Aieshah Nasir
 * Description: Write a program to simulate online ticket reservation. 
 * 		Implement write lock. 
 * 		Write a program to open a file, store a ticket number and exit.
 *  		Write a separate program, to open the file, 
 * 		implement write lock, read the ticket number, 
 * 		increment the number and 
 * 		print the new ticket number then close the file.
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(void) {
	int fd = open("tkt.txt", O_WRONLY | O_CREAT, 0644);
	if(fd == -1) {
		perror("open");
		exit(1);
	}
	write(fd, "100\n", 5);
	close(fd);
	printf("tkt init number 100\n");
	return 0;
}
