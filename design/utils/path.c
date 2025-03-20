#include "path.h"
#include "str.h"
#include <string.h>

/*
 *path.h:
 *경로와 관련된 반복 사용될 루틴을 모아놓았다.
 *
 *
*/

char** slice_path(char* path){
    /*절대경로인지 상대경로인지 확인하고 경로를 쪼갠다*/
    //첫문자는 지웠고 
    if(path[0]=='.' || path[0]=='/'){
        path=remove_firstMem(path);
    }

    char *slicedPath[]=delimit(path,'/');

    return slicedPath;
}