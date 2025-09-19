/**
 * Program: 9.c
 * Author: Aieshah Nasir
 * Description: Write a program to print the following information about a given file.
 * 		a. inode
 * 		b. number of hard links
 * 		c. uid
 * 		d. gid
 * 		e. size
 * 		f. block size
 * 		g. number of blocks
 * 		h. time of last access
 * 		i. time of last modification
 * 		j. time of last change
 * Date: 01/09/2025
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
	struct stat sb;
	
	if(argc != 2) {
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}
	
	if(lstat(argv[1], &sb) == -1) {
		perror("lstat");
		exit(1);
	}

	printf("File:                   %s\n", argv[1]);
	printf("Inode number:           %lu\n", sb.st_ino);
	printf("Number of Hard Links:   %lu\n", sb.st_nlink);
	printf("UID:                    %u\n", sb.st_uid);
	printf("GID:                    %u\n", sb.st_gid);
	printf("Size:                   %ld bytes\n", sb.st_size);
	printf("Block size:             %ld bytes\n", sb.st_blksize);
	printf("Number of blocks:       %ld\n", sb.st_blocks);
	printf("Last accessed:          %s\n", ctime(&sb.st_atime));
	printf("Last modified:          %s\n", ctime(&sb.st_mtime));
	printf("Last status change:     %s\n", ctime(&sb.st_ctime));
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/9$ ./fileinfo 9.c
 * File:                   9.c
 * Inode number:           3952714
 * Number of Hard Links:   1
 * UID:                    1000
 * GID:                    1000
 * Size:                   1333 bytes
 * Block size:             4096 bytes
 * Number of blocks:       8
 * Last accessed:          Mon Sep  1 19:42:16 2025
 * 
 * Last modified:          Mon Sep  1 19:42:00 2025
 * 
 * Last status change:     Mon Sep  1 19:42:00 2025
 */
