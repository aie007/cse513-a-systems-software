/**
 * Program: 16a.c
 * Author: Aieshah Nasir
 * Description: Program to perform mandatory locking
 * 		b. implement read lock
 * Date: 04/09/2025
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	struct flock lock;
	char *file = "file.txt";
	char buf[1024];
	int fd = open(file, O_RDWR);
	if(fd == -1) {
		perror("open");
		return 1;
	}
	lock.l_type = F_RDLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0; // 0->eof
	lock.l_pid = getpid();

	// locking
	printf("acquiring read lock\n");
	fcntl(fd, F_SETLKW, &lock);
	// critical section
	printf("read lock acquired. holding for 10 sec\n");
	read(fd, buf, sizeof(buf));
	printf("file content:\n%s\n", buf);
	sleep(10);
	// unlocking
	lock.l_type = F_UNLCK;
	fcntl(fd, F_SETLK, &lock);
	printf("read lock released\n");
	
	close(fd);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/16$ ./a.out
 * acquiring read lock
 * read lock acquired. holding for 10 sec
 * file content:
 * Sat Sep  6 11:46:40 AM IST 2025
 * hello world! this is what the file contains (:
 * Sat Sep  6 11:48:02 AM IST 2025
 * 
 * read lock released
 */
