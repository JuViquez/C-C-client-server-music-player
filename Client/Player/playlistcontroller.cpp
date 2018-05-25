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
#include <iostream>
#include <arpa/inet.h>
#include <vector>
#include <algorithm>
#include <cstdio>

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
    printf("\n set sockets \n");
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
            songsList.push_back(fileList[i]);
        }
     }
     //close(sockfd);
     return 1;
}

int PlaylistController::GetSong(){
    try{
        FILE *fp;
        int bytesReceived = 0;
        fp = fopen(currentSong.c_str(), "ab");
            if(NULL == fp){
                printf("Error opening file");
                return -1;
            }
       long double sz=1;
       int buff[1] = {2};
       write(sockfd, buff, 1);
       write(sockfd, currentSong.c_str(), 100);
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
    }catch(...){
        return -1;
    }
}

void PlaylistController::RemoveSongFromPlaylist(int songIndex){
    queueplayList.erase(queueplayList.begin()+songIndex);
}

void PlaylistController::ShufflePLaylist(){
    std::random_shuffle ( queueplayList.begin(), queueplayList.end() );
}

void PlaylistController::AddSongToPlaylist(string songTitle){
    //FALTA BUSCAR LAS REPETIDAS
    songsList.push_back(songTitle);
}

void PlaylistController::RemoveSongFile(){
    if(!currentSong.empty()){
        remove(currentSong.c_str());
        printf("Borrando cancion");
        currentSong = "";
    }
}


int PlaylistController::PlayNextSong(){
    printf("PlayNextSong %d \n",currentIndexSong);
    for(std::string &s : queueplayList){
        printf("SONG %s \n",s.c_str());
    }
    if(queueplayList.size()-1 != currentIndexSong){
        printf("Primer IF %s siguiente cancion \n",queueplayList[currentIndexSong+1].c_str());
        if(queueplayList[++currentIndexSong] != currentSong ){
            RemoveSongFile();
            currentSong = queueplayList[currentIndexSong];
            return GetSong();
        }
        return 1;
    }
    return -1;
}

