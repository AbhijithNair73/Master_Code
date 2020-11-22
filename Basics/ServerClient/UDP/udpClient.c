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
	int sfd =0, n=0, b;
	char rbuff[1024]={0};
	char sendbuffer[1024]={0};

	struct sockaddr_in client_addr, server_addr;

	memset(rbuff, '0', sizeof(rbuff));
	memset(sendbuffer, '0', sizeof(sendbuffer));

	sfd = socket(AF_INET, SOCK_DGRAM, 0);
	//printf("client socket created = %d",sfd);


	//  connect
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(5550);
	client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	socklen_t clientSize = sizeof(client_addr);
	while(1)
	{
		printf("\nClient = ");
		fgets(sendbuffer,1024,stdin);
		int valsent = sendto(sfd,sendbuffer,sizeof(sendbuffer), 0, (struct sockaddr *)&client_addr, clientSize);
		int valread = recvfrom( sfd ,rbuff, sizeof(rbuff), 0, (struct sockaddr *)&client_addr, &clientSize); 
		printf("\nServer = %s",rbuff ); 
		
	}
	return 0;
}
