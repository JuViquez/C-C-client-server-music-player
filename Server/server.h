#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>


struct sockaddr_in c_addr;
void* attendClient(int* arg);
void SendFileListToClient(int connfd);
void SendFileToClient(int connfd,char* fname);

