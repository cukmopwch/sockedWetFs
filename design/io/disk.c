#include "io_disk.h"

//쓰기전에 하나로 합친다
int serialize_metadata(void *buff,const void* data){

}

int disk_write(){

}

int allocate_block(char* buf,uint32_t disk_cell){
    disk_write();
}

int write_inode_to_disk(inode* node,uint32_t disk_cell,char* buff){
    uint32_t block_num;
    if(!disk_cell){
        disk_cell=find_free_inode();
    }
    if(!set_disk_allocated()){
        //실패했어영
    }

    if(disk_write(*node,disk_cell)){
        //실패했어영
    }
    if((block_num=find_free_block())==null){
        //실패했어영
    }
    if(!set_disk_allocated(block_num)){
        //실패했어영
    }
    //디스크에 블록 쓰기
    
    if (allocate_block(buff,a->inode_num+8*(block_num-1)))
    {
        /* code */
    }
    
}