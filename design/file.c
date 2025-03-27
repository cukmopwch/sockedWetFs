#include "file_ops.h"
#include "fs_types.h"
#include <stddef.h>

/*
* 이 파일은 파일의 처리와 관련된 파일이다.
*
*파일을 열고 
*
*
*
*
*
*
*/

int add_fd_entry(Fd_table* currentFdTail,Inode* file){
    /*파일 디스크립터 테이블에 항목을 추가한다.*/

    //파일 디스크립터 테이블에 추가한다.
    Fd_table *newFdTail=malloc();
    newFdTail->next=currentFdTail->next;
    currentFdTail->next=newFdTail;

    //$$$$까다롭다
    tail->fd=allocate_fdId();
    tail->file=file;
    
    return fd
}

int remove_fd_entry(){

}

Inode get_targetFileInode(Inode* currentDir,char* filename){
    /*해당 파일의 아이노드를 리턴한다.*/

    Inode* targetInode=malloc();
    targetInode=find_Inode_fromBlockGroup(NULL,find_InodeId_fromDirEntry(currentDir,pathList[i]));
    return*targetInode;
}





int file_open(char* filename,Fd_table* oldTail){
    /*파일을 연다*/

    //아이노드를 찾는다
    Inode targetFile = get_targetFileInode();
    int fd=add_fd_entry(targetFile);
    

    return fd;
}

int file_close(int fd,Fd_table* oldTail){
    /*파일을 닫는다.*/
}


/**************************************** 유틸리티 ******************************
 * 
 * 
 * 파일의 생성 그리고 읽기, 쓰기, 삭제 전부 모아둔다.
 * 
 * 
 * 
 * 
*/

file_read(){
    /*문자로 파일을 직접 읽어온다.*/
}

file_edit(){}


int file_create(Superblock *sb){
    /*파일을 만든다.*/
    inode f;
    f.id=sb->used_inode;
    sb->used_inode=(sb->used_inode)+1;

    
}

file_remove(){}