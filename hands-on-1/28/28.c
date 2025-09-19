/**
 * Program: 28.c
 * Author: Aieshah Nasir
 * Description: program to get  minimum and maximum real time priority
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <sched.h>

int main(void) {
	printf("SCHED_FIFO\nMax Priority: %d\tMin Priority: %d\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
	printf("SCHED_RR\nMax Priority: %d\tMin Priority: %d\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/28$ ./a.out
 * SCHED_FIFO
 * Max Priority: 99	Min Priority: 1
 * SCHED_RR
 * Max Priority: 99	Min Priority: 1
 */

