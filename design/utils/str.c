#include "str.h"

char * remove_firstMem(char* buffer){
    int i=0;
    while(*(buffer++)=='\n'){
        buffer[i]=buffer[i+1];
    }
    return buffer;
}

char** delimit(char** buffer,char* delimiter){

}