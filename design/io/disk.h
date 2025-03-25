#ifndef IO_DISK_H
    #define IO_DISK_H 1
    int serialize_data(void *buff,const void* data);
    int deserialize_data();
    int read_content_fromInode();
    int disk_write();
    int allocate_block(char* buf,uint32_t disk_cell);
    int allocate_inode(inode* node,uint32_t disk_cell,char* buff);
#endif