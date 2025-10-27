/**
 * Program: 25.c
 * Author: Aieshah Nasir
 * Description: Write a program to print a message queue's 
 * 		(use msqid_ds and ipc_perm structures)
 * 		a. access permission
 * 		b. uid, gid
 * 		c. time of last message sent and received
 * 		d. time of last change in the message queue
 * 		e. size of the queue
 * 		f. number of messages in the queue
 * 		g. maximum number of bytes allowed
 * 		h. pid of the msgsnd and msgrcv
 * Date: 28/09/2025
 */

#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <time.h>

typedef struct msg_buffer {
	long msg_type;
	char msg_txt[100];
} msg_buffer;

int main(void) {
	msg_buffer message;
	key_t key = ftok(".", 1);
	int msgid = msgget(key, 0666 | IPC_CREAT);

	struct msqid_ds buf;
	msgctl(msgid, IPC_STAT, &buf); // IPC_STAT

	struct ipc_perm msg_perm = buf.msg_perm;
	
	printf("access permission: %d\n", msg_perm.mode);
	printf("uid: %d\tgid: %d\n", msg_perm.uid, msg_perm.gid);
	printf("time of last message sent: %ld\n", buf.msg_rtime);
	printf("time of last received: %ld\n", buf.msg_stime);
	printf("time of last change in message queue: %ld\n", buf.msg_ctime);
	printf("size of the queue: %ld bytes\n", buf.msg_cbytes);
	printf("number of messages in queue: %ld\n", buf.msg_qnum);
	printf("max number of bytes in queue: %ld bytes\n", buf.msg_qbytes);
	printf("PID of last msgsnd: %ld\n", buf.msg_lspid);
	printf("PID of last msgrcv: %ld\n", buf.msg_lrpid);
	return 0;
}

/**
 * Sample Output:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/25$ ./a.out
 * access permission: 438
 * uid: 1000	gid: 1000
 * time of last message sent: 0
 * time of last received: 0
 * time of last change in message queue: 1759164595
 * size of the queue: 0 bytes
 * number of messages in queue: 0
 * max number of bytes in queue: 16384 bytes
 * PID of last msgsnd: 0
 * PID of last msgrcv: 0
 */
