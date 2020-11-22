// Reference : https://www.codingninjas.com/blog/2020/07/06/learning-socket-programming-in-c/
//https://beej.us/guide/bgnet/html//index.html

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char *argv[])
{

  int fd =0, confd = 0;
  struct sockaddr_in serv_addr;

  char buff[1025];
  int num;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  printf("Server Socket created = %d\n",fd);

  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(buff, '0', sizeof(buff));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(5550);
  bind(fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
  listen(fd, 10);

  while(1)
  {
       confd = accept(fd, (struct sockaddr*)NULL, NULL);
       if (confd==-1) 
       {
            perror("Accept");
            continue;
        }
        printf("fd of connected client socket = %d",confd);
        

//File opening and writing

        FILE* fp = fopen( "provacopy.txt", "wb");
        tot=0;
        if(fp != NULL)
        {
            while( (b = recv(confd, buff, 1024,0))> 0 ) 
            {
                tot+=b;
                fwrite(buff, 1, b, fp);
            }

            printf("Received byte: %d\n",tot);
            if (b<0)
               perror("Receiving");

            fclose(fp);
        } 
        else 
        {
            perror("File");
        }
        close(confd);
    }

    return 0;
}
