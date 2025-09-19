/**
 * Program: 17b.c
 * Author: Aieshah Nasir
 * Description: Write a program to simulate online ticket reservation. 
 * 		Implement write lock. 
 * 		Write a program to open a file, store a ticket number and exit.
 *  		Write a separate program, to open the file, 
 * 		implement write lock, read the ticket number, 
 * 		increment the number and 
 * 		print the new ticket number then close the file.
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main() {
    int fd = open("tkt.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Setup write lock
    struct flock lock;
    lock.l_type = F_WRLCK;     // Write lock
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;            // Lock entire file
    lock.l_pid = getpid();

    // Apply lock
    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - locking");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Read current ticket number
    char buffer[32];
    lseek(fd, 0, SEEK_SET);
    int bytes = read(fd, buffer, sizeof(buffer) - 1);
    if (bytes <= 0) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytes] = '\0';

    int ticket = atoi(buffer);
    ticket++;

    // Print new ticket number
    printf("Your ticket number is: %d\n", ticket);

    // Write updated ticket number
    snprintf(buffer, sizeof(buffer), "%d\n", ticket);
    lseek(fd, 0, SEEK_SET);
    ftruncate(fd, 0);  // Clear file before writing
    write(fd, buffer, strlen(buffer));

    // Release lock
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}

/**
o/p:
nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/17$ ./a.out
tkt init number 100
nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/17$ cc 17b.c
nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/17$ ./a.out
open: No such file or directory
nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/17$ cc 17b.c
nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-1/17$ ./a.out
Your ticket number is: 101

*/
