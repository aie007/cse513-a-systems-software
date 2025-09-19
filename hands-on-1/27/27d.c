/**
 * Program: 27d.c
 * Author: Aieshah Nasir
 * Description: program to execute `ls -Rl` using syscalls
 * 		d. execv
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t p = fork();
	if(p == 0) {
		char *args[] = {"ls", "-Rl", NULL};
		execv("/bin/ls", args);
	}
	else {
		wait(0);
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/27$ ./a.out
 * .:
 * total 36
 * -rw-rw-r-- 1 nasir nasir   563 Sep  7 22:41 27a.c
 * -rw-rw-r-- 1 nasir nasir   771 Sep  7 22:42 27b.c
 * -rw-rw-r-- 1 nasir nasir   821 Sep  7 22:44 27c.c
 * -rw-rw-r-- 1 nasir nasir   386 Sep  7 22:45 27d.c
 * -rw-rw-r-- 1 nasir nasir   361 Sep  7 22:41 27e.c
 * -rwxrwxr-x 1 nasir nasir 16096 Sep  7 22:46 a.out

*/
