#include<stdio.h>
#include<unistd.h>


int main() {
    pid_t pid, child_pid;
    int exec_rc;

    // exec_rc = execl("/bin/ls", "/bin/ls", "-l", "-a");
    // if (exec_rc == -1) {
    //     printf("\nexecl error");
    // }

    // exec_rc = execlp("ls", "ls", "-l", "-a");
    // printf("execlp");
    // if (exec_rc == -1) {
    //     printf("\nexeclp error");
    // }

    char *args[] = {"/bin/ls","-l", "-a", NULL};
    exec_rc = execv("/bin/ls", args);
    printf("execv");
    if (exec_rc == -1) {
        printf("\nexecv error");
    }


}