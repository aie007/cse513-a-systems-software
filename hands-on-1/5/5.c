/**
 * Program: 5.c
 * Author: Aieshah Nasir
 * Description: Program to create five new files with infinite loop. Execute the prprogram in the background and check the file descriptor table at /proc/pid/fd
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <fcntl.h>

int main(void) {
	int cnt = 5;
	for(;;) {
		if(cnt > 0) {
			char file[100];
			sprintf(file, "file%d.txt", cnt);
			int fd = open(file, O_CREAT);
			printf("file name: %s\tfd: %d\n", file, fd); 
			cnt--;	
		}
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/5$ ./a.out &
 * [2] 13956
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/5$ file name: file5.txt	fd: 3
 * file name: file4.txt	fd: 4
 * file name: file3.txt	fd: 5
 * file name: file2.txt	fd: 6
 * file name: file1.txt	fd: 7
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/5$ ls -l /proc/13956/fd
 * total 0
 * lrwx------ 1 nasir nasir 64 Aug 31 18:47 0 -> /dev/pts/1
 * lrwx------ 1 nasir nasir 64 Aug 31 18:47 1 -> /dev/pts/1
 * lrwx------ 1 nasir nasir 64 Aug 31 18:47 2 -> /dev/pts/1
 * lr-x------ 1 nasir nasir 64 Aug 31 18:47 3 -> /home/nasir/Documents/hands-on-1/5/file5.txt
 * lr-x------ 1 nasir nasir 64 Aug 31 18:47 4 -> /home/nasir/Documents/hands-on-1/5/file4.txt
 * lr-x------ 1 nasir nasir 64 Aug 31 18:47 5 -> /home/nasir/Documents/hands-on-1/5/file3.txt
 * lr-x------ 1 nasir nasir 64 Aug 31 18:47 6 -> /home/nasir/Documents/hands-on-1/5/file2.txt
 * lr-x------ 1 nasir nasir 64 Aug 31 18:47 7 -> /home/nasir/Documents/hands-on-1/5/file1.txt
 */
