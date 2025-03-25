#include "io_disk.h"

int bIn(){

}

int bOut(){

}

//쓰기전에 하나로 합친다
int serialize_data(void *buff,const void* data){
    /*데이터 직렬화*/
}

int deserialize_data(){
    /*데이터 역직렬화*/
    //오프셋을 임시저장할 변수가 필요하고 배열의 최대는 메시지의 최대다
    Dir_entry* temp=(Dir_entry*)dirChild;
    // 요런 느낌이였던거 같은데
    switch (type)
    {
    case 1:
        /* char이다 */
        break;
    case 2:
        /* Inode다 */
        break;
    default:
        break;
    }
}

int read_content_fromInode(){
    /*아이노드에서 데이터블록을 읽어낸다*/
    char *buffer=disk_read()
    //요런 루틴이 필요할거 같은데
    Datablock dirChild=disk_read(subjectDir->Datablock);
   
}

int disk_read(){
    /*디스크에서 직접적으로 읽어온다.*/
    int limit;
    while(limit){
        //문자인지 구조체인지 판단을 해야지
        deserialize_data(bIoRead());
    }
    
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