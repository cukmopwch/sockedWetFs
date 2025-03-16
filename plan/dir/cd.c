#include "../disk_mg/diskunit.h"

//디렉터리 변경에 관한 이야기를 담자

//얘는 메인 가야할듯
struct current_dir default
struct current_dir root;

//현재디렉터리를 기본설정한다
initialize_cd(){
    root.name='/'
    root.inode=SuperBlock.rootdir;
    root.prev=0;
    default=root;
}

//현재 디렉터리를 변경한다
update_cd(){
    struct current_dir*b=malloc();
    root->next =b;
    b->prev=root;
    //문제점 디폴트가 뭔지를   해결 하나의 변수를 만듬
    default=b;

}

//디스크에서 가져오는 부분을 구현한다
disk_approach(struct inode *a){
    a=디스크에서 inode구조체가져오기();
    데이터 블록 위치=디스크의 데이터 블록 가져오기(a->BlockStart);
}

//ls 기능

list_all(){
    int start=0;
    struct inode *a
    disk_approach(a);

    for(int i=0;i<len(데이터 블록 위치))
    if(데이터 블록 위치[i]==','){
        memcpy(*데이터 블록위치[start],담을 위치,i-start)
        //각 파일이나 디렉터리 출력
        print(담을 위치)
    }
}

//Cd 기능을 구현한다.

cd(char *dir){
    struct inode *a
    disk_approach(a);
    
    for(int i=0;i<len(데이터 블록 위치))
    if(데이터 블록 위치[i]==','){
        memcpy(*데이터 블록위치[start],담을 위치,i-start)
        //각 파일이나 디렉터리 출력
        if(담을위치==dir){
            update_cd(dir,inode)
        }
    }
}