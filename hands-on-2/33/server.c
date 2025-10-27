/**
 * Program: 33 (server.c)
 * Author: Aieshah NAsir
 * Description: Write a program to communicate between two machines using socket.
 * Date: 01/10/2025
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(void) {
    	int socktd = socket(AF_INET, SOCK_STREAM, 0);
    	if (socktd == -1) {
        	perror("Error when creating socket");
    		exit(1);
	}
    	printf("server Socket created\n");

    	struct sockaddr_in server, client;
    	server.sin_addr.s_addr = htonl(INADDR_ANY); // host to network long
    	server.sin_family = AF_INET;
    	server.sin_port = htons(8080);

    	int bindS = bind(socktd, (struct sockaddr *)&server, sizeof(server));
    	if (bindS == -1) {
        	perror("Error while binding name to socket");
        	exit(1);
    	}
    	printf("Binding to server socket was successful!\n");

    	// listen for connection
    	int listenS = listen(socktd, 2);
    	if (listenS == -1) {
        	perror("Error while trying to listen for connections");
        	exit(1);
    	}
    	printf("Listening from Connection ");

    	int client_size = (int)sizeof(client);
    	int connectionfd = accept(socktd, (struct sockaddr *)&client, &client_size);
    	if (connectionfd == -1) {
        	perror("error while accepting connection");
        	exit(1);
    	}
    	else {
        	char buf[100];
        	printf("Write massage form server to client: ");
        	scanf("%[^\n]", buf);
        	// write fron server to connection fd
        	write(connectionfd, buf, sizeof(buf));

        	read(connectionfd, buf, 100);
        	printf("Data from client: %s\n", buf);
    	}

    	// closing socket
    	close(socktd);
}

/**
 * Sample op:
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/33$ ./server
 * server Socket created
 * Binding to server socket was successful!
 * Listening from Connection Write massage form server to client: hi i am server
 * Data from client: hello
 * 
 * nasir@nasir-HP-Pavilion-Laptop-14-dv0xxx:~/Documents/hands-on-2/33$ ./client
 * Socket created
 * hello
 * Connection with server establishedData from server: hi i am server
 * Write massage for server: Data sent to server
 */
