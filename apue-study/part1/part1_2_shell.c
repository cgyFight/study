// 读取命令并执行，比如输入ls,则执行Ls并将其结果输出
#include "apue.h"
#include <sys/wait.h>

int main(int argc, char **argv)
{
    char buf[MAXLINE];

    pid_t pid;
    int status;

    printf("%% ");

    while (fgets(buf, MAXLINE, stdin)) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = '\0';
        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            //exec the order
            execlp(buf, buf, NULL);
            err_ret("couldn't excte: %s", buf);
            exit(127);
        }

        //parent: wait the process exit
        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }
        printf("%% ");
    }
 

    return 0;
}
