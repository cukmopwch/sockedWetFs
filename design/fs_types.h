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
        
        //디스크 대여관리
        uint32_t freeInode;

        //오프셋
        uint32_t blockgroupSize;
        uint32_t blockgroupNum;


        //블록그룹 테이블
        uint32_t *Blockgroup_table;

    }Superblock;

    typedef struct{
        uint32_t *inode_Bitmap;
        uint32_t *block_Bitmap;
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

        //8개 블록의 주소<고정 4kb> 배열로 바꿔볼까? 
        uint32_t startDatablock;
        uint32_t Datablock[8];
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
        Fd_entry * next;//원형 링크로 하자
    }Fd_entry;
    
    


#endif