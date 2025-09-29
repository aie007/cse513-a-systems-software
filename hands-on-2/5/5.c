/**
 * Program: 5.c
 * Author: Aieshah Nasir
 * Description: program to print the system limitation of
 * 		a. maximum length of the arguments to the exec family of functions.
 * 		b. maximum number of simultaneous process per user id.
 * 		c. number of clock ticks (jiffy) per second.
 * 		d. maximum number of open files
 * 		e. size of a page
 * 		f. total number of pages in the physical memory
 * 		g. number of currently available pages in the physical memory.
 * Date: 27/09/2025
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
	long val;

	val = sysconf(_SC_ARG_MAX);
	printf("maximum length of arguments to the exec family of functions: %ld\n", val);
	
	val = sysconf(_SC_CHILD_MAX);
	printf("maximum number of simultaneous proces sper user id: %ld\n", val);
	
	val = sysconf(_SC_CLK_TCK);
	printf("number of clock ticks (jiffy) per sec: %ld\n", val);

	val = sysconf(_SC_OPEN_MAX);
	printf("maximum number of open files: %ld\n", val);

	val = sysconf(_SC_PAGESIZE);
	printf("size of a page: %ld bytes\n", val);

	val = sysconf(_SC_PHYS_PAGES);
	printf("total number of pages in the physical memory: %ld\n", val);

	val = sysconf(_SC_AVPHYS_PAGES);
	printf("number of currently available pages in the physical memory: %ld\n", val);
 
	return 0;
}

/**
 * sample output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/5$ ./a.out
 * maximum length of arguments to the exec family of functions: 2097152
 * maximum number of simultaneous proces sper user id: 62423
 * number of clock ticks (jiffy) per sec: 100
 * maximum number of open files: 1024
 * size of a page: 4096 bytes
 * total number of pages in the physical memory: 4034264
 * number of currently available pages in the physical memory: 2076764
 */
