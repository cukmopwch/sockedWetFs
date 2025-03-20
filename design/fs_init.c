#include "fs_init.h"
#include "io/disk.h"
#include <stddef.h>
#include "directory.h"
//존재하는지 확인
check_superblock(){

}

read_superblock(){

}


int get_metadata_size(Superblock *fs,int n){
    fs->metadata_size=fs->superb_size+n*fs->block_size;
    return 0;
}

uint32_t get_inode_size(){
    uint32_t inode_num=1;
    uint32_t datablock_num=8;
    uint32_t totalBlock=(1*1024*1024*1024)/(512*(inode_num+datablock_num));
    uint32_t block_num=(totalBlock*8)/9;
    uint32_t inode_times=block_num/9;
    return inode_times;
}

//파일시스템 생성
int format_filesystem(Superblock *a,uint32_t disk_size){

    //1.기본 설정 및 파티션을 위한 오프셋 완료
    a->block_size=512;
    a->disk_size=disk_size;
    a->superb_size=sizeof(Superblock);
    a->block_size=sizeof(Blockgroup);
    //메타데이터 오프셋과 데이터 오프셋을 구한다
    if(!get_metadata_size(a,8)){
        printf("failed. Wrong");
    }
    /*파일*/
    a->inode_num=get_inode_size();
    a->block_num=8*a->inode_num;

    //2-0.메타데이터 쓰기 블록0에
    /****************메타데이터 파티션쓰기******************** */
    //직렬화해라 메타데이터(슈퍼블록+블록그룹)
    void* buffer=malloc(a->metadata_size);    
    if(a->metadata_size>512){
        //더 할당해야
        //아니라면 
    }else{
        //메타데이터를 위한 블록이 한개일때
        if(serialize_metadata(buffer,a)){
            //7개의 블록그룹을 넣는 작업을 해라
        }else{
            //뭔가 문제 생김
        }
        //직력화된 데이터를 블록 1개에 써라
        if(!disk_write(buffer,0)){

        }
    }
    //2-1.루트 디렉터리 생성 및 블록에 쓰기 번호1 

    Inode *root_i;
    root_i=malloc(sizeof(root_i));

    root_i->ctime=1120;
    root_i->utime=1125;
    root_i->id=2;
    root_i->mode=0x4180;
    root_i->Datablock=2;
    
    if(write_inode_to_disk(root_i,1,NULL)){

    }

    //3.초기 현재 디렉터리 설정
    change_currentDirectory(NULL,*root_i,NULL);
    
}

int fs_init(Superblock* sBlock,Inode* rootDir,Inode* current_Dir){
    if(check_superblock()){
        //디스크에 superblock이 있다면 파일시스템도 있다
        read_superblock();
    }else{
        if(!format_filesystem(sBlock,512)){
            printf("FS Formating failed");
            return 1;
        }
       
    }

    return 0;
}