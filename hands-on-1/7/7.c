/**
 * Program: 7.c
 * Author: Aieshah Nasir
 * Description: Program to copy file1 to file2 ($cp file1 file2)
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Invalid syntax!\nUsage: ./cpy src_file dest_file\n");
		exit(1);
	}
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0777);
	if(fd1 < 0) {
		printf("can't open file1 fd=%d\n", fd1);
		exit(1);
	}
	if(fd2 < 0) {
		printf("file2 cannot open fd=%d\n", fd2);
		exit(1);
	}
	else {
		char buf[100];
		int n1, n2;
		while(n1 = read(fd1, buf, sizeof(buf))) {
			n2 = write(fd2, buf, n1);
			if(n1 != n2) {
				printf("Error writing into file!\n");
				exit(1);
			}
		}
	}
	close(fd1);
	close(fd2);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/7$ echo "hello world! it's not actually sept 1st, but i wrote that. who cares :)" > src.txt
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/7$ ./cpy src.txt dest.txt
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/7$ cat dest.txt
 * hello world! it's not actually sept 1st, but i wrote that. who cares :)
 */
