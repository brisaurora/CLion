#include <stdio.h>
#include <stdlib.h>
#include "dirent.h"
#include "sys/types.h"
#include "errno.h"
#include "string.h"
int main(int argc, char **argv)
{
    DIR *streamp;
    struct dirent *dep;

    streamp = opendir(argv[1]);

    errno = 0;
    while ((dep = readdir(streamp)) != NULL) {
        printf("Found file: %s\n", dep->d_name);
    }
    if (errno != 0)
        printf("readdir error\n");

    closedir(streamp);
    exit(0);
}
