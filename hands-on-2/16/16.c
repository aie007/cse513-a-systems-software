/**
 * Program: 16.c
 * Author: Aieshah Nasir
 * Description: program to send and receive data from parent to child and 
 * 		vice versa. use two way communication
 * Date: 29/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	int pipe1[2], pipe2[2];
	char *m1 = "hello child";
	char *m2 = "hii parent";
	char buf[100];

	if (pipe(pipe1) == -1 || pipe(pipe2) == -1) {
		perror("pipe");
		exit(1);
	}

	int p;
	p = fork();
	if (p < 0) {
		perror("fork");
		exit(1);
	}
	else if (p == 0) {
		close(pipe1[1]);
		close(pipe2[0]);
		write(pipe2[1], m1, sizeof(m1));
		read(pipe1[0], buf, sizeof(buf));
		printf("Read in child: %s\n", buf);
		close(pipe1[0]);
		close(pipe2[1]);
	}
	else {
		close(pipe2[1]);
		close(pipe1[0]);
		write(pipe1[1], m2, sizeof(m2));
		read(pipe2[0], buf, sizeof(buf));
		printf("Read in parent: %s\n", buf);
		close(pipe2[0]);
		close(pipe1[1]);
	}
	return 0;
}

/**
Sample Output:
nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/16$ ./a.out
Read in child: hii parent
Read in parent: hello child
 */
