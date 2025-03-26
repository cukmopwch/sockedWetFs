#include "file_ops.h"
#include "fs_types.h"

/*
* 이 파일은 파일의 이동과 관련된 파일이다.
*
*
*
*
*
*
*
*
*/

Inode get_targetFileInode(Inode* currentDir,char** pathList){

}





int file_open(char* filename,Fd_table* oldTail){
    /*파일을 연다*/

    //아이노드를 찾는다
    Inode targetFile = get_targetFileInode();

    //파일 디스크립터 테이블에 추가한다.
    Fd_table *tail=malloc();
    tail->next=oldTail->next;
    oldTail->next=tail;

    //$$$$까다롭다
    tail->fd=???;
    tail->file=targetFile;

    return tail->fd;
}

file_edit(){}
 file_create(Superblock *sb){
    inode f;
    f.id=sb->used_inode;
    sb->used_inode=(sb->used_inode)+1;

    
}


file_remove(){}