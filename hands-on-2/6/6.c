/**
 * Program: 6.c
 * Author: Aieshah Nasir
 * Description: program to create three threads
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void hello() {
	printf("hello threadspace :)\n");
}

int main(void) {
	pthread_t t1, t2, t3;
	pthread_create(&t1, NULL, (void *)hello, NULL);
	pthread_create(&t2, NULL, (void *)hello, NULL);
	pthread_create(&t3, NULL, (void *)hello, NULL);
	pthread_exit(NULL);
	return 0;
}

/**
 * sampple output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/6$ ./a.out
 * hello threadspace :)
 * hello threadspace :)
 * hello threadspace :)
 */
