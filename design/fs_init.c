#include "fs_init.h"
#include "io/disk.h"
#include <stddef.h>
#include "directory.h"
//존재하는지 확인
check_superblock(){

}

read_superblock(){

}

void init_blockgroup(Superblock *a,uint32_t position){
    /*블록그룹을 설정한다.*/
    Blockgroup *temp=malloc();

    int inodeNum,blockNum;
    inodeNum=cal_size();
    blockNum=a->blockgroupSize-1-inodeNum;

    temp->inode_Bitmap=malloc(sizeof(uint32_t)*inodeNum);
    temp->block_Bitmap=malloc(sizeof(uint32_t)*blockNum);

    //이부분문제
    disk_write(temp,position);

    free(temp->inode_Bitmap);
    free(temp->block_Bitmap);
    free(temp);

    return;
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

    //1.superblock설정
    init_superblock();

    a->Blockgroup_table=malloc(sizeof(uint32_t)*a->blockgroupNum);

    //2.블록그룹 개수만큼 쓰기
    for(int i=0;i<a->blockgroupNum;i++){
        a->Blockgroup_table[i]=i*(a->blockgroupSize);
        init_blockgroup(a,a->Blockgroup_table[i]);
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