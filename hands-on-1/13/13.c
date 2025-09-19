/**
 * Program: 13.c
 * Author: Aieshah Nasir
 * Description: Program to wait for a STDIN for 10 seconds using select.
 * 		Write a proper print statement to verify whether 
 * 		the data is available within 10 seconds or not 
 * 		(check in $man 2 select)
 * Date: 01/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

int main(void) {
	int retval;
	fd_set rfds;
	struct timeval tv;
	
	// watch STDIN to see when it has i/p
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	// wait up to 10 seconds
	tv.tv_sec = 10;
	tv.tv_usec = 0;

	retval = select(1, &rfds, NULL, NULL, &tv);
	if(retval == -1) 
		perror("select");
	else if(retval)
		printf("Data is available now\n");
	else 
		printf("No data within 10 seconds\n");
	 	
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/13$ ./a.out
 * No data within 10 seconds
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/13$ ./a.out
 * jfj
 * Data is available now
 */
