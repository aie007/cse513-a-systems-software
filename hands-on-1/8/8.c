/**
 * Program: 8.c
 * Author: Aieshah Nasir
 * Description: Program to open a file in read only mode, 
 * 		read line by line and display each line as it is read.
 *		Close the file when end of file is reached.
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SZ 1024

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Invalid syntax!\nUsage: %s filename\n", argv[0]);
		return 1;
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0) {
		perror("open");
		exit(1);
	}
	char buf[BUF_SZ];
	char line[BUF_SZ];
	int n, sz = 0;
	while(n = read(fd, buf, BUF_SZ)) {
		for(int i = 0; i < n; i++) {
			line[sz++] = buf[i];
			if(buf[i] == '\n') {
				write(0, line, sz);
				sz = 0;
				getchar();
			}
		}
	}
	if(sz > 0) {
		write(0, line, sz);
	}
	close(fd);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/8$ ./read 
 * Invalid syntax!
 * Usage: ./read filename
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/8$ ./read file.txt
 * hello world!
 *
 * today is 1st september 2025
 *
 * only 4 months left for this year to get over
 *
 * put your best efforts starting today
 *
 * good day!!
 * 
 */
