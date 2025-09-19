/**
 * Program: 1a.c
 * Author: Aieshah Nasir
 * Description: Create the following types of files using (ii) system call
 * 		a. Soft/Symbolic Link ( symlink system call )
 * Date: Aug 21 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Invalid syntax!\n");
		printf("Usage: ./1a source_name symbolic_link_name\n");
		exit(1);
	}
	// symlink() for symbolic link
	int slnk = symlink(argv[1], argv[2]);
	if(slnk == 0) {
		printf("Soft link created successfully\n");
	}
	else {
		printf("Error creating soft link\n");
		exit(1);
	}
	return 0;
}

/**
 * Sample Output: 
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/hands-on-1/1$ ./1a 1.txt slnk
 * Soft link created successfully
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/hands-on-1/1$ ls -l slnk 1.txt
 * -rw-rw-r-- 2 nasir nasir 35 Aug 14 11:04 1.txt
 * lrwxrwxrwx 1 nasir nasir  5 Aug 21 11:15 slnk -> 1.txt		
 */
