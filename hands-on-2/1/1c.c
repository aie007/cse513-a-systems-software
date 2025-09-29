/**
 * Program: 1c.c
 * Author: AIeshah Nasir
 * Description: Program to set an interval timer in 10sec and 10microsec 
 * 		c. ITIMER_PROF
 * Date: 23/09/2025
 */

#include <sys/time.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void DoStuff(int sig) {
	printf("Timer went off (ITIMER_PROF)\n");
}

int main(void) {
	signal(SIGPROF, DoStuff);
	struct itimerval it_val;
	it_val.it_value.tv_sec = 10;
	it_val.it_value.tv_usec = 10;
	it_val.it_interval = it_val.it_value;
	if(setitimer(ITIMER_PROF, &it_val, NULL) == -1) {
		perror("setitimer");
		exit(1);
	}
	while(1);
	return 0;
}

/**
 * sample output: 
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/1$ ./a.out
 * Timer went off (ITIMER_PROF)
 * Timer went off (ITIMER_PROF)
 * Timer went off (ITIMER_PROF)
 * Timer went off (ITIMER_PROF)
 * Timer went off (ITIMER_PROF)
 * ^[:wqTimer went off (ITIMER_PROF)
 * Timer went off (ITIMER_PROF)
 * ^C
*/
