#ifndef FS_INIT_H
    #define FS_INIT_H

    #include "fs_types.h"

    int fs_init(Superblock* sBlock,Inode* rootDir,Inode* current_Dir);

#endif