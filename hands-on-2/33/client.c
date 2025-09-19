#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(void) {
	char buf[1024];
	char *hello = "hello, server! i'm the client!";
	struct sockaddr_in serv;
	sd = socket (AF_INET, SOCK_STREAM, 0);

	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr (“ser ip”);
	serv.sin_port = htons (5050);

	connect (sd, &server, sizeof  (server));
	int n = read(sd, );

	return 0;
}
