#include <stdint.h>
#include <stdio.h>
#include "design/fs_init.h"
#include "design/fs_types.h"
#include "directory.h"
#include <string.h>

//파일 디스크립터 id할당관리
#define Mx_FdId 256
#define Fd_BitmapSize (Mx_FdId / 8)



int main(){
    int go=1;
    char* buffer;
    char alphabet;
    Superblock sBlock;
    Inode rootDir;
    Inode currentDir; 
    Fd_table* fdTail=malloc();
    unsigned char fd_bitmap[Fd_BitmapSize];

    //파일디스크립터id할당 초기화
    memset(fd_bitmap,0,Fd_BitmapSize);
    
    
    //파일 시스템을 초기화한다.
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