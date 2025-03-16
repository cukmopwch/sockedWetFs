#include "file_ops.h"

file_create(Superblock *sb){
    inode f;
    f.id=sb->used_inode;
    sb->used_inode=(sb->used_inode)+1;

    
}



file_read(){}

file_edit(){}



file_remove(){}