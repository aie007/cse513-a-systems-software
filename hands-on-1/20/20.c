/**
 * Program: 20.c
 * Author: Aieshah Nasir
 * Description: Find the priority of your running program.
 *              Modify the priority using nice command.
 * Date: 05/09/2025
 */

int main(void) {
	for(;;);
        return 0;
}

/**
 * Working with top, nice, renice commands:
 * 
 * initial priority-------------------------------------------------------------
 * $ top -p 19850
 * 
 *    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
 *   19850 nasir     20   0    2548   1044   1044 R 100.0   0.0   2:50.33 a.out 
 * -----------------------------------------------------------------------------
 * 
 * using renice command --------------------------------------------------------
 * $ renice -n 5 -p 19850
 * 19850 (process ID) old priority 0, new priority 5
 * 
 *    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
 *   19850 nasir     20   0    2548   1044   1044 R 100.0   0.0   2:50.33 a.out   
 * -----------------------------------------------------------------------------
 * 
 * using nice command ----------------------------------------------------------
 * $ nice -20 ./a.out &
 * $ top -p 19974
 * 
 *    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
 *  19974 nasir     39  19    2548   1044   1044 R 100.0   0.0   2.00.17 a.out 
 * -----------------------------------------------------------------------------
 */
