#include "inode.h"
/*
* 이 파일은 아이노드의 처리와 관련된 파일이다.
*
*
*
*
*
*
*
*
*/

int allocate_fdId(unsigned char *buffer){
    /*파일 디스크립터 엔트리 번호를 할당한다.*/
    int byte_index;
    int bit_index;

    for(int i=0;i<256;i++){
        byte_index=i/8;
        bit_index=i%8;
        if(!(buffer[byte_index] & (1 << bit_index))){
            //만약 해당 비트가 비어있다면 i값을 fdId로 준다
            buffer[bit_index] |= (1 << bit_index);
            return i;
        }
    }
    

}

uint32_t find_InodeId_fromDirEntry(Inode* subjectDir,char* filename){
    /*해당하는 디렉터리의 아이노드 id를 얻어온다*/

    //데이터 블록 공간을 디스크에서 읽는다.
    Datablock dirChild=read_content_fromInode();


    for(int i=0;i<500;i++){
        //해당하는 디렉터리의 아이노드id를 찾는다.
        if(temp->name==dirName){
            printf("Found DirName: %s",dirName);
            return temp->inode_id;
        }
    }
    return -1;
}

Inode* find_Inode_fromBlockGroup(Inode* Inode,uint32_t Inodeid){
    /*블록그룹에서 아이노드를 찾아낸다.*/
    if(Inodeid==-1){
        //아이노드id를 찾기를 실패하거나 더 이상 없으면 -1을 리턴한다
        return -1;
    }
    
    for(int i=0;i<8;i++){
        //각 블록 그룹을 순회하며 아이노드를 찾는다
        for(int t=metadata+총블록개수*i;t<(t+아이노드개수);t++){
            Inode *temp=malloc(sizeof(Inode));
            temp=disk_read(t);
            if(temp->id==Inodeid){
                return temp;
            }
        }
    }
}