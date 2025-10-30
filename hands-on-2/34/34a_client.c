/**
 * Program: 34a_client.c
 * Author: Aieshah Nasir
 * Description: program to create a concurrent server.
 *     		a. use fork
 * Date: 01/10/2025 
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>

void main(void) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Erroe when creating socket");
        _exit(0);
    }
    printf("Socket created\n");

    // assigning server info
    struct sockaddr_in address;
    address.sin_addr.s_addr = htonl(INADDR_ANY); // host to network short
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    // make connection to the server
    int conn = connect(sockfd, (struct sockaddr *)&address, sizeof(address));

    if (conn == -1)
    {
        perror("Error while establishing Connection\n");
        _exit(0);
    }

    printf("Connection with server established\n");

    char buf[100];
    // read fron server
    read(sockfd, buf, 100);
    printf("Data from server: %s\n", buf);

    printf("Write message for server from client: \n");
    scanf("%[^\n]", buf);

    write(sockfd, buf, sizeof(buf));
    printf("Data sent to server\n");

    // closing socket
    close(sockfd);
}
