#include <stdio.h>
#include <stdlib.h>
#include "fcntl.h"
#include "unistd.h"
#include "sys/stat.h"
int main (int argc, char **argv)
{
    struct stat f_stat;
    char *type, *readok;

    stat(argv[0], &f_stat);
    if (S_ISREG(f_stat.st_mode)) /* Determine file type */
        type = "regular";
    else if (S_ISDIR(f_stat.st_mode))
        type = "directory";
    else
        type = "other";

    if ((f_stat.st_mode & S_IRUSR)) /* Check read access */
        readok = "yes";
    else
        readok = "no";

    printf("type: %s, read: %s\n", type, readok);
    exit(0);

}