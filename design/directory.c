#include "utils/path.h"
#include "utils/str.h"


set_currentDirectory(){

}

int change_currentDirectory(Inode* currentDir,Inode baseDir,char* path){
    Inode foundInode=lookupDirInode(baseDir,path);
    *currentDir=foundInode;
    return 0;
}