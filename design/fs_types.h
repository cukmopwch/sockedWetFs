#ifndef FS_TYPES_H
    #define FS_TYPES_H 1
    #include <stdint.h>
/*
* 헤더파일
* 이 파일은 SockedWet파일시스템을 위한 핵심 구조체를 저장하는 헤더파일이다
*
*
*
*
*
*
*
*
*/


    typedef struct {
        /*슈퍼블록을 정의한다.*/
        
        //루트 디렉터리의 디스크 번호
        uint32_t rootDir;

        //디스크 대여
        uint32_t used_inode;

        uint32_t data_offset;

        //디스크 유닛 및 개수
        uint32_t disk_size;//gb단위로 8gb면 8
        uint32_t block_size;
        uint32_t superb_size;

        //오프셋
        uint32_t metadata_size;
        uint32_t block_group_num;
        uint32_t inode_num;
        uint32_t block_num;

        //블록그룹 테이블
        uint32_t Blockgroup_table;

    }Superblock;

    typedef struct{
        uint32_t inode_Bitmap;
        uint32_t block_Bitmap;

        uint32_t inode_table;
        uint32_t inode_per_group;
    }Blockgroup;

    typedef struct{
        /*아이노드를 정의한다*/

        //아이노드 번호, id
        uint32_t id;
        //파일인지 디렉터리인지,권한
        uint16_t mode;
        //생성및 마지막 사용시간
        uint32_t ctime;
        uint32_t utime;

        //8개 블록의 주소<고정 4kb>
        uint32_t Datablock;
    }Inode;

    typedef struct {
        /*데이터 블록을 정의한다.*/
        uint32_t inode_id;
        char data[512];
    }Datablock;

    typedef struct 
    {   
        /*디렉터리 엔트릐를 저장한다.*/
        //총 5바이트로
        char name[32];
        uint32_t inode_id;
    }Dir_entry;

    typedef struct 
    {
        int fd;
        Inode file;
        Fd_table * next;//원형 링크로 하자
    }Fd_table;
    
    


#endif