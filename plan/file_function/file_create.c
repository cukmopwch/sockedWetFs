#include "../disk_mg/diskunit.h"

int file_create(char* data){
//슈퍼블록의 Unused확인 
    if(!슈퍼블록 구조체.freeInode){
        //없으면 에러 (용량 부족)
    }


    //각각 블록그룹 조회
    for(int i;i<슈퍼블록.BlockCount;i++){
        if(슈퍼블록.BlockStart[i].비트맵위치<조작으로 알아냤다>){
            //*해당 아이노드를 할당한다
            슈퍼블록.BlockStart[i].inode[비트맵위치]=malloc()
            //*멤버들쓰고
            슈퍼블록.BlockStart[i].inode[비트맵위치].type=파일이다;
            슈퍼블록.BlockStart[i].inode[비트맵위치].mode=읽기 가능하다;
            기타등등
            //블록을 할당 받는다.
            슈퍼블록.BlockStart[i].inode[비트맵위치].blockD_Start[블록비트맵위치]=malloc();
            슈퍼블록.BlockStart[i].inode[비트맵위치].blockD_Start[블록비트맵위치]=data;
            //*아이노드 구조체랑 블록 구조체를 써준다 테이프처럼
            디스크에쓰기(슈퍼블록.BlockStart[i].inode[비트맵위치],크기);
            디스크에쓰기(슈퍼블록.BlockStart[i].inode[비트맵위치].blockD_Start[블록비트맵위치],크기);
            //*할당해제한다.
            슈퍼블록.BlockStart[i].inode[비트맵위치].free();
            슈퍼블록.BlockStart[i].inode[비트맵위치].blockD_Start[블록비트맵위치].free();
            return 0;
        }
        if(i==6){
            //마지막까지 반응이 없으면 망했엉 ㅠㅠ
            //에러<용량 부족>
            return -1;
        }
        }
}
