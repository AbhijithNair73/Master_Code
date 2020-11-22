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
	server_fd = socket(AF_INET,SOCK_STREAM,0);
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
	
	if(listen(server_fd, 10) < 0 ) //Accepts 10 connections
	{
		perror("listen"); 
		exit(EXIT_FAILURE); 
	}
	
	newSocket_fd = accept(server_fd, (struct sockaddr *)&clientAddr, &serverSize);
	if(newSocket_fd<0)
	{
		perror("accept"); 
		exit(EXIT_FAILURE); 
	}
		printf("Client Details:\n");
	printf("Client port = %u\n",ntohs(clientAddr.sin_port));
	printf("Client IP = %s\n",inet_ntoa(clientAddr.sin_addr));
	while(1)
	{
		int valread = recv( newSocket_fd , recBuffer, sizeof(recBuffer), 0); 
		printf("\nClient = %s",recBuffer ); 
		printf("\nSever = ");
		fgets(sendBuffer,1024,stdin);
		int valsent = send(newSocket_fd,sendBuffer,sizeof(sendBuffer), 0);
	}

	return 0;
}
