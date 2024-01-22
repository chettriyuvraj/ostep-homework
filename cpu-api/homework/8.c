#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

/* Let's connect STDOUT of child to STDIN of parent and print */

#define BUFFER_SIZE 50

int main() {
    int stdin_parent = STDIN_FILENO;
    char read_buffer[BUFFER_SIZE];
    int p[2];
    pid_t pid;

    int pipe_rc = pipe(p); 
    if (pipe_rc == -1) {
        printf("Pipe error\n");
    } 

    printf("First fork\n");
    pid = fork();
    if (pid == 0) {
        close(p[0]);
        ssize_t write_rc = write(p[1], "Sending a letter from CP1 to CP2 :)", (strlen("Sending a letter from CP1 to CP2 :)") + 1));
        if (write_rc == -1) {
            printf("Write error\n");
            exit(1);
        }
        close(p[1]);
        exit(0);
    }

    pid_t child_pid1 = wait(NULL);
    printf("Second fork\n");
    pid = fork();
    if (pid == 0) {
        close(p[1]);
        ssize_t read_rc = read(p[0], read_buffer, BUFFER_SIZE);
        if (read_rc == -1) {
            printf("Read error\n");
            exit(1);
        }
        close(p[0]);
        printf("Letter received from process 1: %s\n", read_buffer);
        exit(0);
    }

    pid_t child_pid2 = wait(NULL);
    printf("Successfully implemented pipe!");

}