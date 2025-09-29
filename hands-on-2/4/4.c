/**
 * Program: 4.c
 * Author: Aieshah Nasir
 * Description: Program to measure the amt of time to execute 100 getppid()
 * 		system call. use timestamp counter
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned long long rdtsc() {
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A" (dst));
	return dst;
}

int main(void) {
	long long int start, end;
	start = rdtsc();
	for(int i = 0; i < 100; i++) {
		getppid();
	} 
	end = rdtsc();
	printf("time taken to execute 100 getppid() syscall = %llu ticks\n", end - start);
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/4$ ./a.out
 * time taken to execute 100 getppid() syscall = 90412 ticks
 */
