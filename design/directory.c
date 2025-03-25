#include "utils/path.h"
#include "utils/str.h"
#include "io/disk.h"

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

uint32_t find_dirInodeId_fromDirEntry(Inode* subjectDir,char* dirName){
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

Inode* find_dirInode_fromBlockGroup(Inode* dirInode,uint32_t dirInodeid){
    /*블록그룹에서 아이노드를 찾아낸다.*/
    if(dirInodeid==-1){
        //아이노드id를 찾기를 실패하거나 더 이상 없으면 -1을 리턴한다
        return -1;
    }
    
    for(int i=0;i<8;i++){
        //각 블록 그룹을 순회하며 아이노드를 찾는다
        for(int t=metadata+총블록개수*i;t<(t+아이노드개수);t++){
            Inode *temp=malloc(sizeof(Inode))
            temp=disk_read(t);
            if(temp->id){
                dirInode
                return temp
            }
        }
    }
}



Inode get_tagetDirInode(Inode startInode,char** pathList){
    /*최하위 디렉터리의 아이노드를 얻는다*/
    Inode* targetDir=&startInode;
    Inode temp;
    int i=0;
    while (!find_dirInode_fromBlockGroup(targetDir,find_dirInodeId_fromDirEntry(targetDir,pathList[i])))
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
