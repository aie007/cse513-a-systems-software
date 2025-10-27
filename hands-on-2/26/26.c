/**
 * Program: 26.c
 * Author: Aieshah Nasir
 * Description: program to send messages to the message queue
 * 		check $ipcs -q
 * Date: 29/09/2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 100

struct msg_buffer {
	long type;
	char txt[MSG_SIZE];
};

int main(void) {
	key_t key;
	int msgid;
	struct msg_buffer msg;
	key = ftok(".", 1);
	if(key == -1) {
		perror("ftok");
		exit(1);
	}
	msgid = msgget(key, 0666 | IPC_CREAT);
	if(msgid == -1) {
		perror("msgget");	
		exit(1);
	}
	msg.type = 1;
	strcpy(msg.txt, "hello message queue!");
	if(msgsnd(msgid, &msg, sizeof(msg.txt),0) == -1) {
		perror("msgsnd");
		exit(1);
	}
	printf("message sent: %s\n", msg.txt);
	return 0;
}

/**
 * Sample o/p:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/26$ ./a.out
 * message sent: hello message queue!
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/26$ ipcs -q
 * 
 * ------ Message Queues --------
 * key        msqid      owner      perms      used-bytes   messages    
 * 0x010512ba 0          nasir      666        100          1           
 */
