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

int main() {
    FILE *fp = fopen("records.txt", "w");
    if (!fp) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Write 3 fixed-size records
    fprintf(fp, "Record 1: Alice     \n");
    fprintf(fp, "Record 2: Bob       \n");
    fprintf(fp, "Record 3: Charlie   \n");

    fclose(fp);
    printf("Initialized records.txt with 3 records.\n");
    return 0;
}


