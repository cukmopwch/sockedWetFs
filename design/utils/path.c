#include "path.h"
#include "str.h"
#include <string.h>

/*
 *path.h:
 *경로와 관련된 반복 사용될 루틴을 모아놓았다.
 *
 *
*/

char* check_PathType(char* path){
    /*절대경로인지 상대경로인지 확인한다.*/
    if(path[0]=='.'){
        path=remove_firstMem(path);
        return '.';
    }
    else if (path[0]=='/'){
        path=remove_firstMem(path);
        return '/';
    }
    return ' ';
}

search_dirEntry(Inode* subjectDir){
    Datablock temp=disk_read();
    //###1.캐스팅하는 과정이 필요해 여기부터 그리고 해당 아이노드 번호 찾는거 file.c에 넣어야 할듯

}

Inode get_wantedDirInode(Inode startInode,char* path){
    Inode* searchingDir=&startInode;
    while (searchingDir)
    {
        
    }
    
}