#ifndef MY_FILE_SYSTEM_FS_CONFIG_H
#define MY_FILE_SYSTEM_FS_CONFIG_H

//数据类型定义
typedef int uint32_t;
typedef uint32_t offset_t;
typedef uint32_t fs_size_t;
typedef unsigned short uint16_t;

//Inode设置
#define PER_BLOCK_GROUP_INODE_MAX_NUM 1024//索引节点数量
#define INODE_FREE 0//空索引
#define INODE_BUSY 1//已分配索引
#define INODE_NOT_USE 255//保留节点
#define ROOT_INODE_NUM 2//根目录索引节点
#define INODE_SIZE 128//索引节点大小
#define PER_BLOCK_INODE_NUM (BLOCKSIZE/INODE_SIZE)//一个块的节点数量
#define BG_INODE_TABLE_BLOCK_NUM (PER_BLOCK_GROUP_INODE_MAX_NUM/PER_BLOCK_INODE_NUM)//索引节点存储需要花费块数量

//最大打开文件数
#define MAX_OPEN_FILE 10
#define MAX_FILE_CACHE 16
#define ROOT_DIR_BEGIN 4
#define ROOT_DIR_BLOCK 2
#define ROOT_DIR_END (ROOT_DIR_BEGIN+ROOT_DIR_BLOCK)
//索引节点
#define DIRECT_BLOCK_NUM 12//直接索引
#define SMALL_BLOCK_NUM (DIRECT_BLOCK_NUM+1)//1级索引
#define MID_BLOCK_NUM (SMALL_BLOCK_NUM+1)//2级索引
#define BIG_BLOCK_NUM (MID_BLOCK_NUM+1)//3级索引
#define ACTUAL_BLOCK_NUM BIG_BLOCK_NUM//总索引数量
//文件控制块
#define FCB_SIZE 32
#define EXAMNAME_SIZE 4//扩展名字
#define MAX_FILE_NAME 8//最大文件名长度
#define CHECK_NUM_SIZE 9//校验码长度
#define MAX_DIR_BLOCK_FCB_NUM (BLOCKSIZE/FCB_SIZE)//一个块存储多少个目录项
//目录文件
#define DIR_MAX_LEN 80
//必要文件数据
#define FILENAME "zdz_fs"
#define FILE_TYPE_MSG "ext2_likely_fs"
#define CHECK_BLOCK0 "10011101"//引导块校验码
#define CHECK_SUPER_BLOCK "01101100"//超级块校验码

//文件类型
#define DIRECTORY_FILE_EXNAME "dir"
#define DATA_FILE_EXNAME "dat"
//文件大小，块数量设置
#define BLOCKSIZE 1024
#define BLOCK_GROUP_NUM 2//块组数量
#define BLOCK_FREE 0//空闲块
#define BLOCK_BUSY 1//已分配块
#define MAX_BLOCK_IN_INODE (DIRECT_BLOCK_NUM+1*BLOCKSIZE/sizeof(offset_t))//一个索引节点最大存储数据块数量
#define PER_BLOCK_GROUP_BLOCK_MAX_NUM 1024//每个块组中的块数量
#define BLOCK_GROUP_SIZE (PER_BLOCK_GROUP_BLOCK_MAX_NUM*BLOCKSIZE)//块组大小
#define FS_TOTAL_SIZE (1+BLOCK_GROUP_SIZE*BLOCK_GROUP_NUM)//文件系统总大小
#define PER_BLOCK_GROUP_INIT_BLOCK (1+2+BG_INODE_TABLE_BLOCK_NUM+BLOCK_GROUP_NUM)
//常用定义

#define ERR_FAIL (-1)
#define ERR_OK 0
typedef struct FCB
{
    char filename[MAX_FILE_NAME];
    char examname[EXAMNAME_SIZE];
    fs_size_t free;//目录项是否为空，0为空，1为已分配
    fs_size_t i_node_num;
}fcb;
typedef struct FCB_Inode
{
    unsigned char file_Type;//0目录文件，1是数据文件
    uint16_t create_time;//文件创建时间
    uint16_t create_data;//文件创建日期
    uint16_t modified_time;//文件修改时间
    uint16_t modified_data;//文件修改日期
    fs_size_t length;//文件长度,目录项文件长度表示占用的块的数量，数据文件的文件长度才是真实的文件长度
    offset_t i_block[ACTUAL_BLOCK_NUM];//3级目录，0~12直接地址，13是一级索引，14是2级索引，15是三级索引
}i_node;

typedef struct USEROPEN
{
    char filename[MAX_FILE_NAME];
    char examname[EXAMNAME_SIZE];
    fs_size_t inode_num;
    char dir[DIR_MAX_LEN];//文件目录
    int count;//指针读写位置
    char file_open_free;//打开表项是否为空，空为0，占用为1

}useropen;
typedef struct SUPER_BLOCK
{
    char check_string[CHECK_NUM_SIZE];
    fs_size_t all_free_block;
    fs_size_t all_free_Inode;
    fs_size_t root_inode;//根目录索引节点
    fs_size_t per_block_group_block_free_num[BLOCK_GROUP_NUM];
    fs_size_t per_block_group_Inode_free_num[BLOCK_GROUP_NUM];
    offset_t super_block0_start_address;//每个块组起始位置

}super_block;

typedef struct BLOCK0//引导块
{
    char check_string[CHECK_NUM_SIZE];
    char information[200];
    struct FCB root;//根目录FCB
    offset_t super_block0_address;

}block0;

typedef struct GROUP_Description_Table_Block
{
    fs_size_t block_group_num;//块组描述符编号
    fs_size_t block_group_free_block;//空闲块数量
    fs_size_t block_group_free_inode;//空闲索引节点数量
    offset_t block_group_description_address;//当前GDT位置
    offset_t super_block0_address;//每个块组中超级块存储位置
    offset_t Block_Bitmap_address;//块节点位图
    offset_t Inode_Bitmap_address;//索引节点位图
    offset_t Inode_Save_address;//索引节点数据库偏移地址
    offset_t data_start_block_address;//数据块偏移地址

}GDT;
typedef struct File_cache
{
    offset_t block_address;//块地址
    char file_cache[BLOCKSIZE];//块缓存
    uint16_t input_time;//放入cache时间
    uint16_t cache_state;//0为默认，1为修改

}file_cache;
typedef struct Directory_BLOCK
{
    fcb dir_entry[MAX_DIR_BLOCK_FCB_NUM];
}dir_block;

typedef GDT group_Description_Table_Block;
#endif //MY_FILE_SYSTEM_FS_CONFIG_H
