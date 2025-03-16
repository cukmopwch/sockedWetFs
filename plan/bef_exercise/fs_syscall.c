#include "fs_custom.h"
#include "./io_s/io_s.h"
#include <stdlib.h>
#include "file_oper.h"

//뭔가 만들었는지 안만들었는지 그것이 저자되어야 할거 같은데
int Create=0;
struct SuperBlock layout;



void fs_initialize(){
    //0.파일시스템을 구성했냐 아니면 처음인가?
    if(!Create){
        //첫 부팅 
        //안썼다.
        //1-슈퍼블록 구조체
        //?무엇이 먼저 실행되었우면 좋겠는지가 if의 1이 먼저 올지 0이 먼저올지를 결정하는 거다.
        //1.사이즈 설정
        layout.BlcokSize=Size;
        //2.전체 부분들을 설정한다..
        uint32_t disk=8*1024*1024*1024;
        uint32_t bg_sz=1024*1024*1024;
        int unit=20+512*10;
        uint32_t inode_num=bg_sz/unit;
        uint32_t block_num=10*inode_num;
        layout.totalInode=inode_num*7;
        layout.totalBlock=block_num*7;
        layout.freeInode=layout.totalInode;

        layout.BlockCount=7;

        //3.비트맵설정해보자구 아이노드와 블록
        //4.순차적으로 할당을 하고 1gb가 채워지면 다음 블록 그룹으로 가자 ㄴㄴ 접근방식은 정확히 알기 어려움...
        //얘는 구조체에 추가해야 할거 같은데
        Create=1;
        //2-블록 그룹 구조체
        layout.BlockStart=(struct BlockGroup*)malloc(sizeof(struct BlockGroup));
        for(int i=0;i<layout.BlockCount;i++){
            //근데 막상 포인터로 처리해 보려니 그냥 짜피 구조체가 할당되는것은 피할수 없는것
            //구조체정도는 인정해줘야 하나? ㄴㄴ 주소라면 ㄱㅊ 
            //두번째부터는 필요할때 할당하셈
            (layout.BlockStart+i)->inodeStart=(struct Inode*)malloc(sizeof(struct Inode));
            //?근데 너무 크긴하다 내가 시발 8gb노트북인데 아니야 숫자에 속지만 26kb밖에 안됨 ㅋㅋ 기껏해야 mb임
            //!메모리 관리는 늘 두려운 것
            //?포인터를 만들어서 그걸 32비트형의 정수에 넣어도 됨?
            (layout.BlockStart+i)->inodeBitmap=(uint8_t*)malloc(Inode_BmSz);
            (layout.BlockStart+i)->blockBitmap=(uint8_t*)malloc(Block_BmSz);

        }
        //3-루트 디렉터리 설정<함수로 빼줘야 한다.>
        layout.BlockStart->inodeStart->type="dir";
        layout.BlockStart->inodeStart->mode="r";
        layout.BlockStart->inodeStart->ctime=time();
        layout.BlockStart->inodeStart->etime="";
        layout.BlockStart->inodeStart->blockD_Start=(struct Block*)malloc(sizeof(struct Block));
        //파일 만들때마다 추가한다.
        //add_Direntry(무언가 파일);


        layout.rootdir=layout.BlockStart;
        //4-슈퍼블록 구조체랑 블록 그룹 구조체 쓰자꾸나
        disk_Write(&layout);
    }else{
        //재부팅
        disk_Read();
    }
    
}

int file_Create(char* data){
    //1.슈퍼블록에서 유효한 아이노드가 남아있냐 그리고 유효한 블록이 남아있냐?
    //2.블록 그룹을 순회한다.
    //3.블록 그룹의 아이노드 비트맵에서 비어있는 녀석을 찾는다
    //4.블록 그룹의 블록 비트맵에서 비어있는게 하나라도 있나 확인한다.
    //5.해당 아이노드를 아이노드 테이블로 가져와 블록을 할당하고 정보를 할당한다.
}

int file_Read(int inode_index){

}