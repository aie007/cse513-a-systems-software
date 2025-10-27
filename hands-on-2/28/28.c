/**
 * Program: 28.c
 * Author: Aieshah NAsir
 * Description: program to change the exiting message queue permission. (use msqid_ds structure)
 * Date: 01/10/2025
*/

#include <sys/msg.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <time.h>

struct msg_buffer {
	long msg_type;
	char msg_text[100];
};

int main(void) {
	struct msg_buffer message;
	key_t key = ftok(".", 1); 
	int msgid = msgget(key, 0666 | IPC_CREAT);
    
	struct msqid_ds buf;
	msgctl(msgid, IPC_STAT, &buf);
    
	struct ipc_perm msg_perm = buf.msg_perm; 
	printf("access permission %d\n", msg_perm.mode);
	buf.msg_perm.mode = 0776;
	msgctl(msgid, IPC_SET, &buf);
   
	struct msqid_ds cbuf;
	msgctl(msgid, IPC_STAT, &cbuf);
	struct ipc_perm u_msg_perm = cbuf.msg_perm; 	
	printf("access permission %d\n", u_msg_perm.mode);
	return 0;
}

/**
 * Sample Op:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/28$ ./a.out
 * access permission 438
 * access permission 510
 */
