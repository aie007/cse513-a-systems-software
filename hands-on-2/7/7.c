/**
 * Program: 7.c
 * Author: Aieshah Nasir
 * Description: program to print the created thread ids
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void hello() {
	printf("hello threadspace :), i am thread id:%lu\n", pthread_self());
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
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/7$ ./a.out
 * hello threadspace :), i am thread id:130104726386368
 * hello threadspace :), i am thread id:130104709600960
 * hello threadspace :), i am thread id:130104717993664
 */

