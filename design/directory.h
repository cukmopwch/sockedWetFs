#ifndef DIRECTORY_H 
    #define DIRECTORY_H
/*
* 헤더파일
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
    
    uint32_t find_dirInodeId_fromDirEntry(Inode* subjectDir,char* dirName);

    Inode* find_dirInode_fromBlockGroup(Inode* dirInode,uint32_t dirInodeid);

    Inode get_tagetDirInode(Inode startInode,char** pathList);

    int change_currentDir(Inode* currentDir,Inode startDir,char* path);
#endif