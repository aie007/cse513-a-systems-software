/**
 * Program: 27a.c
 * Author: Aieshah Nasir
 * Description: program to execute `ls -Rl` using syscalls
 * 		a. execl
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
	pid_t p = fork();
	if(p == 0) {
		execl("/bin/ls", "ls", "-Rl", NULL);
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
 * total 20
 * -rw-rw-r-- 1 nasir nasir   361 Sep  7 22:40 27a.c
 * -rwxrwxr-x 1 nasir nasir 16040 Sep  7 22:40 a.out
*/
