/**
 * Program: 20b.c
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
	char *fifo = "myfifo";
	int fd = open(fifo, O_RDONLY);
	while(1) {
		if(fd == -1) {
			perror("open");
		}
		else {
			char s;
			while(read(fd, &s, 1) > 0) {
				write(1, &s, 1);
			}
			write(1, "\n", 1);
		}
		close(fd);
	}
	return 0;
}

/**
 * Sample Output:
 * 
 * 20a.c - writer
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/20$ ./20a
 * type a message...
 * hii
 * type a message...
 * how are you?   
 * type a message...
 * can you see me?
 * type a message...
 * bye
 * type a message...
 * ^C
 * 
 * 20b.c - reader
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/20$ ./a.out
 * hii
 * how are you? 
 * can you see me?
 * bye
 * ^C
 * 
 */

