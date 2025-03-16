#include <stdint.h>
#include <stdio.h>
#include "design/fs_init.h"
#include "design/fs_types.h"

int main(){

    if(fs_init()){
        printf("failed....");
        return 1;
    }
}