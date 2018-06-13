#include <stdio.h>

#include "apue.h"

#include <sys/types.h>
#include <dirent.h>

// 列出一个目录中的所有文件
int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *dirp;

    if (argc != 2)
    {
        printf("wtc\n");
        err_quit("usage : ls directory_name");
    }

    if (NULL != (dir = opendir(argv[1])))
    {

        while ((dirp = readdir(dir)) != NULL)
        {
            printf("%s\n", dirp->d_name);
        }
    }
    else
    {
        err_sys("can't open %s\n", argv[1]);
    }

    return 0;
}