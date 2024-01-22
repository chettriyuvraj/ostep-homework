#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int global_x = 25;

int main() {
    int local_x = 5;
    pid_t pid = fork();
    if (pid == 0) {
        printf("\nModifying values\n\n");
        local_x = 10;
        global_x = 10;
        printf("\nModified values\n\n");
    } else {
        printf("\n\nBefore wait\n\n");
        pid_t child_pid = wait(NULL);
        printf("\n\nFinished waiting for child process %d\n\n", child_pid);
        sleep(3);
        printf("\nValue of global_x in parent after modification is %d\n\n", global_x);
    }
}