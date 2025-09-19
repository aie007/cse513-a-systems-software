/**
 * Program: 11a.c
 * Author: Aieshah Nasir
 * Description: Program to find out the opening mode of a file. Use fcntl.
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fd = open("file.txt", O_WRONLY);
	if(fd == -1) {
		perror("open");
		exit(1);
	}
	int flags = fcntl(fd, F_GETFL);
	if(flags == -1) {
		perror("fcntl");
		close(fd);
		exit(1);
	}
	int access_mode = flags & O_ACCMODE;
	const char flags_str[][100] = { "O_RDONLY", "O_WRONLY", "O_RDWR", 
		"O_CREAT", "O_TRUNC", "O_APPEND",
		"O_WRONLY | O_CREAT | O_TRUNC",
		"O_WRONLY | O_CREAT | O_APPEND",
		"O_RDWR | O_CREAT | O_TRUNC",
		"O_RDWR | O_CREAT | O_APPEND"
    	};
	printf("access mode: %s\n", flags_str[access_mode]);
	close(fd);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/12$ ./a.out
 * access mode: O_WRONLY
 */
