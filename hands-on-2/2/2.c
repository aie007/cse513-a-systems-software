/**
 * Program: 2.c
 * Author: Aieshah Nasir
 * Description: program to print the system resources limits. 
 * 		Use getrlimit system call.
 * Date: 27/09/2025 
 */

#include <stdio.h>
#include <sys/resource.h>
#include <stdlib.h>

void printLimits(int resource, const char *name) {
	struct rlimit limit;
	if(getrlimit(resource, &limit) == -1) {
		perror(name);
	}
	printf("%-20s:", name);
	if(limit.rlim_cur == RLIM_INFINITY) {
		printf("\tSoft: Unlimited\t");
	} else {
		printf("\tSoft: %ld\t", limit.rlim_cur);
	} 
	if(limit.rlim_max == RLIM_INFINITY) {
		printf("\tHard: Unlimited\n");
	} else {
		printf("\tHard: %ld\n", limit.rlim_max);
	}
}
int main(void) {
	printf("System Resource Limits:\n");
	printLimits(RLIMIT_CPU, "CPU Time");
	printLimits(RLIMIT_FSIZE, "File Size");
	printLimits(RLIMIT_DATA, "Data  Segment");
	printLimits(RLIMIT_STACK, "Stack Size");
	printLimits(RLIMIT_CORE, "Core File Size");
	printLimits(RLIMIT_RSS, "Resident Set Size");
	printLimits(RLIMIT_NPROC, "Processes");
	printLimits(RLIMIT_NOFILE, "Open Files");
	printLimits(RLIMIT_MEMLOCK, "Locked Memory");
	printLimits(RLIMIT_AS, "Address Space");
	printLimits(RLIMIT_LOCKS, "File Locks");
	printLimits(RLIMIT_SIGPENDING, "Pending Signals");
	printLimits(RLIMIT_MSGQUEUE, "Message Queue Size");
	printLimits(RLIMIT_NICE, "Nice Priority");
	printLimits(RLIMIT_RTPRIO, "Realtime Priority");
	printLimits(RLIMIT_RTTIME, "Realtime Timeout");
	return 0;
}

/**
 * sample output:
 * System Resource Limits:
 * CPU Time            :	Soft: Unlimited		Hard: Unlimited
 * File Size           :	Soft: Unlimited		Hard: Unlimited
 * Data  Segment       :	Soft: Unlimited		Hard: Unlimited
 * Stack Size          :	Soft: 8388608		Hard: Unlimited
 * Core File Size      :	Soft: 0		Hard: Unlimited
 * Resident Set Size   :	Soft: Unlimited		Hard: Unlimited
 * Processes           :	Soft: 62423		Hard: 62423
 * Open Files          :	Soft: 1024		Hard: 1048576
 * Locked Memory       :	Soft: 2065543168		Hard: 2065543168
 * Address Space       :	Soft: Unlimited		Hard: Unlimited
 * File Locks          :	Soft: Unlimited		Hard: Unlimited
 * Pending Signals     :	Soft: 62423		Hard: 62423
 * Message Queue Size  :	Soft: 819200		Hard: 819200
 * Nice Priority       :	Soft: 0		Hard: 0
 * Realtime Priority   :	Soft: 0		Hard: 0
 * Realtime Timeout    :	Soft: Unlimited		Hard: Unlimited
 */
