#include "apue.h"
#include <error.h>

int main(int argc, char **argv)
{
    fprintf(stderr, "EACESS: %s\n", strerror(EACCES));
    errno = ENOENT;
    errno = EACCES;
    perror("this:");
    getc(stdin);

    return 0;
}
