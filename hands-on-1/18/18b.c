/**
 * Program: 18a.c
 * Author: Aieshah Nasir
 * Description: 18. Write a program to perform Record locking.
		a. Implement write lock
		b. Implement read lock
		Create three records in a file. Whenever you access a particular record, first lock it then modify/access to avoid race condition. 
 * Date: 07/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define RECORD_SIZE 20

void lock_record(int fd, int rec_num, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = (rec_num - 1) * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    printf("Trying to acquire %s lock on record %d...\n",
           lock_type == F_WRLCK ? "write" : "read", rec_num);

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        exit(EXIT_FAILURE);
    }

    printf("Lock acquired on record %d.\n", rec_num);
}

void unlock_record(int fd, int rec_num) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = (rec_num - 1) * RECORD_SIZE;
    lock.l_len = RECORD_SIZE;
    lock.l_pid = getpid();

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
        exit(EXIT_FAILURE);
    }

    printf("Lock released on record %d.\n", rec_num);
}

int main() {
    int rec_num, mode;
    printf("Enter record number to access (1–3): ");
    scanf("%d", &rec_num);
    if (rec_num < 1 || rec_num > 3) {
        fprintf(stderr, "Invalid record number.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter mode (0 = read, 1 = write): ");
    scanf("%d", &mode);

    int fd = open("records.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    lock_record(fd, rec_num, mode == 1 ? F_WRLCK : F_RDLCK);

    char buffer[RECORD_SIZE + 1];
    lseek(fd, (rec_num - 1) * RECORD_SIZE, SEEK_SET);
    read(fd, buffer, RECORD_SIZE);
    buffer[RECORD_SIZE] = '\0';

    if (mode == 0) {
        printf("Read record %d: %s\n", rec_num, buffer);
    } else {
        printf("Current record %d: %s\n", rec_num, buffer);
        printf("Enter new content (max 18 chars): ");
        char input[19];
        scanf("%s", input);

        // Pad and write
        char new_record[RECORD_SIZE];
        snprintf(new_record, RECORD_SIZE, "Record %d: %-10s\n", rec_num, input);
        lseek(fd, (rec_num - 1) * RECORD_SIZE, SEEK_SET);
        write(fd, new_record, RECORD_SIZE);
        printf("Record %d updated.\n", rec_num);
    }

    unlock_record(fd, rec_num);
    close(fd);
    return 0;
}
