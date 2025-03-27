#include "utils/path.h"
#include "utils/str.h"
#include "io/disk.h"
#include "inode.h"

/*
* 이 파일은 디렉터리의 이동과 관련된 파일이다.
*
*
*
*
*
*
*
*
*/







Inode get_tagetDirInode(Inode startInode,char** pathList){
    /*최하위 디렉터리의 아이노드를 얻는다*/
    Inode* targetDir=&startInode;
    Inode temp;
    int i=0;
    while (!find_Inode_fromBlockGroup(targetDir,find_dirInodeId_fromDirEntry(targetDir,pathList[i])))
    {   
        //하위 디렉터리로 매번 내려간다.
        temp=*targetDir;
        i++;
        
    }
    return temp;
}



int change_currentDir(Inode* currentDir,Inode startDir,char* path){
    /*디렉터리를 변경한다.*/
    
    if(!currentDir){
        //초기 현재 디렉터리는 루트 디렉터리로 한다.
        *currentDir=startDir;
        return 0;
    }
    //경로를 쪼갠다.
    char* slicedPath[]=slice_path(path);


    /*반복해야할거같은데*/
    Inode foundInode=get_tagetDirInode(startDir,slicedPath);
    *currentDir=foundInode;
    return 0;
}
