//
// Created by Aurora on 2021/12/12.
//

#ifndef MY_FILE_SYSTEM_FS_OPERATION_H
#define MY_FILE_SYSTEM_FS_OPERATION_H
#include "fs_config.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <time.h>
enum cmdType
{
    my_ls_t,
    my_mkdir_t,
    my_format_t,
    my_open_t,
    my_exit_t,
    my_cd_t,
    my_create_t,
    my_rmdir_t,
    my_write_t,
    my_read_t,
    my_rm_t,
    my_close_t,
    my_help_t

};
enum fileType
{
    diretory_file,
    data_file,
    undefine_file//未知文件
};
enum seek_Type
{
    my_SEEK_SET,
    my_SEEK_CUR,
    my_SEEK_END
};
/*全局变量区域
 *
 */
useropen openfilelist[MAX_OPEN_FILE];//文件打开表
fs_size_t currfd;//当前文件指针
file_cache fs_TLB[MAX_FILE_CACHE];//0为超级块，1为块位图，2为索引节点位图，3为块组描述符,4~ROOT_DIR_END为根目录，其他为用户cache
int old_cache_address;//简易cache调度策略，先进先出
/*功能选择
 *
 *
 */
void start_fs(void);

void my_mkdir(char *filename);//jjx
void my_create(char *filename);

void my_format(void);//plt

void my_ls(void);//lly

void my_exit(void);//cjs

void my_cd(char *filename);//zyt
void my_open(char *filename);


void my_read(int fd);//zym

void my_write(int fd);//xc

void my_rm(char *filename);//xfh
void my_rmdir(char *filename);

void my_close(int fd);
void my_help(void);

/*********************初始化函数*******************************/
void init_openfile(void);//从虚拟磁盘载入根目录，超级块等必要块
void init_root_dir_inode(void);//初始化根目录索引节点，并存入fs_TLB
void init_inode(fs_size_t i_node_num,int node_type);//初始化i节点
void get_time(uint16_t *date_time,uint16_t *day_time);//获取时间
void output_time(uint16_t data_time,uint16_t time);//输出时间
/********************初始化函数*******************************/


/********************目录管理函数******************************
 *
 *
 *
 */
void show_dir_entry(dir_block *temp_dir);//显示目录文件
int check_filename_is_right(i_node *inode,char *filename);//检查重名
void get_filename_correct(char *filename,char  *cut_filename);//获取合法文件名
int check_filename_in_block_is_right(dir_block *dir_block,char *filename);//检查某一个块内的目录项是否重名
void copy_entry_to_openfile_list(fs_size_t fd,fcb dir_entry);//将目录项置入文件打开表
void search_and_copy_entry_to_openfilelist(char *filename,int fileType);//查找并打开文件或目录
void search_and_create_entry_to_block(char *filename,int fileType);//创建对应类型文件
int save_dir_entry_to_block(char *filename,offset_t block_address,fs_size_t fileType);//将目录项保存至该数据块
/********************目录项管理函数*******************************/


/*****************核心分配函数*******************
 *以下函数主要功能在于将多级索引的索引块的块和数据数据载入cache
 * 并且返回指向该数据块的索引块的指针（已含块内偏移量
 *
 * @param i_node_block_num 块编号
 * @param inode   索引节点
 * @return offset 指向分配块的控制块
 */
offset_t *allocation_block_to_inode(fs_size_t i_node_block_num,i_node *inode);//分配数据块
offset_t *get_address_i_node_block(fs_size_t i_node_block_num,i_node *inode);//获取数据块状态
offset_t *allocation_block_level1_to_inode(offset_t block_level1_address,fs_size_t block_num_in_level1);//分配数据块
offset_t *get_address_i_node_level1_block(offset_t block_level1_address,fs_size_t block_num_in_level1);//获取数据块状态
int select_cmd(char *cmd);//选择命令
int get_free_block(void);//获取空块
int get_free_Inode(void);//获取新索引节点

void come_to_other_GDT(fs_size_t move_to_GDT_num);//切换至其他块组
offset_t get_Inode_address(fs_size_t inode);//获取索引节点绝对地址
offset_t get_Block_address(fs_size_t block);//获取索引节点绝对地址
offset_t searche_cache(offset_t address);//搜索是否存在cache


/*********************核心分配函数***************************/


/********************文件同步函数*******************************/
void save_block_to_cache(void *cache,offset_t cahce_address);//更新cache
void update_super_block(fs_size_t modify_num);//磁盘上所有超级块与处于第i块组的超级块同步
void update_GDT_block(fs_size_t modify_num);//磁盘上所有i号块组描述符进行同步
void save_cache_to_file(fs_size_t cache_num);//保存cache i时使用
void get_block_from_file(offset_t block_address,void  *cache);//从文件读出块
void save_inode_to_file(offset_t inode_address,i_node *src_inode);//将索引节点保存至文件
void get_inode_from_file(offset_t inode_address,i_node *dst_inode);//从文件中取出inode
/********************文件同步函数*******************************/


/*********************文件释放函数*******************************/
void rm_block_in_bitmap(offset_t block_address);//修改索引节点位图
void rm_inode_in_bitmap(fs_size_t inode_num);//修改块位图
void rm_search_file_and_delete(char *filename);//查找目录项并执行删除操作
void rm_inode(fs_size_t inode_num,fs_size_t fileType);//删除目录项索引节点
void rm_data_file(fs_size_t inode_num);//删除数据文件索引节点
void rm_dir_file(fs_size_t inode_num);//删除目录文件索引节点
void rm_dir_in_block(fs_size_t block_num,i_node *temp_inode);//删除目录文件某个数据块内的所有目录项
void rm_data_file_in_block(fs_size_t block_num,i_node *temp_inode);//删除数据文件数据块
int check_dir_in_block_is_empty(offset_t block_num,i_node *temp_inode);//确认目录项是否为空
int select_Type_of_file(char *file_exam);//判断文件类型
/*********************文件释放函数*******************************/

/*********************文件读写函数*******************************/
void read_message_in_block(fs_size_t offset_end,offset_t block_address);//显示某一个数据块从第i位开始的数据
void my_seek(fs_size_t len,int cmd_Type,fs_size_t max_len,int fd);//重定位
/*********************文件读写函数*******************************/
#endif //MY_FILE_SYSTEM_FS_OPERATION_H
