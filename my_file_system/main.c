#include <stdio.h>
#include "string.h"
#include "fs_operation.h"

int main() {

    char cmd_buff[300],*sp;
    int cmd_num;
    start_fs();
    init_root_dir_inode();
    FILE *file;

    printf("****************file system start********************\n");
    while (1)
    {
        //printf("%d\n",openfilelist[currfd].inode_num);
        printf("%s>",openfilelist[currfd].dir);
        gets(cmd_buff);
        if(!strcmp(cmd_buff,""))
        {
            printf("\n");
            continue;
        }
        sp= strtok(cmd_buff," ");
        cmd_num= select_cmd(sp);
        switch(cmd_num) {
            case my_ls_t:my_ls();break;
            case my_format_t:my_format();init_openfile();init_root_dir_inode();break;
            case my_mkdir_t:sp= strtok(NULL," ");
            if(sp!=NULL)
                my_mkdir(sp);
            else
                printf("you need to input a name to mkdir!\n");break;
            case my_exit_t:my_exit();return 0;
            case my_close_t:my_close(currfd);break;
            case my_write_t:my_write(currfd);break;
            case my_read_t:my_read(currfd);break;
            case my_rmdir_t:sp= strtok(NULL," ");
                if(sp!=NULL)
                    my_rmdir(sp);
                else
                    printf("you need to input a name to rmdir!\n");break;
            case my_rm_t:sp= strtok(NULL," ");
                if(sp!=NULL)
                    my_rm(sp);
                else
                    printf("you need to input a name to rm!\n");break;
            case my_cd_t:sp= strtok(NULL," ");
                if(sp!=NULL)
                    my_cd(sp);
                else
                    printf("you need to input a name to cd!\n");break;break;
            case my_create_t:sp= strtok(NULL," ");
                if(sp!=NULL)
                    my_create(sp);
                else
                    printf("you need to input a name to create!\n");break;break;
            case my_open_t:sp= strtok(NULL," ");
                if(sp!=NULL)
                    my_open(sp);
                else
                    printf("you need to input a name to open!\n");break;break;

            default:
                printf("wrong cmd!\n");
                printf("%d ",get_free_Inode());
                printf("%d \n",get_free_block());
                /*for(int i=0;i<PER_BLOCK_GROUP_INODE_MAX_NUM/16;i++)
                {

                    printf("%d ",fs_TLB[2].file_cache[i]);
                    if(i%32==0&&i!=0)
                        printf("\n");

                }
                printf("%d",fs_TLB[2].block_address);*/
                break;
        }
    }
}
