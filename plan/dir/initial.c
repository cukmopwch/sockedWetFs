#include "../disk_mg/diskunit.h"



void initialize(strcut SuperBlock * a){
    //슈퍼블록을 통해 파일시스템을 적어놨는지 확인한다
    if(디스크조회함수()){
        //있으면 넘어가고
        a=디스크조회함수();
    }else{
        //없으면 유닛부터 디스크공간추상화까지 수행
    }
}