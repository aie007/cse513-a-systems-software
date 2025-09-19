/**
 * Program: 14.c
 * Author: Aieshah Nasir
 * Description: Program to find the type of a file
 * 		a. i/p should be taken from the command line 
 * 		b. program should be able to identify any type of file 
 * Date: 04/09/2025
 */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Usage: %s filename", argv[0]);
	}
	
	struct stat st;
	stat(argv[1], &st);
	if(S_ISREG(st.st_mode))
		printf("regular file\n");
	else if(S_ISDIR(st.st_mode))
                printf("directory\n");
	else if(S_ISCHR(st.st_mode))
                printf("character device\n");
	else if(S_ISBLK(st.st_mode))
                printf("block device\n");
	else if(S_ISFIFO(st.st_mode))
                printf("FIFO named pipe\n");
	else if(S_ISLNK(st.st_mode))
                printf("symbolic link file\n");
	else if(S_ISSOCK(st.st_mode))
                printf("socket\n");
	else 
		printf("file type unknown\n");

	if(!fork()) {
		execl("/usr/bin/file", "file", argv[1], NULL);
		perror("execl");
	}
	else {
		wait(0);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/14$ ./a.out 14.c
 * regular file
 * 14.c: C source, ASCII text
 */
