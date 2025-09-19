/**
 * Program: 30.c
 * Author: Aieshah Nasir
 * Description: program to run a script at a specific time using a daemon process
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/types.h>

#define TARGET_HOUR 23
#define TARGET_MIN 45
#define SCRIPT_PATH "~/Documents/hands-on-1/30/scrpt.sh"

void daemonize() {
    pid_t pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS); // Parent exits

    // Child continues
    if (setsid() < 0) exit(EXIT_FAILURE); // New session

    // Fork again to prevent reacquiring terminal
    pid = fork();
    if (pid < 0) exit(EXIT_FAILURE);
    if (pid > 0) exit(EXIT_SUCCESS);

    // Set file permissions and working directory
    umask(0);
    chdir("/");

    // Close standard file descriptors
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main() {
    daemonize();

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_now = localtime(&now);

        if (tm_now->tm_hour == TARGET_HOUR && tm_now->tm_min == TARGET_MIN) {
            system(SCRIPT_PATH);  // Run the script
            break; // Exit after running
        }

        sleep(30); // Check every 30 seconds
    }

    return 0;
}

/**
 * Sample Output:
 * [1]+  Done                    ./30  (wd: ~/Documents/hands-on-1/30)
 * (wd now: ~/Documents/hands-on-1/17)
 */
