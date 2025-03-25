#include "file_ops.h"

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

file_create(Superblock *sb){
    inode f;
    f.id=sb->used_inode;
    sb->used_inode=(sb->used_inode)+1;

    
}



file_read(){
    
}

file_edit(){}



file_remove(){}