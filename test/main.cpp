#include <iostream>
#include "cstring"
using namespace std;
typedef struct a
{
    short d;
    short l;
    double c;
    int a;
    char s[20];
    string t;
}aa[10];
int main() {
    FILE *file;
    file= fopen("TEST_READ","rb+");
    fseek(file,10,SEEK_SET);
    char temp_buf[1220];
    char meg[1024];
    char *sp;
    int i=0;
    struct a cc;
    strcpy(cc.s,"1234567890123456");
    printf("%d",sizeof (cc));
    cc.t="1212323";
    char d[1000];
    memset(d,0,1000);
    memcpy(d,&cc,1000);
    strcpy(d,cc.t,sizeof (cc.t));
    while(i<1024) {
        scanf("%c", meg + i);
        if (meg[i] == '\n')
        {
            meg[i]='\0';
            break;}
        i++;
    }
    sp= strtok(meg,"/");
    i=0;
    char save_sp[300]="";
    while (sp!=NULL)
    {
        if(!strcmp(sp,""))
            printf("exit\n");

        printf("********%s %s %d\n",sp,save_sp,i);

        //对应cd
        //check
        //s_sp==sp 目录进入失败
        //sp==NULL 目录进入成功

        //对于创建
        //sp==NULL
        //重名
        strcat(save_sp,"/");
        strcat(save_sp,sp);
        sp= strtok(NULL,"/");


    }
    fwrite(meg, strlen(meg),1,file);
    fseek(file,0,SEEK_SET);
    memset(meg,0,sizeof(meg));
    fread(meg, 20,1,file);
    cout<<"%"<<endl;
    cout<<meg<<endl;
    return 0;
}
