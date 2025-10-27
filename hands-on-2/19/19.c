/**
 * Program: 19.c
 * Author: Aieshah Nasir
 * Description: Create a FIFO by
 * 		a. mknod command
 * 		b. mkfifo command
 * 		c. use strace to find out which command is better (mkfifo/mknod)
 * 		d. mknod system call
 * 		e. mkfifo library function
 * Date: 30/09/2025
 */

#include <stdio.h>
#include <sys/stat.h>

int main(void) {
	if(mkfifo("./fifo_using_mkfifo", 0666) == 0) {
		printf("fifo creation successful using mkfifo()\n");
	}
	if(mknod("./fifo_using_mknod", S_IFIFO | 0666, 0) == 0) {
		printf("fifo creation successful using mknod()\n");
	}
	return 0;
}

/**
 * Sample Output:
 * 
 * a. create a FIFO using mknod cmd 
 * $ mknod fifoA p
 * 
 * b. create a FIFO using mkfifo cmd
 * $ mkfifo fifoB
 * 
 * c. use strace to find out which is better
 * $ strace mknod fifoA p
 * $ strace mkfifo fifoB
 * mkfifo internally uses the mknod() system call with S_IFIFO mode. 
 * Hence, mkfifo is more safe and readable.
 * 
 * d. create a FIFO using mknod system call
 * e. create a FIFO using mkfifo library function
 * 
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/19$ ./a.out
 * fifo creation successful using mkfifo()
 * fifo creation successful using mknod()
 * 
 */
