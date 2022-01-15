//
// Created by Aurora on 2021/12/12.
//
#include "fs_operation.h"
void my_format(void)
{
    old_cache_address=ROOT_DIR_END;//初始化用户cache编号为起始位置
    //申请一个块组的空间用来初始化（只有1MB，极大优化文件系统初始化占用的内存
    //不用增加设置提高程序运行占用的堆栈空间真不错
    char *my_virtual_hard=(char *) malloc(BLOCK_GROUP_SIZE);
    //初始化全局变量
    memset(fs_TLB,0,sizeof(fs_TLB));
    memset(openfilelist,0,sizeof (openfilelist));
    memset(my_virtual_hard,0,BLOCK_GROUP_SIZE);
    //打开文件并释放之前占用的空间
    FILE *file;
    file= fopen(FILENAME,"wb+");
    //初始化引导块
    block0 *temp_block0=(block0*)my_virtual_hard;
    strcpy(temp_block0->check_string,CHECK_BLOCK0);
    strcpy(temp_block0->information,FILE_TYPE_MSG);
    temp_block0->super_block0_address= BLOCKSIZE;
    //初始化根目录文件控制块
    temp_block0->root.i_node_num=ROOT_INODE_NUM;
    strcpy(temp_block0->root.filename,"root");
    strcpy(temp_block0->root.examname,DIRECTORY_FILE_EXNAME);

    fwrite(temp_block0,BLOCKSIZE,1,file);

    //开始初始化块组
    memset(my_virtual_hard,0,BLOCK_GROUP_SIZE);
    //初始化超级块
    super_block *temp_super_block0=(super_block*)(my_virtual_hard);
    strcpy(temp_super_block0->check_string,CHECK_SUPER_BLOCK);
    temp_super_block0->all_free_Inode=PER_BLOCK_GROUP_INODE_MAX_NUM*BLOCK_GROUP_NUM-3;
    temp_super_block0->all_free_block=PER_BLOCK_GROUP_INODE_MAX_NUM*BLOCK_GROUP_NUM-PER_BLOCK_GROUP_INIT_BLOCK*BLOCK_GROUP_NUM;
    for(int i=0;i<BLOCK_GROUP_NUM;i++)
    {
        temp_super_block0->per_block_group_Inode_free_num[i]=PER_BLOCK_GROUP_INODE_MAX_NUM;
        temp_super_block0->per_block_group_block_free_num[i]=PER_BLOCK_GROUP_BLOCK_MAX_NUM-PER_BLOCK_GROUP_INIT_BLOCK;
        if(i==0)
            temp_super_block0->per_block_group_Inode_free_num[i]-=3;
    }
    temp_super_block0->root_inode=ROOT_INODE_NUM;
    temp_super_block0->super_block0_start_address=BLOCKSIZE;
    //初始化块组0的0号块组描述符
    group_Description_Table_Block *temp_group_description0=(GDT *)(my_virtual_hard+BLOCKSIZE*3);
    temp_group_description0->block_group_num=0;
    temp_group_description0->super_block0_address=0;
    temp_group_description0->Block_Bitmap_address=temp_group_description0->super_block0_address+BLOCKSIZE;
    temp_group_description0->Inode_Bitmap_address=temp_group_description0->Block_Bitmap_address+BLOCKSIZE;
    temp_group_description0->block_group_description_address=temp_group_description0->Inode_Bitmap_address+BLOCKSIZE;
    temp_group_description0->Inode_Save_address=temp_group_description0->block_group_description_address+BLOCKSIZE*BLOCK_GROUP_NUM;
    temp_group_description0->data_start_block_address=temp_group_description0->Inode_Save_address+BLOCKSIZE*BG_INODE_TABLE_BLOCK_NUM;
    temp_group_description0->block_group_free_block=PER_BLOCK_GROUP_BLOCK_MAX_NUM-PER_BLOCK_GROUP_INIT_BLOCK;
    temp_group_description0->block_group_free_inode=PER_BLOCK_GROUP_INODE_MAX_NUM-3;
    //初始化块组0的其他块组描述符
    for(int i=1;i<BLOCK_GROUP_NUM;i++)
    {
         char *dst_gdt;
         char *src_gdt;
        src_gdt=temp_group_description0->block_group_description_address+my_virtual_hard;
        dst_gdt=src_gdt+BLOCKSIZE*i;
        memcpy(dst_gdt,src_gdt,BLOCKSIZE);
        GDT *dst_gdt_block=(GDT *)dst_gdt;
        dst_gdt_block->block_group_num=i;
        dst_gdt_block->block_group_description_address+=BLOCKSIZE;
        dst_gdt_block->block_group_free_inode=PER_BLOCK_GROUP_INODE_MAX_NUM;
    }

    //初始化块位图0，分配系统必要占据的块
    char *dst_gdt;
    for(int i=0;i<(1+BLOCK_GROUP_NUM+2+BG_INODE_TABLE_BLOCK_NUM);i++)//超级块+GDT+块位图+节点位图+节点保存块
    {
        dst_gdt=my_virtual_hard + temp_group_description0->Block_Bitmap_address + i;
        memset(dst_gdt, BLOCK_BUSY, sizeof(unsigned char));
    }
    //保留0~1号索引节点
    for(int i=0;i<ROOT_INODE_NUM;i++) {
        dst_gdt=my_virtual_hard + temp_group_description0->Inode_Bitmap_address + i;
        memset(dst_gdt, INODE_NOT_USE,sizeof(unsigned char));
    }

    //设置根目录索引节点
    memset(my_virtual_hard+temp_group_description0->Inode_Bitmap_address+ROOT_INODE_NUM,INODE_BUSY,sizeof (unsigned char));
    fwrite(my_virtual_hard,BLOCK_GROUP_SIZE,1,file);
    //清除块位图和索引节点位图
    memset(my_virtual_hard+temp_group_description0->Inode_Bitmap_address,INODE_FREE,BLOCKSIZE);
    memset(my_virtual_hard+temp_group_description0->Block_Bitmap_address,BLOCK_FREE,BLOCKSIZE);
    //拷贝整个块组
    for(int i=1;i<BLOCK_GROUP_NUM;i++)
        fwrite(my_virtual_hard,BLOCK_GROUP_SIZE,1,file);
    fclose(file);
    free(my_virtual_hard);
    printf("format success!\n");

}
offset_t get_Block_address(fs_size_t block)
{
    //获取超级块
    super_block *temp_super_block=(super_block *)fs_TLB[0].file_cache;
    //计算此块所在块组以及在块组内的位置
    offset_t tp;
    offset_t block_GDT,block_num_in_bitmap;
    block_GDT=block/PER_BLOCK_GROUP_BLOCK_MAX_NUM;
    block_num_in_bitmap=block%PER_BLOCK_GROUP_INODE_MAX_NUM;
    //如果大于最大块组号，则返回
    if(block_GDT>=BLOCK_GROUP_NUM)
    {
        printf("overflow block you can get!\n");
        return -1;
    }
    //计算绝对地址
    tp=temp_super_block->super_block0_start_address+BLOCK_GROUP_SIZE*block_GDT;
    tp+=block_num_in_bitmap*BLOCKSIZE;
    return tp;
}
offset_t get_Inode_address(fs_size_t inode)
{
    //获取超级块
    super_block *temp_super_block=(super_block *)fs_TLB[0].file_cache;
    //获取索引节点块组及其在块组中位置
    offset_t tp;
    offset_t inode_GDT,inode_num_in_bitmap;
    inode_GDT=inode/PER_BLOCK_GROUP_INODE_MAX_NUM;
    inode_num_in_bitmap=inode%PER_BLOCK_GROUP_INODE_MAX_NUM;
    //如果大于最大块组号
    if(inode_GDT>=BLOCK_GROUP_NUM)
    {
        printf("overflow inode you can get!\n");
        return -1;
    }
    //计算绝对地址
    tp=temp_super_block->super_block0_start_address+BLOCK_GROUP_SIZE*inode_GDT;//定位块组
    GDT *temp_gdt=(GDT *)fs_TLB[3].file_cache;
    tp=tp+temp_gdt->Inode_Save_address+INODE_SIZE*inode_num_in_bitmap;
    return tp;

}
void my_ls(void)
{
    offset_t inode_address;
    //校验操作合法性
    if(!strcmp(openfilelist[currfd].examname,DATA_FILE_EXNAME))
    {
        printf("you can not use ls in data file!\n");
        return;
    }
    //获取索引节点
    inode_address=get_Inode_address(openfilelist[currfd].inode_num);
    i_node *temp_inode=(i_node *) malloc(INODE_SIZE);
    get_inode_from_file(inode_address,temp_inode);
    //如果该索引节点未被分配过数据块
    if(temp_inode->i_block[0]==0) {
        printf("inital inode :%d\n",openfilelist[currfd].inode_num);
        init_inode(openfilelist[currfd].inode_num, 0);
        get_inode_from_file(inode_address, temp_inode);
    }
    //输出目录
    int i;
    int err;
    //遍历所有目录数据块
    for(i=0;i<temp_inode->length;i++)
    {
        //将数据块载入至cache
        get_address_i_node_block(i,temp_inode);
        err=searche_cache(temp_inode->i_block[i]);
        //输出数据块
        show_dir_entry((dir_block *)fs_TLB[err].file_cache);
    }
    free(temp_inode);

}
void start_fs(void)
{
    FILE *file=NULL;
    int i;
    //校验文件合法性
    char temp_fs_start[CHECK_NUM_SIZE];
    file=fopen(FILENAME,"rb+");
    //初始化全局变量
    memset(fs_TLB,0,sizeof (fs_TLB));
    old_cache_address=ROOT_DIR_END;
    //打开文件系统文件
    if(file!=NULL)
    {
        //获取文件系统存储文件起始地址字符串
        fread(temp_fs_start,CHECK_NUM_SIZE,1,file);

        //校验是否为文件系统文件
        if(!strcmp(temp_fs_start,CHECK_BLOCK0)) {
            printf("find correct fs_file!\n");
            //fseek(file,BLOCKSIZE,SEEK_SET);
            //fwrite("123",3,1,file);
            //获取0号块组超级块状态
            fseek(file,BLOCKSIZE,SEEK_SET);
            fread(temp_fs_start,CHECK_NUM_SIZE,1,file);
            fseek(file,-CHECK_NUM_SIZE,SEEK_CUR);
            //查找可用超级块
            for(i=0;i<BLOCK_GROUP_NUM;i++)
            {
                //printf("%d\n",i);
                //校验i号块组超级块状态
                if(!strcmp(temp_fs_start,CHECK_SUPER_BLOCK)) {
                    printf("find can use super block!\n");
                    break;
                }
                //printf("check num:%s offset is :%lu\n",temp_fs_start, ftell(file));
                //获取i+1号块组超级块
                fseek(file,BLOCK_GROUP_SIZE,SEEK_CUR);
                fread(temp_fs_start,CHECK_NUM_SIZE,1,file);
                fseek(file,-CHECK_NUM_SIZE,SEEK_CUR);

            }
            fclose(file);
            //超级块全部损坏
            if(i>=BLOCK_GROUP_NUM)
            {
                printf("super block is all destoryed!\n");
                my_format();
            }
            else if(i>0) {
                update_super_block(i);//将可用超级块同步至所有块组
            }
        }
        else {//引导块校验错误，格式化文件
            fclose(file);
            printf("try format ths fs_file\n");
            my_format();
        }
    }
    else//未找到文件系统存储文件，创建文件
    {
        printf("can not find virtual fs!try create a fs_file.\n");
        my_format();
    }
    //初始化文件打开表
    init_openfile();
}
void save_block_to_cache(void *cache,offset_t cahce_address)
{
    //将被覆盖的cache存储至文件
    save_cache_to_file(old_cache_address);
    //复制数据块至cache，设置cache信息
    memcpy(fs_TLB[old_cache_address].file_cache,cache,BLOCKSIZE);
    fs_TLB[old_cache_address].cache_state=0;
    fs_TLB[old_cache_address].block_address=cahce_address;
    fs_TLB[old_cache_address].input_time=0;
    //更新下一个被覆盖的cache的位置
    old_cache_address=old_cache_address+1;
    if(old_cache_address>=MAX_FILE_CACHE)
    {
        old_cache_address=old_cache_address%MAX_FILE_CACHE+ROOT_DIR_END;
    }

}
void save_cache_to_file(fs_size_t cache_num)
{
    FILE *file;
    file= fopen(FILENAME,"rb+");

    //检查cache是否被更新过
    if(fs_TLB[cache_num].cache_state)
    {
        fseek(file,fs_TLB[cache_num].block_address,SEEK_SET);
        fwrite(fs_TLB[cache_num].file_cache,BLOCKSIZE,1,file);
    }
    //初始化cache状态
    fs_TLB[cache_num].cache_state=0;
    fclose(file);

}
void init_openfile(void)
{
    block0 *init_block0=(block0 *) malloc(BLOCKSIZE);
    int i;
    FILE *file;
    //获取引导块
    file=fopen(FILENAME,"rb");
    fseek(file,0,SEEK_SET);
    fread(init_block0,BLOCKSIZE,1,file);
    //将根目录载入文件打开表
    printf("wait to open root dir!\n");
    strcpy(openfilelist[0].filename,init_block0->root.filename);
    strcpy(openfilelist[0].dir,"\\root");
    strcpy(openfilelist[0].examname,init_block0->root.examname);
    openfilelist[0].count=0;
    openfilelist[0].inode_num=init_block0->root.i_node_num;
    free(init_block0);
    //读入超级块、0号块组描述符、块位图、索引节点位图
    char temp_block_group[(BLOCKSIZE*4)];
    fread(temp_block_group,(BLOCKSIZE*4),1,file);
    //设置全局变量
    for(i=0;i<4;i++)
    {
        memcpy(fs_TLB[i].file_cache,temp_block_group+BLOCKSIZE*i,BLOCKSIZE);
        fs_TLB[i].input_time=0;
        fs_TLB[i].block_address=BLOCKSIZE+i*BLOCKSIZE;
        fs_TLB[i].cache_state=0;
    }
    fclose(file);
    //设置当前文件打开表为0
    currfd=0;

}
void get_filename_correct(char *filename,char  *cut_filename)
{
    //将文件长度截取为最大文件长度
    if(strlen(filename)>=MAX_FILE_NAME)
    {
        memcpy(cut_filename,filename,MAX_FILE_NAME-1);
        cut_filename[MAX_FILE_NAME-1]='\0';
    }
    else
        strcpy(cut_filename,filename);
}
int check_filename_is_right(i_node *inode,char *cur_filename)
{
    offset_t *temp_block_address;
    int i,cache_num;
    int err;
    dir_block *temp_dir_block=NULL;
    //此索引节点目录项数据块存储个数
    offset_t i_node_block_num_end;
    i_node_block_num_end=inode->length;
    //遍历每个目录项数据块查找冲突
    for(i=0;i<i_node_block_num_end;i++)
    {
        //数据块载入cache
        temp_block_address= get_address_i_node_block(i,inode);
        cache_num= searche_cache(*temp_block_address);
        temp_dir_block=(dir_block *)fs_TLB[cache_num].file_cache;
        //校验是否存在重名
        err=check_filename_in_block_is_right(temp_dir_block,cur_filename);
        if(err==ERR_FAIL) {
            printf("you can not create the same name file in this directory !\n");
            return ERR_FAIL; }
    }
    return ERR_OK;
}
int check_filename_in_block_is_right(dir_block *dir_block,char *filename)
{
    int i;
    //遍历搜索目录项，查找重名
    for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++)
    {
        if(dir_block->dir_entry[i].free==0)
            continue;
        if(!strcmp(filename,dir_block->dir_entry[i].filename))
            return ERR_FAIL;
    }

    return ERR_OK;
}
void search_and_create_entry_to_block(char *filename,int fileType)
{
    i_node *temp_inode= (i_node *)malloc(INODE_SIZE);
    offset_t temp_inode_address;
    //获取索引节点
    temp_inode_address= get_Inode_address(openfilelist[currfd].inode_num);
    get_inode_from_file(temp_inode_address,temp_inode);
    //获取文件名字
    int err;
    char cut_filename[MAX_FILE_NAME];
    get_filename_correct(filename,cut_filename);
    //校验合法性
    err = check_filename_is_right(temp_inode,cut_filename);
    if(err==ERR_FAIL)
    {
        free(temp_inode);
        return;
    }
    //计算记录结尾地址
    offset_t i_node_block_num_end;
    i_node_block_num_end=temp_inode->length;
    //获取数据块地址和状态
    offset_t *block_address_ptr;
    block_address_ptr=NULL;
    int i;
    //遍历所有目录数据块
    for(i=0;i<temp_inode->length;i++) {
        block_address_ptr = get_address_i_node_block(i, temp_inode);
        err= save_dir_entry_to_block(cut_filename,*block_address_ptr,fileType);
        if(err==ERR_OK)//存入成功
        {
            free(temp_inode);
            return;
        }
    }
    if(err==ERR_FAIL)//存入失败
    {
        //判断是否根目录且超出设计上限
        if(currfd==0&&i_node_block_num_end>=ROOT_INODE_NUM) {
            printf("the size of directory or file is out of signed!\n");
            free(temp_inode);
            return;
        }
        else//申请新数据块
        {
            block_address_ptr= allocation_block_to_inode(i_node_block_num_end,temp_inode);
            if(block_address_ptr==NULL)
            {
                printf("the size of directory or file is out of signed!\n");
                free(temp_inode);
                return;
            }
            else {//申请成功
                save_dir_entry_to_block(filename,*block_address_ptr,fileType);
                temp_inode->length++;
            }
        }
    }
    //修改索引节点数据
    save_inode_to_file(temp_inode_address,temp_inode);
    free(temp_inode);

}
void my_mkdir(char * filename)
{
    if(strcmp(openfilelist[currfd].examname,DIRECTORY_FILE_EXNAME)!=0)
    {
        printf("you can not use my_mkdir in a data file!\n");
        return;
    }
    //搜索并创建目录文件
    search_and_create_entry_to_block(filename,0);

}
int save_dir_entry_to_block(char *filename,offset_t block_address,fs_size_t fileType)
{
    int cache_num;
    //获取cache地址
    cache_num=searche_cache(block_address);
    dir_block *temp_dir_block=(dir_block *)fs_TLB[cache_num].file_cache;
    int i;
    //查找空目录项
    for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++)
    {
        if(!temp_dir_block->dir_entry[i].free)
        {
            //选择文件种类
            switch (fileType) {
                case 0:strcpy(temp_dir_block->dir_entry[i].examname,DIRECTORY_FILE_EXNAME);break;
                case 1:strcpy(temp_dir_block->dir_entry[i].examname,DATA_FILE_EXNAME);break;
                default:break;
            }
            //设置目录项内容和cache状态
            strcpy(temp_dir_block->dir_entry[i].filename,filename);
            temp_dir_block->dir_entry[i].i_node_num=get_free_Inode();
            temp_dir_block->dir_entry[i].free=1;
            fs_TLB[cache_num].cache_state=1;
            //初始化索引节点
            init_inode(temp_dir_block->dir_entry[i].i_node_num,fileType);
            return ERR_OK;
        }
    }

    return ERR_FAIL;

}
void save_inode_to_file(offset_t inode_address,i_node *src_inode)
{
    FILE *file;
    file= fopen(FILENAME,"rb+");
    fseek(file, inode_address,SEEK_SET);
    fwrite(src_inode,INODE_SIZE,1,file);
    fclose(file);
}
void get_inode_from_file(offset_t inode_address,i_node *dst_inode)
{
    FILE *file;
    file= fopen(FILENAME,"rb");
    fseek(file, inode_address,SEEK_SET);
    fread(dst_inode,INODE_SIZE,1,file);
    fclose(file);
}

void get_block_from_file(offset_t block_address,void  *cache)
{
    FILE *file;
    file= fopen(FILENAME,"rb");
    fseek(file, block_address,SEEK_SET);
    fread(cache,BLOCKSIZE,1,file);
    fclose(file);

}

offset_t *get_address_i_node_block(fs_size_t i_node_block_num,i_node *inode)
{

    char temp_buff[BLOCKSIZE];
    int cache_num;
    //超出最大支持块号
    if(i_node_block_num>=MAX_BLOCK_IN_INODE)
        return NULL;
    //直接索引
    if(i_node_block_num<DIRECT_BLOCK_NUM)
    {
        //检查是否已分配数据块
        if(inode->i_block[i_node_block_num]==0)
            return NULL;
        cache_num= searche_cache(inode->i_block[i_node_block_num]);//检查是否在cache里
        //载入cache
        if(cache_num>=MAX_FILE_CACHE)
        {
            get_block_from_file(inode->i_block[i_node_block_num],temp_buff);
            save_block_to_cache(temp_buff,inode->i_block[i_node_block_num]);
        }
        //返回控制块地址
        return (&(inode->i_block[i_node_block_num]));
    }
    else if(i_node_block_num<DIRECT_BLOCK_NUM+1*BLOCKSIZE/sizeof(offset_t))
    {
        //检查是否为空
        if(inode->i_block[SMALL_BLOCK_NUM-1]==0)
            return NULL;
        //计算1级索引内的块号
        fs_size_t block_num_in_level1_num=i_node_block_num-DIRECT_BLOCK_NUM;
        return get_address_i_node_level1_block(inode->i_block[SMALL_BLOCK_NUM - 1],block_num_in_level1_num);

    }

    return  NULL;
}
offset_t *get_address_i_node_level1_block(offset_t block_level1_address,fs_size_t block_num_in_level1)
{
    char temp_buff[BLOCKSIZE];
    int cache_num;
    cache_num= searche_cache(block_level1_address);//检查是否在cache里
    if(cache_num>=MAX_FILE_CACHE)//载入cache
    {
        get_block_from_file(block_level1_address,temp_buff);
        save_block_to_cache(temp_buff,block_level1_address);
        cache_num= searche_cache(block_level1_address);
    }
    //计算块地址位置
    offset_t *temp_block_level;
    temp_block_level=(offset_t *)fs_TLB[cache_num].file_cache;
    temp_block_level+=block_num_in_level1;
    if(*temp_block_level==0)//数据块地址为空
        return NULL;
    else {
        //检查数据块是否在cache
        int level1_block_cache;
        level1_block_cache= searche_cache(*temp_block_level);
        //载入cache
        if(level1_block_cache>=MAX_FILE_CACHE)
        {
            get_block_from_file(*temp_block_level,temp_buff);
            save_block_to_cache(temp_buff,*temp_block_level);
        }
        //printf("block address in:%d %d\n",*temp_block_level,
               //*((offset_t *)fs_TLB[cache_num].file_cache + block_num_in_level1));
        return ((offset_t *)fs_TLB[cache_num].file_cache + block_num_in_level1);
    }

}
offset_t *allocation_block_to_inode(fs_size_t i_node_block_num,i_node *inode)
{
    char temp_block_buff[BLOCKSIZE];
    if(i_node_block_num>=MAX_BLOCK_IN_INODE)
        return NULL;

    //直接索引
    if(i_node_block_num<DIRECT_BLOCK_NUM) {
        if(inode->i_block[i_node_block_num]==0)
            inode->i_block[i_node_block_num]= get_Block_address(get_free_block());
        //载入cache
        get_block_from_file(inode->i_block[i_node_block_num],temp_block_buff);
        save_block_to_cache(temp_block_buff,inode->i_block[i_node_block_num]);
        return (&(inode->i_block[i_node_block_num]));
    }
    else if(i_node_block_num<DIRECT_BLOCK_NUM+1*BLOCKSIZE/sizeof(offset_t))
    {
        if(inode->i_block[SMALL_BLOCK_NUM-1]==0)
            inode->i_block[SMALL_BLOCK_NUM-1]= get_Block_address(get_free_block());
        fs_size_t block_num_in_level1_num=i_node_block_num-DIRECT_BLOCK_NUM;
        return allocation_block_level1_to_inode(inode->i_block[SMALL_BLOCK_NUM - 1],
                                                             block_num_in_level1_num);

    }
    return NULL;
}
offset_t *allocation_block_level1_to_inode(offset_t block_level1_address,fs_size_t block_num_in_level1)
{
    char temp_buff[BLOCKSIZE];
    int cache_num;
    //检查一级索引地址块是否载入cache
    cache_num= searche_cache(block_level1_address);
    if(cache_num>=MAX_FILE_CACHE) {
        get_block_from_file(block_level1_address,temp_buff);
        save_block_to_cache(temp_buff,block_level1_address);
        cache_num= searche_cache(block_level1_address);
    }
    fs_TLB[cache_num].cache_state=1;

    //获取1级索引控制块在cache中位置
    offset_t *temp_block_level1;
    temp_block_level1=(offset_t *)fs_TLB[cache_num].file_cache;
    temp_block_level1+=block_num_in_level1;
    //检查是否为空
    if(*temp_block_level1==0)
        *temp_block_level1= get_Block_address(get_free_block());
    int cache_num_level1;
    //检查一级索引数据块是否载入cache
    cache_num_level1= searche_cache(*temp_block_level1);
    if(cache_num_level1>=MAX_FILE_CACHE) {
        get_block_from_file(*temp_block_level1, temp_buff);
        save_block_to_cache(temp_buff, *temp_block_level1);
        //printf("save %d to cache\n",*temp_block_level1);
    }

    return ((offset_t *) fs_TLB[cache_num].file_cache + block_num_in_level1);
}
void my_exit()
{

    int i;
    //保存所有cache
    for(i=0;i<MAX_FILE_CACHE;i++)
        save_cache_to_file(i);
    //同步块组描述符
    GDT *temp_gdt_block=(GDT *)fs_TLB[3].file_cache;
    if(fs_TLB[3].cache_state)
        update_GDT_block(temp_gdt_block->block_group_num);
    //同步超级块
    if(fs_TLB[0].cache_state)
        update_super_block(0);

    printf("******************file system exit**********************\n");
}
void my_cd(char *filename)
{
    //校验操作合法性
    if(strcmp(openfilelist[currfd].examname,DIRECTORY_FILE_EXNAME)!=0)
    {
        printf("you can not use my_cd in a data file!\n");
        return;
    }
    if(!strcmp(filename,"."))
        return;
    if(!strcmp(filename,".."))
    {
        if(currfd==0) {
            printf("this is root!\n");
        }
        else {
            openfilelist[currfd].file_open_free = 0;
            currfd--;
        }
        return;
    }
    if(strlen(filename)>=MAX_FILE_NAME)
    {
        printf(" not find this directory!\n");
        return;
    }
    //搜索目录项并打开
    search_and_copy_entry_to_openfilelist(filename,diretory_file);
}
void copy_entry_to_openfile_list(fs_size_t fd,fcb dir_entry)
{
    if(fd>=MAX_OPEN_FILE)
        return;
    if(fd==0)
        return;
    strcpy(openfilelist[fd].filename,dir_entry.filename);
    strcpy(openfilelist[fd].examname,dir_entry.examname);
    openfilelist[fd].inode_num=dir_entry.i_node_num;
    openfilelist[fd].count=0;
    openfilelist[fd].file_open_free=1;
    strcpy(openfilelist[fd].dir,openfilelist[fd-1].dir);
    strcat(openfilelist[fd].dir,"\\");
    strcat(openfilelist[fd].dir,dir_entry.filename);
}
void my_open(char *filename)
{
    if(0!=strcmp(openfilelist[currfd].examname,DIRECTORY_FILE_EXNAME))
    {
        printf("you can not use my_open in a dat file!\n");
        return;
    }
    if(strlen(filename)>=MAX_FILE_NAME)
    {
        printf(" not find this directory!\n");
        return;
    }
    if(currfd==MAX_OPEN_FILE)
    {
        printf(" please close some file!\n");
        return;
    }
    search_and_copy_entry_to_openfilelist(filename,data_file);

}
void search_and_copy_entry_to_openfilelist(char *filename,int fileType)
{
    //获取索引节点
    offset_t temp_inode_address;
    temp_inode_address= get_Inode_address(openfilelist[currfd].inode_num);
    //printf("temp_inode_address:%d\n",temp_inode_address);
    i_node *temp_inode=(i_node*) malloc(INODE_SIZE);
    get_inode_from_file(temp_inode_address,temp_inode);
    //搜索目录项
    //遍历每个目录项数据块查找
    int i,i_node_block_num_end;
    int cache_num;
    offset_t *temp_block_address;
    dir_block *temp_dir_block;
    int err=ERR_OK;
    i_node_block_num_end=temp_inode->length;
    //printf("%d",i_node_block_num_end);
    for(i=0;i<i_node_block_num_end;i++)
    {
        //载入cache
        temp_block_address= get_address_i_node_block(i,temp_inode);
        cache_num= searche_cache(*temp_block_address);
        //printf("%d %d\n",*temp_block_address,temp_inode->i_block[i]);
        temp_dir_block=(dir_block *)fs_TLB[cache_num].file_cache;
        //检查数据块内目录项状态
        err=check_filename_in_block_is_right(temp_dir_block,filename);//返回ERR_FAIL表示找到重名
        if(err==ERR_FAIL)
            break;
    }
    if(err==ERR_OK)
    {
        printf(" not find this directory or file!\n");
        return;
    }
    else
    {
        //查找目录项
        for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++)
        {
            if(temp_dir_block->dir_entry[i].free==0)
                continue;
            //查找到同名文件
            if(!strcmp(filename,temp_dir_block->dir_entry[i].filename)) {
                char check_Type_buff[EXAMNAME_SIZE];
                //选择文件类型
                switch (fileType) {
                    case diretory_file:strcpy(check_Type_buff,DIRECTORY_FILE_EXNAME);break;
                    case data_file:strcpy(check_Type_buff,DATA_FILE_EXNAME);break;
                    default:break;
                }
                //检查文件类型
                if(strcmp(check_Type_buff,temp_dir_block->dir_entry[i].examname)!=0)
                {
                    free(temp_inode);
                    printf(" the  type of this file is error!\n");
                    return;
                }
                currfd++;
                //将目录项载入至打开表
                copy_entry_to_openfile_list(currfd,temp_dir_block->dir_entry[i]);
                break;
            }
        }
    }
    free(temp_inode);
}
void my_create(char *filename)
{
    if(strcmp(openfilelist[currfd].examname,DIRECTORY_FILE_EXNAME)!=0)
    {
        printf("you can not use my_mkdir in a data file!\n");
        return;
    }
    search_and_create_entry_to_block(filename,1);
}
void my_read(int fd)
{
    if(!strcmp(openfilelist[fd].examname,DIRECTORY_FILE_EXNAME))
    {
        printf("you can not use read in a diretory file!\n");
        return;
    }
    //获取索引节点
    offset_t temp_inode_address;
    i_node *temp_inode;
    temp_inode=(i_node *) malloc(INODE_SIZE);
    temp_inode_address= get_Inode_address(openfilelist[fd].inode_num);
    get_inode_from_file(temp_inode_address,temp_inode);
    //计算数据块数量
    int i;
    offset_t *temp_block_address;
    fs_size_t offset=temp_inode->length;
    fs_size_t offset_end=offset%BLOCKSIZE;
    for(i=0;i<(temp_inode->length)/BLOCKSIZE;i++)
    {
        temp_block_address=get_address_i_node_block(i,temp_inode);
        read_message_in_block(BLOCKSIZE,*temp_block_address);
    }
    //输出最后一个数据块的数据
    temp_block_address=get_address_i_node_block(i,temp_inode);
    read_message_in_block(offset_end,*temp_block_address);
    printf("\nthe len of this data file is %d\n",temp_inode->length);
    free(temp_inode);

}
void read_message_in_block(fs_size_t offset_end,offset_t block_address)
{
    int cache_num;
    cache_num= searche_cache(block_address);
    char temp_buff[BLOCKSIZE+1];
    memcpy(temp_buff,fs_TLB[cache_num].file_cache,offset_end);
    temp_buff[offset_end]='\0';
    printf("%s",temp_buff);
}
void my_write(int fd)
{
    if(!strcmp(openfilelist[fd].examname,DIRECTORY_FILE_EXNAME))
    {
        printf("you can not use read in a diretory file!\n");
        return;
    }
    //获取索引节点
    offset_t temp_inode_address;
    i_node *temp_inode;
    temp_inode=(i_node *) malloc(INODE_SIZE);
    temp_inode_address= get_Inode_address(openfilelist[fd].inode_num);
    get_inode_from_file(temp_inode_address,temp_inode);
    //选择偏移类型
    // 1: 截断写，清空全部内容，从头开始写
    // 2. 覆盖写，从文件指针处开始写
    // 3. 追加写，从末尾写
    int write_type,offset_len,i;
    //选择模式
    printf("select the type of write:\n");
    printf("1:Truncation  2:Coverage  3:Addition\n");
    printf("write type is:");
    scanf("%d",&write_type);getchar();
    printf("you can input '$' to end write\n");
    //定位写指针位置
    switch (write_type) {
        case 1:
            //删除分配的所有数据块中的文件
            for(i=0;i<(temp_inode->length)/BLOCKSIZE+1;i++)
                rm_data_file_in_block(i,temp_inode);
            temp_inode->length=0;
            temp_inode->i_block[0]= get_Block_address(get_free_block());
            openfilelist[fd].count=0;break;
        case 2:
            printf("input you want to arrive:");
            scanf("%d",&offset_len);getchar();
            my_seek(offset_len,my_SEEK_SET,temp_inode->length,fd);break;
        case 3:
            my_seek(0,my_SEEK_END,temp_inode->length,fd);
            break;
        default:break;

    }

    //写入数据
    int block_num;
    int block_offset;
    int cache_num;
    offset_t *temp_block_address;
    block_num=openfilelist[fd].count/BLOCKSIZE;
    block_offset=openfilelist[fd].count%BLOCKSIZE;
    //读出数据块
    char *temp_write;
    int flag=1;
    temp_block_address=get_address_i_node_block(block_num,temp_inode);
    if(temp_block_address==NULL)
        temp_block_address= allocation_block_to_inode(block_num,temp_inode);
    cache_num= searche_cache(*temp_block_address);
    temp_write=fs_TLB[cache_num].file_cache;
   // printf("get block address is:%d\n",*temp_block_address);
  //  printf("cache num is:%d\n",cache_num);
    //输入数据
    while (flag)
    {

        while (block_offset<BLOCKSIZE)
        {
            //写入数据
            scanf("%c", temp_write+block_offset);
            //停止条件
            if(temp_write[block_offset]=='$')
            {
                getchar();
                temp_write[block_offset]='\0';
                flag=0;
                break;
            }
            //块内偏移量
            block_offset++;
            //读写指针位置
            if(temp_inode->length==openfilelist[fd].count)
            {
                openfilelist[fd].count++;
                temp_inode->length++;
            }
            else
                openfilelist[fd].count++;
            //设置cache为已修改
            fs_TLB[cache_num].cache_state=1;
        }

        block_num++;
        //获取数据块
        temp_block_address=get_address_i_node_block(block_num,temp_inode);
        if(temp_block_address==NULL)
            temp_block_address = allocation_block_to_inode(block_num, temp_inode);
        if(!flag)
            break;
        //printf("get block address is:%d\n",*temp_block_address);
        //数据块分配失败
        if(*temp_block_address==0)
        {
            printf("allocate error!\n");
            break;
        }
        cache_num= searche_cache(*temp_block_address);
       // printf("cache num is:%d\n",cache_num);
      //  printf("%lu",BLOCKSIZE/sizeof (offset_t));
        temp_write=fs_TLB[cache_num].file_cache;
        block_offset=0;

    }
    save_inode_to_file(temp_inode_address,temp_inode);
    free(temp_inode);


}
void my_seek(fs_size_t len,int cmd_Type,fs_size_t max_len,int fd)
{
    fs_size_t move_to_byte;
    switch (cmd_Type) {
        case my_SEEK_CUR:move_to_byte=len+openfilelist[fd].count;
            if(move_to_byte>=max_len)
                openfilelist[fd].count=max_len;
            else if(move_to_byte<0)
                openfilelist[fd].count=0;
            else
                openfilelist[fd].count=move_to_byte;break;
        case my_SEEK_SET:
            if(len>=max_len)
                openfilelist[fd].count=max_len;
            else if(len>0)
                openfilelist[fd].count=len;
            else
                openfilelist[fd].count=0;break;
        case my_SEEK_END:
            openfilelist[fd].count=max_len==0?0:max_len-1;break;
        default:break;
    }

}
void my_rm(char *filename)
{
    if(strlen(filename)>=MAX_FILE_NAME)
    {
        printf("can not find this diretory or file\n");
        return;
    }
    if(0!=strcmp(openfilelist[currfd].examname,DIRECTORY_FILE_EXNAME))
    {
        printf("can not use rm in data file\n");
        return;
    }
    //搜索并删除文件
    rm_search_file_and_delete(filename);
}
void my_rmdir(char *filename)
{
    my_rm(filename);
}
void rm_search_file_and_delete(char *filename)
{
    //检查合法性
    if(!strcmp(filename,"."))
        return;
    if(!strcmp(filename,".."))
    {
        return;
    }
    //获取索引节点
    offset_t temp_inode_address;
    temp_inode_address= get_Inode_address(openfilelist[currfd].inode_num);
    //printf("temp_inode_address:%d\n",temp_inode_address);
    i_node *temp_inode=(i_node*) malloc(INODE_SIZE);
    get_inode_from_file(temp_inode_address,temp_inode);
    //搜索目录项
    //遍历每个目录项数据块查找
    int i,i_node_block_num_end;
    int cache_num;
    offset_t *temp_block_address;
    dir_block *temp_dir_block;
    int err=ERR_OK;
    i_node_block_num_end=temp_inode->length;
    //遍历数据块查找目录项位置
    for(i=0;i<i_node_block_num_end;i++)
    {
        temp_block_address= get_address_i_node_block(i,temp_inode);
        cache_num= searche_cache(*temp_block_address);
        //printf("%d %d\n",*temp_block_address,temp_inode->i_block[i]);
        temp_dir_block=(dir_block *)fs_TLB[cache_num].file_cache;
        err=check_filename_in_block_is_right(temp_dir_block,filename);//返回ERR_FAIL表示找到重名
        if(err==ERR_FAIL) {
            fs_TLB[cache_num].cache_state=1;
            break; }
    }
    if(err==ERR_OK)
    {
        printf(" not find this directory or file!\n");
        return;
    }
    else
    {
        int fileType;
        //查找目录项
        for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++)
        {
            if(temp_dir_block->dir_entry[i].free==0)
                continue;
            //释放目录项
            if(!strcmp(filename,temp_dir_block->dir_entry[i].filename)) {
                //获取目录项类型
                fileType= select_Type_of_file(temp_dir_block->dir_entry[i].examname);
                temp_dir_block->dir_entry[i].free=0;
                //删除索引节点数据
                rm_inode(temp_dir_block->dir_entry[i].i_node_num,fileType);
                break;
            }
        }

        //如果当前目录项数据块为空，释放数据块(除非是root
        if(check_dir_in_block_is_empty(i,temp_inode)==ERR_OK&&currfd!=0)
        {

            temp_block_address= get_address_i_node_block(i,temp_inode);
            if(!temp_block_address)
            {
                rm_block_in_bitmap(*temp_block_address);
                *temp_block_address=0;
                temp_inode->length--;
                save_inode_to_file(temp_inode_address,temp_inode);
            }
        }
    }

    free(temp_inode);

}
int select_Type_of_file(char *file_exam)
{
    if(!strcmp(DIRECTORY_FILE_EXNAME,file_exam))
        return diretory_file;
    else if(!strcmp(DATA_FILE_EXNAME,file_exam))
        return data_file;
    return undefine_file;
}
void rm_block_in_bitmap(offset_t block_address)//修改索引节点位图
{
    int block_num;
    super_block *temp_super_block=(super_block *)fs_TLB[0].file_cache;
    //获取当前块组描述符
    GDT *temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    block_num=(block_address-temp_super_block->super_block0_start_address)/BLOCKSIZE;
    if(block_num>BLOCK_GROUP_NUM*PER_BLOCK_GROUP_BLOCK_MAX_NUM)
        return;
    fs_size_t block_of_block_group,block_offset_in_block;
    block_of_block_group=block_num/PER_BLOCK_GROUP_BLOCK_MAX_NUM;
    block_offset_in_block=block_num%PER_BLOCK_GROUP_BLOCK_MAX_NUM;
    //切换至对应块组描述符
    if(temp_gdt->block_group_num!=block_of_block_group) {
        come_to_other_GDT(block_of_block_group);
    }
    temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    //更新索引节点位图状态
    fs_TLB[1].file_cache[block_offset_in_block]=BLOCK_FREE;
    fs_TLB[1].cache_state=1;

    //修改超级块状态
    temp_super_block->all_free_block++;
    temp_super_block->per_block_group_block_free_num[temp_gdt->block_group_num]+=1;
    fs_TLB[0].cache_state=1;

    //更新块组描述符状态
    temp_gdt->block_group_free_block++;
    fs_TLB[3].cache_state=1;
   // printf("delete block %d",block_num);
}
void rm_inode_in_bitmap(fs_size_t inode_num)//修改块位图
{

    if(inode_num>BLOCK_GROUP_NUM*PER_BLOCK_GROUP_INODE_MAX_NUM)
        return;
    super_block *temp_super_block=(super_block *)fs_TLB[0].file_cache;
    //获取当前块组描述符
    GDT *temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    fs_size_t inode_block_group,inode_offset_in_block;
    inode_block_group=inode_num/PER_BLOCK_GROUP_INODE_MAX_NUM;
    inode_offset_in_block=inode_num%PER_BLOCK_GROUP_INODE_MAX_NUM;
    //切换至对应块组描述符
    if(temp_gdt->block_group_num!=inode_block_group) {
        come_to_other_GDT(inode_block_group);
    }
    temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    //更新索引节点位图状态
    fs_TLB[2].file_cache[inode_offset_in_block]=INODE_FREE;
    fs_TLB[2].cache_state=1;

    //修改超级块状态
    temp_super_block->all_free_Inode++;
    temp_super_block->per_block_group_Inode_free_num[temp_gdt->block_group_num]+=1;
    fs_TLB[0].cache_state=1;

    //更新块组描述符状态
    temp_gdt->block_group_free_inode++;
    fs_TLB[3].cache_state=1;
}
int check_dir_in_block_is_empty(offset_t block_num,i_node *temp_inode)
{
    offset_t *temp_block_address;
    temp_block_address= get_address_i_node_block(block_num,temp_inode);
    if(!temp_block_address)
        return ERR_OK;
    int  cache_num;
    cache_num= searche_cache(*temp_block_address);
    dir_block *temp_dir_block=(dir_block *)fs_TLB[cache_num].file_cache;
    int i;
    for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++)
    {
        if(!temp_dir_block->dir_entry[i].free)
            break;
    }
    if(i<MAX_DIR_BLOCK_FCB_NUM)
        return ERR_FAIL;
    else
        return ERR_OK;

}
void rm_inode(fs_size_t inode_num,fs_size_t fileType)
{
    //选择删除文件的类型
    if(fileType==diretory_file)
    {
        rm_dir_file(inode_num);
    }
    else if(fileType==data_file)
    {
        rm_data_file(inode_num);
    }


}
void rm_data_file(fs_size_t inode_num)//删除数据文件索引节点
{
    rm_inode_in_bitmap(inode_num);
    int i;
    offset_t temp_inode_address;
    i_node *temp_inode;
    //获取索引节点
    temp_inode=(i_node *) malloc(INODE_SIZE);
    temp_inode_address= get_Inode_address(inode_num);
    get_inode_from_file(temp_inode_address,temp_inode);
    //删除分配的所有数据块中的文件
    for(i=0;i<(temp_inode->length)/BLOCKSIZE+1;i++)
    {
        rm_data_file_in_block(i,temp_inode);
    }
    memset(temp_inode,0,INODE_SIZE);
    save_inode_to_file(temp_inode_address,temp_inode);
    free(temp_inode);
}
void rm_dir_file(fs_size_t inode_num)//删除目录文件索引节点
{
    if(inode_num<=ROOT_INODE_NUM) {
        return;
    }
    else
        rm_inode_in_bitmap(inode_num);
    int i;
    offset_t temp_inode_address;
    i_node *temp_inode;
    //获取索引节点
    temp_inode=(i_node *) malloc(INODE_SIZE);
    temp_inode_address= get_Inode_address(inode_num);
    get_inode_from_file(temp_inode_address,temp_inode);
    //删除所有目录数据
    for(i=0;i<temp_inode->length;i++)
    {
        rm_dir_in_block(i,temp_inode);
    }


    free(temp_inode);
}
void rm_dir_in_block(fs_size_t block_num,i_node *temp_inode)//删除目录文件某个数据块内的所有目录项
{
    int i;
    int cache_num;
    int fileType;
    offset_t *temp_block_address;
    //查找所有正在使用的目录项
    for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++)
    {
        //载入cache
        temp_block_address= get_address_i_node_block(block_num,temp_inode);
        cache_num= searche_cache(*temp_block_address);
        dir_block *temp_dir_block=(dir_block *)fs_TLB[cache_num].file_cache;
        if(temp_dir_block->dir_entry[i].free)
        {
            temp_dir_block->dir_entry[i].free = 0;
            fileType = select_Type_of_file(temp_dir_block->dir_entry[i].examname);
            switch (fileType) {
                case diretory_file:
                    if(!strcmp(temp_dir_block->dir_entry[i].filename,"..")||!strcmp(temp_dir_block->dir_entry[i].filename,"."))
                        break;
                    else
                        rm_dir_file(temp_dir_block->dir_entry[i].i_node_num);//递归删除
                    break;
                case data_file:
                    rm_data_file(temp_dir_block->dir_entry[i].i_node_num);//直接删除
                    break;
                default:
                    break;
            }
        }
    }
    //清空数据块
    temp_block_address= get_address_i_node_block(block_num,temp_inode);
    cache_num= searche_cache(*temp_block_address);
    rm_block_in_bitmap(*temp_block_address);
    fs_TLB[cache_num].cache_state=1;
    memset(fs_TLB[cache_num].file_cache,0,BLOCKSIZE);
    *temp_block_address=0;

}
void rm_data_file_in_block(fs_size_t block_num,i_node *temp_inode)//删除数据文件数据块
{
    int cache_num;
    offset_t *temp_block_address;
    temp_block_address= get_address_i_node_block(block_num,temp_inode);
    cache_num= searche_cache(*temp_block_address);
    //清空数据块
    rm_block_in_bitmap(*temp_block_address);
    fs_TLB[cache_num].cache_state=1;
    memset(fs_TLB[cache_num].file_cache,0,BLOCKSIZE);
    *temp_block_address=0;
}
void my_close(int fd)
{
    if(!strcmp(DIRECTORY_FILE_EXNAME,openfilelist[fd].examname))
    {
        printf("you can not use my_close in a directory file!\n");
        return;
    }
    //简单易懂的返回操作
    openfilelist[fd].count=0;
    openfilelist[fd].file_open_free=0;
    fd--;
    currfd=fd;

}
int select_cmd(char *cmd)
{
    if(!strcmp(cmd,"my_ls"))
        return my_ls_t;
    else if(!strcmp(cmd,"my_mkdir"))
        return my_mkdir_t;
    else if(!strcmp(cmd,"my_close"))
        return my_close_t;
    else if(!strcmp(cmd,"exit"))
        return my_exit_t;
    else if(!strcmp(cmd,"my_format"))
        return my_format_t;
    else if(!strcmp(cmd,"my_cd"))
        return my_cd_t;
    else if(!strcmp(cmd,"my_open"))
        return my_open_t;
    else if(!strcmp(cmd,"my_create"))
        return my_create_t;
    else if(!strcmp(cmd,"my_rm"))
        return my_rm_t;
    else if(!strcmp(cmd,"my_rmdir"))
        return my_rmdir_t;
    else if(!strcmp(cmd,"my_read"))
        return my_read_t;
    else if(!strcmp(cmd,"my_write"))
        return my_write_t;
    else if(!strcmp(cmd,"my_help"))
        return my_help_t;
    return -1;


}
void my_help(void)
{

}
void get_time(uint16_t *date_time,uint16_t *day_time)
{
    time_t rawTime = time(NULL);
    struct tm* time = localtime(&rawTime);
    // 5 6 5 bits
    *day_time = time->tm_hour * 2048 + time->tm_min * 32 + time->tm_sec / 2;
    // 7 4 5 bits; year from 2000
    *date_time = (time->tm_year - 100) * 512 + (time->tm_mon + 1) * 32 + (time->tm_mday);
}
void output_time(uint16_t data_time,uint16_t time)
{
    printf("%d/%d/%d %d:%d\n",
           (data_time>> 9) + 2000,
           (data_time>> 5) & 0x000f,
           (data_time) & 0x001f,
           (time >> 11),
           (time >> 5) & 0x003f);
}



void init_inode(fs_size_t i_node_num,int node_type)
{
    int i_node_address;
    i_node_address=get_Inode_address(i_node_num);
    i_node *temp_inode=(i_node *) malloc(INODE_SIZE);
    get_inode_from_file(i_node_address,temp_inode);
    //初始化目录索引节点
    if(node_type==0) {
        temp_inode->file_Type=0;
        temp_inode->length=1;
        temp_inode->i_block[0]=get_Block_address(get_free_block());
        get_address_i_node_block(0,temp_inode);
        int cache_num= searche_cache(temp_inode->i_block[0]);
        dir_block *temp_dir=(dir_block *)fs_TLB[cache_num].file_cache;
        //设置默认目录项
        temp_dir->dir_entry[0].free=1;
        strcpy(temp_dir->dir_entry[0].examname,DIRECTORY_FILE_EXNAME);
        strcpy(temp_dir->dir_entry[0].filename,".");
        temp_dir->dir_entry[0].i_node_num=i_node_num;
        temp_dir->dir_entry[1].free=1;
        strcpy(temp_dir->dir_entry[1].examname,DIRECTORY_FILE_EXNAME);
        strcpy(temp_dir->dir_entry[1].filename,"..");
        temp_dir->dir_entry[1].i_node_num=openfilelist[currfd].inode_num;
        //标记修改
        fs_TLB[cache_num].cache_state=1;
    }
    else if(node_type==1)//初始化数据文件
    {
        temp_inode->file_Type=1;
        temp_inode->length=0;
        temp_inode->i_block[0]=get_Block_address(get_free_block());
    }
    //设置时间信息
    get_time(&(temp_inode->create_data),&(temp_inode->create_time));
    get_time(&(temp_inode->modified_data),&(temp_inode->modified_time));
    save_inode_to_file(i_node_address,temp_inode);
    free(temp_inode);
}
offset_t searche_cache(offset_t address)
{
    int i;
    for(i=0;i<MAX_FILE_CACHE;i++)
        if(fs_TLB[i].block_address==address)
            break;
    return i;
}
void show_dir_entry(dir_block *temp_dir)
{
    int i;
    i_node *temp_inode=(i_node*) malloc(INODE_SIZE);
    offset_t temp_inode_addrres;
    for(i=0;i<MAX_DIR_BLOCK_FCB_NUM;i++) {
        if(temp_dir->dir_entry[i].free)
        {
            temp_inode_addrres= get_Inode_address(temp_dir->dir_entry[i].i_node_num);
            get_inode_from_file(temp_inode_addrres,temp_inode);
            printf("<%s>%-8s", temp_dir->dir_entry[i].examname, temp_dir->dir_entry[i].filename);
            output_time(temp_inode->create_data,temp_inode->create_time);
        }
    }


}
void init_root_dir_inode(void)
{

    int i_node_address;
    //获取索引节点
    i_node_address=get_Inode_address(openfilelist[0].inode_num);
    i_node *temp_inode=NULL;
    temp_inode=(i_node *) malloc(INODE_SIZE);
    get_inode_from_file(i_node_address,temp_inode);

    //节点未初始化
    if(!(temp_inode->i_block[1])) {
        //printf("initial root\n");
        //初始化索引节点
        get_inode_from_file(i_node_address,temp_inode);
        //申请root目录空间
        for (int i = 0; i < ROOT_DIR_BLOCK; i++)
            temp_inode->i_block[i] = get_Block_address(get_free_block());
        temp_inode->length = ROOT_DIR_BLOCK ;
        get_time(&(temp_inode->create_data),&(temp_inode->create_time));
        get_time(&(temp_inode->modified_data),&(temp_inode->modified_time));
        //保存root目录消息
        save_inode_to_file(i_node_address,temp_inode);
    }
    FILE *file;
    file= fopen(FILENAME,"rb+");

    //将目录消息存入cache
    for(int i=ROOT_DIR_BEGIN;i<ROOT_DIR_END;i++) {
        fseek(file,temp_inode->i_block[i-ROOT_DIR_BEGIN],SEEK_SET);
        fread(fs_TLB[i].file_cache,BLOCKSIZE,1,file);
        fs_TLB[i].cache_state=0;
        fs_TLB[i].block_address=temp_inode->i_block[i-ROOT_DIR_BEGIN];
        fs_TLB[i].input_time=0;

    }
    fclose(file);
    //设置根目录默认目录
    int cache_num= searche_cache(temp_inode->i_block[0]);
    dir_block *temp_dir=(dir_block *)fs_TLB[cache_num].file_cache;
    temp_dir->dir_entry[0].free=1;
    strcpy(temp_dir->dir_entry[0].examname,DIRECTORY_FILE_EXNAME);
    strcpy(temp_dir->dir_entry[0].filename,".");
    temp_dir->dir_entry[0].i_node_num=openfilelist[0].inode_num;
    temp_dir->dir_entry[1].free=1;
    strcpy(temp_dir->dir_entry[1].examname,DIRECTORY_FILE_EXNAME);
    strcpy(temp_dir->dir_entry[1].filename,"..");
    temp_dir->dir_entry[1].i_node_num=openfilelist[0].inode_num;
    fs_TLB[cache_num].cache_state=1;

    save_inode_to_file(i_node_address,temp_inode);
    free(temp_inode);

}
void update_super_block(fs_size_t modify_num)
{
    FILE *file;
    file= fopen(FILENAME,"rb+");
    char temp_super_block[BLOCKSIZE];

    if(modify_num>=BLOCK_GROUP_NUM)
    {
        printf("this address does not have super block");
        return;
    }
    //将可用超级块读出
    fseek(file,BLOCKSIZE+BLOCK_GROUP_SIZE*modify_num,SEEK_SET);
    fread(temp_super_block,BLOCKSIZE,1,file);

    fseek(file,BLOCKSIZE,SEEK_SET);
    int i;
    //同步至所有超级块
    for(i=0;i<BLOCK_GROUP_NUM;i++)
    {

        if(i!=modify_num) {
            fwrite(temp_super_block,BLOCKSIZE,1,file);
            fseek(file,-BLOCKSIZE+BLOCK_GROUP_SIZE,SEEK_CUR);
        }
    }
    fclose(file);
}
void update_GDT_block(fs_size_t modify_num)
{
    FILE *file;
    file= fopen(FILENAME,"rb+");
    char temp_gdt_block[BLOCKSIZE];

    if(modify_num>=BLOCK_GROUP_NUM)
    {
        printf("this address does not have gdt block");
        return;
    }
    //始终查询0号块组gdt数据
    fseek(file,BLOCKSIZE+BLOCKSIZE*(modify_num+3),SEEK_SET);
    fread(temp_gdt_block,BLOCKSIZE,1,file);

    fseek(file,BLOCK_GROUP_SIZE-BLOCKSIZE,SEEK_CUR);
    int i;
    //同步至所有块组
    for(i=1;i<BLOCK_GROUP_NUM;i++)
    {
        fwrite(temp_gdt_block,BLOCKSIZE,1,file);
        fseek(file,-BLOCKSIZE+BLOCK_GROUP_SIZE,SEEK_CUR);

    }
    fclose(file);
}
int get_free_block(void)
{
    int i;
    super_block *temp_super_block=(super_block *)fs_TLB[0].file_cache;
    //查询是否存在空块
    if(temp_super_block->all_free_block==0)
        return -1;
    //查询当前块组是否有空块
    GDT *temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    if(temp_gdt->block_group_free_block==0) {
        for(i=0;i<BLOCK_GROUP_NUM;i++)
        {
            if(temp_super_block->per_block_group_block_free_num[i]!=0)
            {
                come_to_other_GDT(i);
                break;
            }
        }
    }
    temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    for(i=0;i<PER_BLOCK_GROUP_BLOCK_MAX_NUM;i++)
    {

        //printf("%d %d\n",fs_TLB[1].file_cache[i],i);
        if(fs_TLB[1].file_cache[i]==BLOCK_FREE) {
            fs_TLB[1].file_cache[i] = BLOCK_BUSY;
            //更新超级块和块组描述符
            temp_super_block->all_free_block--;
            temp_super_block->per_block_group_block_free_num[temp_gdt->block_group_num]--;
            temp_gdt->block_group_free_block--;
            fs_TLB[1].cache_state=1;
            fs_TLB[0].cache_state=1;
            fs_TLB[3].cache_state=1;
            return i+temp_gdt->block_group_num*PER_BLOCK_GROUP_BLOCK_MAX_NUM;
        }

    }
    return -1;
}
int get_free_Inode(void)
{
    int i;
    super_block *temp_super_block=(super_block *)fs_TLB[0].file_cache;
    //查询是否存在空块
    if(temp_super_block->all_free_Inode==0)
        return -1;
    //查询当前块组是否有空块
    GDT *temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    if(temp_gdt->block_group_free_inode==0) {
        for(i=0;i<BLOCK_GROUP_NUM;i++)
        {
            if(temp_super_block->per_block_group_Inode_free_num[i]!=0) {
                come_to_other_GDT(i);
                break;
            }
        }
    }
    temp_gdt=(GDT *)(fs_TLB[3].file_cache);
    for(i=0;i<PER_BLOCK_GROUP_INODE_MAX_NUM;i++)
    {
        if(fs_TLB[2].file_cache[i]==INODE_FREE) {
            fs_TLB[2].file_cache[i]=INODE_BUSY;
            //更新超级块和块组描述符
            temp_super_block->all_free_Inode--;
            temp_super_block->per_block_group_Inode_free_num[temp_gdt->block_group_num]-=1;
            temp_gdt->block_group_free_inode--;
            fs_TLB[2].cache_state=1;
            fs_TLB[3].cache_state=1;
            fs_TLB[0].cache_state=1;
            return i+temp_gdt->block_group_num*PER_BLOCK_GROUP_INODE_MAX_NUM;
        }

    }

    return -1;
}



void come_to_other_GDT(fs_size_t move_to_GDT_num)
{
    //高情商：此处代码有极大的压行空间，易于理解
    //低情商：神智不清的懒狗写法


    //保存当前快位图和块组描述符至文件
    save_cache_to_file(1);
    save_cache_to_file(2);
    save_cache_to_file(3);
    GDT *temp_gdt=(GDT *)fs_TLB[3].file_cache;
    update_GDT_block(temp_gdt->block_group_num);

    //获取块组0空闲块组描述符
    fs_size_t gdt_block_num;
    offset_t gdt_block_address;
    char temp_gdt_block_buff[BLOCKSIZE];
    gdt_block_num=1+2+move_to_GDT_num;
    gdt_block_address= get_Block_address(gdt_block_num);
    get_block_from_file(gdt_block_address,temp_gdt_block_buff);
    fs_TLB[3].cache_state=0;
    fs_TLB[3].block_address=gdt_block_address;
    fs_TLB[3].input_time=0;
    memcpy(fs_TLB[3].file_cache,temp_gdt_block_buff,BLOCKSIZE);
    //获取块位图和索引节点位图
    gdt_block_num=1+move_to_GDT_num*BLOCK_GROUP_SIZE;
    gdt_block_address= get_Block_address(gdt_block_num);
    get_block_from_file(gdt_block_address,temp_gdt_block_buff);
    fs_TLB[1].cache_state=0;
    fs_TLB[1].block_address=gdt_block_address;
    fs_TLB[1].input_time=0;
    memcpy(fs_TLB[1].file_cache,temp_gdt_block_buff,BLOCKSIZE);

    gdt_block_num=2+move_to_GDT_num*BLOCK_GROUP_SIZE;
    gdt_block_address= get_Block_address(gdt_block_num);
    get_block_from_file(gdt_block_address,temp_gdt_block_buff);
    fs_TLB[2].cache_state=0;
    fs_TLB[2].block_address=gdt_block_address;
    fs_TLB[2].input_time=0;
    memcpy(fs_TLB[2].file_cache,temp_gdt_block_buff,BLOCKSIZE);
}