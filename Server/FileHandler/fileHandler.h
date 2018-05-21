#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

void getDirFileList(int buff_size, int file_name_size, char buff[buff_size][file_name_size],char* dir_name); 
int getFileChunk(char* buff, int buff_size,FILE* file);


