#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

void sigHandler(int x) {
    //printf("This is the handler\n");
    wait(NULL);
}

int main() {
    int pid = fork();
    if(pid == 0) {
        sleep(1);
        printf("%d\tThis is the child\n", getpid());
    }
    else {
        signal(SIGCHLD, sigHandler);
        printf("%d\tThis is the parent\n", getpid());
        system("ps -el | grep a.out");
    }
}