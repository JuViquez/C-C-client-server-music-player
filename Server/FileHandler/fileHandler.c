#include "fileHandler.h"

void getDirFileList(int buff_size, int file_name_size, char buff[buff_size][file_name_size],char* dir_name){
  DIR *d;
  struct dirent *dir;
  d = opendir(dir_name);
  if (d) {
    for( int i = 0; i < buff_size; i++){
       if((dir = readdir(d)) != NULL){
	if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0){
		strcpy(buff[i],dir->d_name);
	}else i--;
       }else {
	break;
       }
    }
    closedir(d);
  }
}


int getFileChunk(char* buff, int buff_size,FILE* file){
   return fread(buff,1,buff_size,file);
}



