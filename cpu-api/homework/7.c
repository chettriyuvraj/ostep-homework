#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>


int main() {
    pid_t pid;

    printf("\n\nForking child:\n");
    pid = fork();
    if (pid == 0) {
        printf("\n\nClosing stdout in child:\n");
        close(STDOUT_FILENO);
        printf("\n\nTrying to print to stdout in child:\n");
    } else {
        pid_t child_pid;
        child_pid = wait(NULL);
        printf("\n\nTrying to print to stdout in parent:\n");
    }

    return 0;
}