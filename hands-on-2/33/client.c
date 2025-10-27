/**
 * Program: 33 (client.c)
 * Author: Aieshah Nasir
 * Description: Write a program to communicate between two machines using socket
 * Date: 01/10/2025
 */

#include <sys/types.h>
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>
#include <stdlib.h>
     
void main(void) {
    	int socktd=socket(AF_INET,SOCK_STREAM,0);
    	if(socktd==-1){
        	perror("Error when creating socket");
    		exit(1);
	}
    	printf("Socket created\n");

    	// assigning server info
   	 struct sockaddr_in address;
    	address.sin_addr.s_addr=htonl(INADDR_ANY);//host to network short
    	address.sin_family=AF_INET;
    	address.sin_port=htons(8080);

    	// make connection to the server
    	int connectionS = connect(socktd, (struct sockaddr *)&address, sizeof(address));

    	if(connectionS==-1){
        	perror("Error while establishing connection");
    		exit(1);
	}
    
    	printf("Connection with server established");

    	char buf[100];
    	// read fron server
    	read(socktd,buf,100);
    	printf("Data from server: %s\n",buf);

    	printf("Write massage for server: ");
    	scanf("%[^\n]",buf);

    	write(socktd,buf,sizeof(buf));
    	printf("Data sent to server");

    	// closing socket
    	close(socktd);
}
