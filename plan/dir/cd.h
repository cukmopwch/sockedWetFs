#ifndef CD_H
    #define CD_M 1
    #include <stdint.h>
    struct current_dir{
        char name[10];
        uint32_t inode;
        struct current_dir *prev;
        struct current_dir *next;
    };
#endif