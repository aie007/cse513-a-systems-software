/**
 * Progrma: 15.c
 * Author: Aieshah Nasir
 * Description: Program to display the environmental variable 
 * 		of the user (use environ)
 * Date: 04/09/2025
 */

#include <stdio.h>
#include <string.h>

extern char **environ;

int main(void) {
	int i = 0;
	while(environ[i] != NULL) {
		if(strncmp(environ[i], "USER=", 5) == 0) {
			printf("%s\n", environ[i]);
			break;
		}
		i++;
	}
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/15$ ./a.out
 * USER=nasir
 */
