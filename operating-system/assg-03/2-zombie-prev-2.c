#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    int pid = fork();
    if(pid == 0) {
        printf("%d\tThis is the child\n", getpid());
    }
    else {
        signal(SIGCHLD,SIG_IGN);
        printf("%d\tThis is the parent\n", getpid());
        system("ps -el | grep a.out");
    }
}