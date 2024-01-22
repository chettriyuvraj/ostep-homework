#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int global_x = 25;

int main() {
    int local_x = 5;
    pid_t pid = fork();
    if (pid == 0) {
        printf("\nWaiting in child\n");
        pid_t child_rc = wait(NULL);
        printf("\nDone waiting in child %d\n", child_rc);
    } else {
        printf("\nWaiting in parent\n");
        pid_t child_rc = wait(NULL);
        printf("\nDone waiting in parent %d\n", child_rc);
    }
    return 0;
}