//This is loopback(127.0.0.1)(Loopback IP) linux based chat application

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main()
{
	int server_fd, newSocket_fd;
	char recBuffer[1024]={0};
	char sendBuffer[1024]={0};
	struct sockaddr_in serverAddr, clientAddr;
	server_fd = socket(PF_INET,SOCK_DGRAM,0);
	if(server_fd < 0)
	{
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	//printf("Socket created for server = %d",server_fd);


	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	//serverAddr.sin_addr.s_addr = INADDR_ANY;
	// serverAddr.sin_addr = htols(INADDR_LOOPBACK);
	serverAddr.sin_port = htons(5550);
	memset(serverAddr.sin_zero,'\0',sizeof(serverAddr.sin_zero));
	socklen_t serverSize = sizeof(clientAddr);

	if( bind (server_fd, (struct sockaddr *)&serverAddr,serverSize) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		int valread = recvfrom( server_fd , recBuffer, sizeof(recBuffer),0,(struct sockaddr *)&clientAddr, &serverSize);
		printf("\nClient = %s",recBuffer );
		printf("\nSever = ");
		serverSize = sizeof(clientAddr);
		fgets(sendBuffer,1024,stdin);
		int valsent = sendto(server_fd,sendBuffer,sizeof(sendBuffer), 0,  (struct sockaddr *)&clientAddr, serverSize);
	}

	return 0;
}
