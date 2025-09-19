/**
 * Program: 16a.c
 * Author: Aieshah Nasir
 * Description: Program to perform mandatory locking
 * 		a. implement write lock
 * Date: 04/09/2025
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	struct flock lock;
	char *file = "file.txt";
	int fd = open(file, O_RDWR);
	if(fd == -1) {
		perror("open");
		return 1;
	}
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0; // 0->eof
	lock.l_pid = getpid();

	// locking
	printf("acquiring write lock\n");
	fcntl(fd, F_SETLKW, &lock);
	// critical section
	printf("write lock acquired. holding for 10 sec\n");
	sleep(10);
	// unlocking
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("write lock released\n");
	
	close(fd);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/16$ ./wrtlck
 * acquiring write lock
 * write lock acquired. holding for 10 sec
 * write lock released
 */
