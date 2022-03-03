#include <stdio.h>
#include <math.h>
void test_address(void *x);
int main() {
    long a;
    off64_t c;
    printf("%lld %lld!\n",sizeof (a),sizeof (c));
    //fprintf
    FILE * fp;
    fp = fopen ("file.txt", "w+");
    fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);
    fclose(fp);

    char d;
    fp = fopen("file.txt","r");
    while(1)
    {
        d = (char)fgetc(fp);
        if( feof(fp) )
        {
            break ;
        }
        printf("%c", d);
    }
    fclose(fp);
    //sprintf
    char str[80];
    float k=1.3f;
    k=powf(k,2);
    sprintf(str, "\nPi 的值 = %f %f", M_PI,k);
    puts(str);

}
