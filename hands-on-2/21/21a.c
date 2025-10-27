/**
 * Program: 21a.c
 * Author: Aieshah Nasir
 * Description: two programs so that both can communicate by FIFO - use two way communication
 * Date: 01/10/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void) {
	char s[100];
	int fd;
	char *fifo = "myfifo";
	mkfifo(fifo, S_IRWXU);
	while(1) {
		fd = open(fifo, O_WRONLY);
		if(fd == -1) {
			perror("open");
			exit(1);
		}
		printf("type a message: ");
		int n = read(0, &s, sizeof(s));
		write(fd, &s, n);
		close(fd);
		fd = open(fifo, O_RDONLY);
		if(fd == -1) {
			perror("open");
			exit(1);
		}
		char buf;
		while(read(fd, &buf, 1) > 0) {
			write(1, &buf, 1);
		}
		write(1, "\n", 1);
		close(fd);
	}
	return 0;
}
