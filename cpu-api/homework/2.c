#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

#define BUFFER_SIZE 10
char buffer[BUFFER_SIZE];

int main() {
    ssize_t bytesRead;
    int fd = open("test.txt",  O_RDWR, 0);
    if (fd == - 1) {
        printf("\nerror opening file");
        return 0;
    }
    
    /* Checking if fd opened in parent valid in forked child */
    pid_t pid = fork();
    if (pid == 0) {
        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
            printf("\nBytes read child");
            write(STDOUT_FILENO, buffer, BUFFER_SIZE);
        }
        if (bytesRead == -1) {
            printf("\nerror reading file");
            return 1;
        }

        ssize_t wc; 
        if ((wc = write(fd, "child", strlen("child"))) < 0) {
            printf("\nWrite error");
        }
    } else {
        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
            printf("\nBytes read parent");
            write(STDOUT_FILENO, buffer, BUFFER_SIZE);
        }
        if (bytesRead == -1) {
            printf("\nerror reading file");
            return 1;
        }

        ssize_t wc; 
        if ((wc = write(fd, "parent", strlen("parent"))) < 0 ) {
            printf("\nWrite error");
        }
    }

    /* Writing to same file*/



    
    return 0;
}