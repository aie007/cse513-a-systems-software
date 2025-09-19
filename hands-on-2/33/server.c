#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char buf[1024];
	char *message = "hello from server";
	struct sockaddr_in serv, cli;

	sd = socket (AF_INET, SOCK_STREAM, 0);

	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons (5050);
	
	bind (sd, &serv, sizeof (serv));
	listen (sd, 5);
	
	nsd = accept (sd, &cli, &sizeof (cli));
	int n = read(nsd, buf, sizeOf(buf));
	

	return 0;
}
