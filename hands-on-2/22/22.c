/**
 * Program: 22.c
 * Author: Aieshah Nasir
 * Description: a program to wait for data to be written into FIFO within 10 sec, use select system call with FIFO
 * Date: 01/10/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void) {
	struct timeval t;
	fd_set fd;
	char *fifo = "myfifo";
	int f = open(fifo, O_NONBLOCK | O_RDONLY); 	
	if(f == -1) {
		perror("open");
		exit(1);
	}
	FD_ZERO(&fd);
	FD_SET(f, &fd);	
	t.tv_sec = 10;
	t.tv_usec = 0;
	int ret = select(f + 1, &fd, NULL, NULL, &t);
	if(ret == -1) {
		perror("select");
		exit(1);
	}
	else if(ret == 0) {
		printf("timeout");
	}
	else {
		char buf;
		while(read(f, &buf, 1) > 0) {
			write(1, &buf, 1);
		}
		write(1, "\n", 1);
	}
	close(f);

	return 0;
}

/**
 * Sample Output:
 * 
 * terminal 2:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/22$ mkfifo myfifo
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/22$ echo "helllo" > myfifo
 * 
 * terminal 1:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/22$ ./a.out
 * helllo
 * 
 * 
 */
