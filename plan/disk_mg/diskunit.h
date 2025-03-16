#ifndef FS_CUSTOM_H 
    #define FS_CUSTOM_H 1
    #include <stdint.h>
    #define Size 512
    #define Inode_C 208899
    #define Inode_BmSz ((Inode_C+7)/8)
    #define Block_C Inode_C*10
    //이 값은 수정되어야 한다.
    #define Block_BmSz ((Block_C+7)/8)

    //내가 볼때 uint_32한 이유가 쉽게 용량을 유추하려는 의도인듯
    //42바이트
    struct SuperBlock
    {   
        uint32_t BlcokSize;
        uint32_t totalBlock;
        uint32_t totalInode;
        uint32_t freeInode;

        //이녀석 inode
        uint32_t rootdir;

        //uint32_t BlockGroup[7];
        //생각해보면 배열로 하기보다 그냥 수로 넣고 인덱스를 설정하는게 나을듯하다
        struct BlockGroup* BlockStart;
        uint32_t BlockCount;
    };

    struct BlockGroup
    {
        //어느것을 이용할까를 
        uint32_t inodeBitmap;
        uint32_t blockBitmap;
        //엄청난 아이노드 테이블 크기는 문제다 지연로딩하라는데 와닿지는 않네.
        //208899개의 아이노드가 있는것은 사실이지만 그것을 담기 어렵기에 배열보다 포인터로 관리하는것...
        //!아이노드 테이블이냐 아이노드 시작점과 개수냐
        //uint32_t inodetable;
        struct Inode* inodeStart;
        //!inode count는 const값 고정값이니 
        //uint32_t inodeCount;
        
        
    };

//20바이트
    struct Inode
    {   
        //파일이냐 디렉터리냐
        uint32_t type;
        //권한 쓰기 읽기 실행
        uint32_t mode;
        uint32_t ctime;
        uint32_t etime;
        struct Block* blockD_Start;
    };

    struct Block
    {
        uint8_t dd[Size];
    };

    struct DirectoryEntry
    {
        uint32_t inode_num;
        char name[512];
    };
    
    
    
    

#endif