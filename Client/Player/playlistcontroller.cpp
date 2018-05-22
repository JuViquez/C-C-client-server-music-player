#include "playlistcontroller.h"
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
#include <vector>

PlaylistController::PlaylistController()
{
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
    }else{
        printf("\n Socket creado \n");
        memset(recvBuff, '0', sizeof(recvBuff));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(6000); // port
        char ip[50];
        strcpy(ip,"127.0.0.1");
        serv_addr.sin_addr.s_addr = inet_addr(ip);
    }
}

void PlaylistController::SetSockets(){
    printf("\n Error : Could not create socket2 \n");
}

int PlaylistController::GetSongsList(){
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
            printf("\n Error : Connect Failed \n");
            return -1;
    }
    int buff[1] = {1};
    write(sockfd, buff, 1);
    char fileList[10][100] = {{0}};
    read(sockfd, fileList, sizeof(fileList));
    for (int i = 0; i<10; i++){
        if(strlen(fileList[i])){
            printf("%s\n", fileList[i]);
            queueplayList.push_back(fileList[i]);
        }
     }
     //close(sockfd);
     return 1;
}

int PlaylistController::GetSong(char* songName){
    char cwd[1024];
       if (getcwd(cwd, sizeof(cwd)) != NULL){
           fprintf(stdout, "Current working dir: %s\n", cwd);}
    FILE *fp;
    int bytesReceived = 0;
    char fname[100] = "clienteFile2.mp3";
    //read(sockfd, fname, 256);
    printf("File Name: %s\n",fname);
    printf("Receiving file...");
    fp = fopen(fname, "ab");
        if(NULL == fp){
            printf("Error opening file");
            return 1;
        }
   long double sz=1;
   /* Receive data in chunks of 256 bytes */
   int buff[1] = {2};
   write(sockfd, buff, 1);
   write(sockfd, songName, 100);
   while((bytesReceived = read(sockfd, recvBuff, 1024)) > 0)
    {
        sz++;
        printf("Received: %llf Mb",(sz/1024));
        fflush(stdout);
        fwrite(recvBuff, 1,bytesReceived,fp);
        if(bytesReceived < 1024) break;
    }
   close(sockfd);
   return 1;
}
