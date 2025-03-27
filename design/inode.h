#ifndef INODE_H
    #define INODE_H 1
    #include "fs_types.h"
    
    uint32_t find_InodeId_fromDirEntry(Inode* subjectDir,char* filename);
    Inode* find_Inode_fromBlockGroup(Inode* Inode,uint32_t Inodeid);
#endif