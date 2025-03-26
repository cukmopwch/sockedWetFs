#include <stdint.h>
#include <stdio.h>
#include "design/fs_init.h"
#include "design/fs_types.h"
#include "directory.h"

int main(){
    int go=1;
    char* buffer;
    char alphabet;
    Superblock sBlock;
    Inode rootDir;
    Inode currentDir; 
    Fd_table openedfile;
    
    if(fs_init(&sBlock,&rootDir,&currentDir)){
        printf("failed....");
        return 1;
    }
    while(go){
        while (alphabet=입력())
        {
            if(alphabet!='\n'){
                printf(alphabet);
                buffer+=alphabet;
            }else{
                if(buffer="cd"){
                    change_currentDirectory("경로");
                }
            }
        }
        
    }
}