/**
 * Program: 1c.c 
 * Author: Aieshah Nasir
 * Description: Create the following types of files using (ii) system call
 * 		c. FIFO (mkfifo lib fn or mknod syscall
 * Date: 22/08/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
	const char *fifo = "fifo.txt";
	
	if(mknod(fifo, S_IFIFO | 0666, 0) == -1) {
		perror("mknod");
		return 1;
	}
	printf("FIFO %s created successfully\n", fifo);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/1$ ./fifomake
 * FIFO fifo.txt created successfully 
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/1$ ./fifomake
 * mknod: File exists
 */
