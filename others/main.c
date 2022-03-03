
#include <stdio.h>
#include "stdlib.h"
char Legal_Big_characters[5]="JQKA";
char Legal_characters_transform[4][3]={"10","11","12","13"};
int main() {
    FILE *fp;
    printf("ÊäÈë'#'Í£Ö¹ÊäÈë\n");
    fp=fopen("result.txt","a+");
    char character='A';
    int i;
    while (character!='#')
    {
        character=(char)getchar();
        if(character>='a'&&character<='z')
            character-=32;

        for (i = 0; i < 4; i++)
            if (character == Legal_Big_characters[i])
                break;
        if(character>='0'&&character<='9') {
            fwrite(&character, sizeof(character), 1, fp);
            fwrite(" ", sizeof(" "),1,fp);
        } else if(i<4)
        {
            fwrite(Legal_characters_transform[i], sizeof(Legal_characters_transform[i]),1,fp);
            fwrite(" ", sizeof(" "),1,fp);
        }
    }
    fwrite("\n", sizeof("\n"),1,fp);
    fclose(fp);
    system("pause");
    return 0;
}
