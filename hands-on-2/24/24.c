/**
 * Program: 24.c
 * Author: Aieshah Nasir
 * Description: a program to create a message queue and print
 * 		the key and message queue id
 * Date: 28/09/2025
 */

#include <sys/msg.h>
#include <stdio.h>
#include <sys/ipc.h>

int main(void) {
	key_t key = ftok(".", 'A');
	printf("key for the given path (pwd) is %d\n", key);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	printf("message queue id: %d\n", msgid);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/24$ ./a.out
 * key for the given path (pwd) is 1090851330
 * message queue id: 1
 */
