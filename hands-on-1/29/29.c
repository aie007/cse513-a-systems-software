/**
 * Program: 29.c
 * Author: Aieshah Nasir
 * Description: program to get scheduling policy and modify the 
 * 		scheduling policy (SCHED_FIFO, SCHED_RR).
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid = getpid();	
	int policy = sched_getscheduler(pid);
	switch(policy) {
		case SCHED_OTHER:
			printf("Current policy: SCHED_OTHER\n");
			break;
		case SCHED_FIFO:
                        printf("Current policy: SCHED_FIFO\n");
                        break;
		case SCHED_RR:
                        printf("Current policy: SCHED_RR\n");
                        break;
		default:
			printf("unkown policy\n");
	}
	
	struct sched_param param;
	param.sched_priority = 10;

	if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        	perror("sched_setscheduler");
    	} 
	else {
        	printf("Successfully changed to SCHED_FIFO\n");
    	}
	
	if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
                perror("sched_setscheduler");
        }
        else {
                printf("Successfully changed to SCHED_RR\n");
        }
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/29$ ./a.out
 * Current policy: SCHED_OTHER
 * sched_setscheduler: Operation not permitted
 * sched_setscheduler: Operation not permitted
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/29$ sudo ./a.out
 * [sudo] password for nasir: 
 * Current policy: SCHED_OTHER
 * Successfully changed to SCHED_FIFO
 * Successfully changed to SCHED_RR
 */
