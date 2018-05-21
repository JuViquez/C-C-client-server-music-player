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
void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }
int main(int argc, char *argv[])
{
    system("clear");
    int sockfd = 0;
    int bytesReceived = 0;
    char recvBuff[1024];
    memset(recvBuff, '0', sizeof(recvBuff));
    struct sockaddr_in serv_addr;

    /* Create a socket first */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }

    /* Initialize sockaddr_in data structure */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6000); // port
    char ip[50];
if (argc < 2) 
{
    printf("Enter IP address to connect: ");
    gets(ip);
}
else
  strcpy(ip,argv[1]);

    serv_addr.sin_addr.s_addr = inet_addr(ip);

    /* Attempt a connection */
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    }

    printf("Connected to ip: %s : %d\n",inet_ntoa(serv_addr.sin_addr),ntohs(serv_addr.sin_port));

   	 /* Create file where data will be stored */
   	FILE *fp;
	char fname[100] = "prueba cliente";
	//read(sockfd, fname, 256);
	printf("File Name: %s\n",fname);
	printf("Receiving file...");
   	 fp = fopen(fname, "ab"); 
    	if(NULL == fp)
    	{
       	 printf("Error opening file");
         return 1;
    	}
    long double sz=1;
    /* Receive data in chunks of 256 bytes */
    int buff[1] = {2};
    write(sockfd, buff, 1);
    char* h = "hola.txt";
    write(sockfd, "hola.txt", 100);
   while((bytesReceived = read(sockfd, recvBuff, 1024)) > 0)
    { 
	if(bytesReceived == 1 && recvBuff[0] == 0)break;
        sz++;
        gotoxy(0,4);
        printf("Received: %llf Mb",(sz/1024));
	fflush(stdout);
        fwrite(recvBuff, 1,bytesReceived,fp);
	
    }
     sleep(1);
     buff[0]=1;
     write(sockfd, buff, 1);
     buff[0] = 1;
     write(sockfd, buff, 1);
     char fileList[10][100] = {{0}};
     read(sockfd, fileList, sizeof(fileList));
     for (int i = 0; i<10; i++){
	printf("%s\n", fileList[i]);
	}

    if(bytesReceived < 0)
    {
        printf("\n Read Error \n");
    }
    printf("\nFile OK....Completed\n");
    close(sockfd);
    return 0;
}
