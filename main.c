#include <stdint.h>
#include <stdio.h>

int main(){
    uint32_t inode_num=1;
    uint32_t datablock_num=8;
    uint32_t block_num=(1*1024*1024*1024)/(9*(inode_num+datablock_num));

    printf("%u.\n",block_num);

}