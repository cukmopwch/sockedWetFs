#include "path.h"
#include "str.h"

char* check_PathType(char* path){
    if(path[0]=='.'){
        path=remove_firstMem(path);
        return '.';
    }
    else if (path[0]=='/'){
        path=remove_firstMem(path);
        return '/';
    }
    return ' ';
}

Inode lookupDirInode(Inode startInode,char* path){
    
}