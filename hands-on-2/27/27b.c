/**
 * Program: 27b.c
 * Author: Aieshah NAsir
 * Description: program to receive messages from the message queue.
 * 		b. with IPC_NOWAIT as a flag
 * Date: 01/10/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MSG_SIZE 100

// Define message structure
struct msg_buffer {
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;

    // Generate the same key as sender
    key = ftok("msgsender.c", 65);
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Get the message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    printf("\nReceiving message with flag = IPC_NOWAIT...\n");
    if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message available (IPC_NOWAIT).\n");
        } else {
            perror("msgrcv (IPC_NOWAIT)");
        }
    } else {
        printf("Received (IPC_NOWAIT): %s\n", message.msg_text);
    }

    return 0;
}

/**
 * Sample Op:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/27$ ./a.out
 * Receiving message with flag = IPC_NOWAIT...
 * Received (IPC_NOWAIT): Hello from sender!
 */
