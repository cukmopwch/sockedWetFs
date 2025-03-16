#ifndef FS_TYPES_H
    #define FS_TYPES_H 1
    #include <stdint.h>
    typedef struct {
        uint32_t used_inode;

        uint32_t data_offset;

        //오프셋을 구하기 위한 parameter
        uint32_t disk_size;
        uint32_t block_size;
        uint32_t total_block;

        uint32_t superb_size;
        uint32_t block_size;

        //오프셋들
        uint32_t metadata_size;
        uint32_t inode_num;
        uint32_t block_num;



        //루트 디렉터리의 디스크 번호
        uint32_t rootDir;

        uint32_t Blockgroup_table;
    }Superblock;

    typedef struct{
        uint32_t inode_Bitmap;
        uint32_t block_Bitmap;

        uint32_t inode_table;
        uint32_t inode_per_group;
    }Blockgroup;

    typedef struct{
        //아이노드 번호
        uint32_t id;
        //파일인지 디렉터리인지
        uint16_t mode;

        //생성및 마지막 사용시간
        uint32_t ctime;
        uint32_t utime;
        //8개 고정 4kb
        uint32_t Datablock;
    }inode;

    typedef struct {
        uint32_t inode_id;
        char data[512];
    }Datablock;

    typedef struct 
    {   
        //총 5바이트로
        char name[8];
        uint32_t inode_id;
    }Dir_entry;
    


#endif