/**
 * Program: 30.c
 * Author: Aieshah Nasir
 * Description: Write a program to create a shared memory. 
 * 		a. write some data to the shared memory 
 * 		b. attach with O_RDONLY and check whether you are able to overwrite. 
 * 		c. detach the shared memory 
 * 		d. remove the shared memory
 * Date: 01/10/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key;
    int shmid;
    char *data;

    // Create shm
    key = ftok(".", 1);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach with read-write and write data
    data = (char *)shmat(shmid, NULL, 0);
    if (data == (char *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    strcpy(data, "Hello from shared memory!");
    printf("Data written: %s\n", data);

    // Detach after writing
    if (shmdt(data) == -1) {
        perror("shmdt");
    }

    //  Attach with O_RDONLY and try to overwrite
    data = (char *)shmat(shmid, NULL, SHM_RDONLY);
    if (data == (char *)(-1)) {
        perror("shmat (O_RDONLY)");
        exit(EXIT_FAILURE);
    }

    printf("Read-only access: %s\n", data);

    // Trying to overwrite (should cause segmentation fault or error)
    printf("Attempting to overwrite in read-only mode...\n");
    strcpy(data, "Trying to overwrite");  // This may crash or fail silently

    //  Detach shm
    if (shmdt(data) == -1) {
        perror("shmdt (readonly)");
    }

    //  Remove shm
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
    } else {
        printf("Shared memory removed.\n");
    }

    return 0;
}

/**
 * Sample op:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/30$ ./a.out
 * Data written: Hello from shared memory!
 * Read-only access: Hello from shared memory!
 * Attempting to overwrite in read-only mode...
 * Segmentation fault (core dumped)
 */
