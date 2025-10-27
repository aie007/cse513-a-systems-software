/**
 * Program: 20a.c
 * Author: AIeshah Nasir
 * Description: two programs so that bot can communicate by FIFo
 * 		use one way communication
 * Date: 30/09/2025 
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
	char s[100];
	int fd;
	char *fifo = "myfifo";
	mkfifo(fifo, 0777);
	while(1) {
		fd = open(fifo, O_WRONLY);
		if(fd == -1) {
			perror("open");
		}
		else {
			printf("type a message...\n");
			int n = read(0, &s, sizeof(s));
			write(fd, s, n);
			close(fd);
		}
	}
	return 0;
}
