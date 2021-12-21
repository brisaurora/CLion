#include <iostream>
#include "cstring"
using namespace std;
typedef struct a
{
    short d;
    short l;
    double c;
    int a;
}aa[10];
int main() {
    FILE *file;
    file= fopen("TEST_READ","rb+");
    fseek(file,10,SEEK_SET);
    char temp_buf[1220];
    char meg[1024];

    int i=0;

    while(i<1024) {

        scanf("%c", meg + i);

        if (meg[i] == '$') break;
        i++;
    }
    fwrite(meg, strlen(meg),1,file);
    fseek(file,0,SEEK_SET);
    memset(meg,0,sizeof(meg));
    fread(meg, 20,1,file);
    cout<<"%"<<endl;
    cout<<meg<<endl;
    return 0;
}
