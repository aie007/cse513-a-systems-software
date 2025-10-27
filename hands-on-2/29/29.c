/**
 * Program: 29.c
 * Author: Aieshah NAsir
 * Description: program to remove the message queue
 * Date: 01/10/2025
 */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
	key_t key = ftok(".", 1);
	int msgid = msgget(key, 0666 | IPC_CREAT);
	struct msqid_ds buf;
	msgctl(msgid, IPC_RMID, &buf);
	return 0; 
}

/**
Sample OP:

 */
