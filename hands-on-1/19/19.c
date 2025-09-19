/**
 * Program: 19.c
 * Author: Aieshah Nasir
 * Description: Program to find out the time taken to execute 
 * 		getpid syscall. Use time stamp counter
 * Date: 04/09/2025
 */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

unsigned long long rdtsc() {
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A"(dst));
	return dst;
}

int main(void) {
	long long int start, end;
	start = rdtsc();
	pid_t pid = getpid();
	end = rdtsc();
	printf("pid = %d\n", pid);
	printf("Time taken: %llu\n", end - start);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/19$ ./a.out
 * pid = 18314
 * Time taken: 13283
 */
