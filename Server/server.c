#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include "./FileHandler/fileHandler.h"
#include <time.h>


struct sockaddr_in c_addr;

void writeToLog(char* line){
    FILE *log = fopen("log.txt", "at");
    if (!log) log = fopen("log.txt", "wt");
    if (!log) {
        printf("can not open logfile.txt for writing.\n");
    }
    else{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	fprintf(log, "%d-%d-%d %d:%d:%d --- %s\n", tm.tm_year + 1900, 
	        tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, line);
    	fclose(log);
    }

}


int VerifyUser(char* username, char* password){
    FILE* usersFile = fopen ("users.csv", "r");
    char line[100] = {0};
    char user[50] = {0};
    char pass[50] = {0};
    while (fgets(line, 100, usersFile))
    {
	sscanf(line, "%[^,],%[^,]", user, pass);
	printf("%s - %s\n", user, pass);
        if(strcmp(username, user) == 0 && strcmp(password,pass) == 0){
            fclose(usersFile);
            return 1;}
    }     
    fclose(usersFile);
    return 0;
}

void SendFileListToClient(int connfd, char* username){
	char logMsg[100] = {0};
	char fileList[10][100] = {{0}};

	getDirFileList(10, 100, fileList,"./songs"); //retrieve the list of files from the dir "songs"
	write(connfd, fileList, sizeof(fileList)); // send file list to client
	
	strcpy(logMsg, "File list Sent to user: ");
    	strcat(logMsg, username);
    	writeToLog( logMsg );
}

void SendFileToClient(int connfd,char* fname, char* username)
{
        FILE *fp = fopen(fname,"rb");
	char logMsg[100] = {0};

        if(fp==NULL)
        {
            printf("File open error\n");
	    fflush(stdout);
        }else{

        /* Read data from file and send it */
		while(1)
		{
		    /* First read file in chunks of 256 bytes */
                    unsigned char buff[32768]={0};
                    int nread = getFileChunk(buff,32768,fp);
		    printf("Bytes read %d \n", nread);
		    fflush(stdout);

		    /* If read was success, send data. */
		    if(nread > 0)
		    {
		        printf("Sending %s... \n", fname);
			fflush(stdout);
		        write(connfd, buff, nread);
		    }
                    if (nread < 32768)
		    {
		        if (feof(fp))
			{
		            printf("End of file\n");
			    printf("File transfer completed for id: %d\n",connfd);
			    fflush(stdout);
			    sprintf(logMsg, "File %s sent to %s", fname, username);
			    writeToLog( logMsg );
			}
		        if (ferror(fp))
		            printf("Error reading\n");
			    strcpy(logMsg, "Error reading for user: ");
			    strcat(logMsg, username);
			    writeToLog( logMsg );
		        break;
		    }
		}
	}
}

void* attendClient(int* arg){
	char fname[100] = {0};
	char fullpath[255] = {0};
	int connfd=(int)*arg;
	int option[1] = {1};
 	char logMsg[100] = {0}; //variables
	char strNum[10];
	char user[50] = {0};
	char password[50] = {0};
 	
	printf("Connection accepted and id: %d\n",connfd);
      	printf("Connected to Client: %s:%d\n",inet_ntoa(c_addr.sin_addr),ntohs(c_addr.sin_port));
	strcpy(logMsg, "Connection aceepted and id: ");
	sprintf(strNum, "%d", connfd);
	strcat(logMsg, strNum);
	writeToLog( logMsg );
	
	while (option[0] != 0){
                memset(fullpath, 0, 255);
                memset(fname, 0, 100);
                memset(option,0,1);
		printf("waiting for client option\n");
		if(read(connfd, option, 1) <= 0) break;
		printf("Client Chosed Option: %d\n",option[0]);
		fflush(stdout);
		switch (option[0]){
			case 0:
				break;
			case 1: //send filelist to client
				SendFileListToClient(connfd, user);
				
				break;
			case 2: //send mp3 to client
				read(connfd, fname, sizeof(fname));
				strcpy(fullpath,"./songs/");
				strcat(fullpath, fname);
				SendFileToClient(connfd, fullpath, user);
				break;
			case 3: //send image to client
				read(connfd, fname, sizeof(fname));
                                strcpy(fullpath,"./images/");
				strcat(fullpath, fname);
				SendFileToClient(connfd, fullpath , user);
				break;
                        case 4: //Authentication
                           
				read(connfd, user, sizeof(user));
				read(connfd, password, sizeof(password));
				fflush(stdout);
				int verification[1] = {0};
				verification[0] = VerifyUser(user,password);
                                if (verification[0]){
					sprintf(logMsg, "Open Connection with User: %s",user);	
					printf("%s\n",logMsg);
					fflush(stdout);}
				else{
					sprintf(logMsg, "Access denied to User: %s",user);
					printf("%s\n",logMsg);
					fflush(stdout);}			
				writeToLog(logMsg);
				write(connfd, verification, 1);
                                break;
		}
	}
        memset(logMsg,0,sizeof(logMsg));
	sprintf(logMsg, "Closing Connection for user: %s", user);
	writeToLog(logMsg);
	printf("Closing Connection for id: %d\n",connfd);
	close(connfd);
	shutdown(connfd,SHUT_WR);
	sleep(2);
}



int main(int argc, char *argv[])
{
    int connfd = 0,err;
    pthread_t tid;
    struct sockaddr_in serv_addr;
    int listenfd = 0,ret;
    size_t clen=0;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd<0)
	{
	  printf("Error in socket creation\n");
	  exit(2);
	}
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int)) < 0)
    	error("setsockopt(SO_REUSEADDR) failed");

    printf("Socket retrieve success\n");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(6000);

    ret=bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
    if(ret<0)
    {
      printf("Error in bind\n");
      exit(2);
    }

    if(listen(listenfd, 10) == -1)
    {
        printf("Failed to listen\n");
        return -1;
    }

else
    while(1)
    {
        clen=sizeof(c_addr);
        printf("Waiting for clients...\n");
        connfd = accept(listenfd, (struct sockaddr*)&c_addr,&clen);
        if(connfd<0)
        {
	  printf("Error in accept\n");
	  continue;
	}
        err = pthread_create(&tid, NULL, &attendClient, &connfd);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
   }
    close(connfd);
    return 0;
}
