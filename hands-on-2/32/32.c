/**
 * Program: 32.c
 * Author: Aieshah NAsir
 * Description: program to implement semaphore to protect any critical section.
 * 		a. rewrite the ticket number creation program using semaphore
 * 		b. protect shared memory from concurrent write access
 * 		c. protect multiple pseudo resources ( may be two) using counting semaphore
 * 		d. remove the created semaphore
 * Date: 01/10/2025
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef union semun {
	int val;                   // val for set val /* 1 for binary else > 1 for Counting Semaphore */
	struct semid_ds *buf;      // Data structure describing a set of semaphores.
	unsigned short int *array; // array for GETALL, SETALL
	struct seminfo *__buf;     // Buffer for IPC_INFO
} semun;
int main(void) {
	semun arg;
	key_t key = ftok(".", 336);
	int semid = semget(key, 1, 0); // if semaphore already exists
	if (semid == -1) {
        	semid = semget(key, 1, IPC_CREAT | 0700);
        	arg.val = 1;                   // 1 for binary
        	semctl(semid, 0, SETVAL, arg); // semaphore number 0// set val of binary semaphore to 0;
    	}

    	struct sembuf sem_op; // for semaphore operation
    	sem_op.sem_num = 0;
    	sem_op.sem_flg = 0;

    	printf("Entering critical zone\n");
    	// use semaphore to lock critical section
    	sem_op.sem_op = -1;
    	semop(semid, &sem_op, 1);
	
    	// critical zone;
   	printf("inside Critical section");
    	getchar();
    	int data;
    	int fd = open("ticket.txt", O_RDWR | O_CREAT, S_IRWXU);
    	if (fd == -1) {
        	perror("Error while opening file!");
        	return 0;
    	}

    	int n = read(fd, &data, sizeof(data));
    	if (n == 0) {
        	data = 1;
    	}
    	else {
        	data += 1;
        	lseek(fd, 0, SEEK_SET); // reset seek
    	}
    	write(fd, &data, sizeof(data));
    	printf("ticket (# %d) has been stored in file\n", data);

    	printf("outside critical zone\n");
    	// use semaphore to unlock critical section
    	sem_op.sem_op = 1;
    	semop(semid, &sem_op, 1);
    	return 0;
}

/**
 * sample op:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/32$ ./a.out
 * Entering critical zone
 * inside Critical section
 * a
 * ticket (# 1) has been stored in file
 * outside critical zone
 */
