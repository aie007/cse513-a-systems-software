/**
 * Program: 23.c
 * Author: Aieshah Nasir
 * Description: a program to print the max number of files can be opened within a process and size of a pipe (circular buffer)
 * Date: 01/10/2025
 */

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	char *fifo = "myfifo";
	mkfifo(fifo, S_IRWXU);
	printf("max number of files that can be opened: %ld\n", sysconf(_SC_OPEN_MAX));
	printf("max size of pipe: %d\n", PIPE_BUF); 
	// can also do pathconf(fifo, _PC_PIPE_BUF);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/23$ ./a.out
 * max number of files that can be opened: 1024
 * max size of pipe: 4096
 */
