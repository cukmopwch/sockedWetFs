#include "../disk_mg/diskunit.h"

struct Inode *current_d="현재 디렉터리";

char* read(char* name){

    current_d->blockD_Start= malloc()
    current_d->blockD_Start=디스크에서 블록을 가져온다()

    //한계점이 있다고 가정을 하자고 512바이트만 담을수 있다고 용량만큼 검색하자
    //핵심은 아이노드 주소를 찾는거야
    int start=0;
    for(int i=0;i<용량;i++){
        if (current_d->blockD_Start[i]==' '){
            memcpy(*current_d->blockD_Start[start],어딘가,i-start);
            //디렉터리 엔트리 디스크에서 가져오기
            temp=malloc()
            temp=디스크에서 엔트리를 가져옴()
            if(temp->name == name){
                break;
            }
            start=i+1;
        }

    }
    //아이노드를 할당한다.
    struct Inode *파일해당=malloc()
    파일해당=디스크에서 해당아이노드 가져옴()
    파일해당->blockD_Start=malloc()
    파일해당->blockD_Start=디스크에서 데이터블록 가져옴()

    //데이터를 임시저장한다.
    char* data;
    *data=*파일해당->blockD_Start
    //할당한거 없앤다
    free(temp)
    free(파일해당->blockD_Start)
    return data;
}