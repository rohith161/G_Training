#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int codeCompilation();

int main() {
    codeCompilation();
    return 0;
}

int codeCompilation() {
    printf("\n\t\t--- Code Compilation ---\n\n\n");  
    char input[100];
    int status;
    int byteread = 0;
    byteread = write(1, "$ ", strlen("$ "));
    if (byteread < 0) {
        perror("write");
        return errno;
    }
    byteread = read(0, input, sizeof(input));
    if (byteread < 0) {
        perror("read");
        return errno;
    }
    input[byteread-1] = '\0';

    if (strstr(input, ".c") == NULL && strstr(input, ".C") == NULL) {
        errno = 2;
        perror("Error");
        return errno;
    }
    int src_fd = open(input,O_RDONLY);
    if(src_fd == -1){
        perror("open");
        close(src_fd);
        return errno;
    }
    close(src_fd);
    int ret = fork();

    if (ret < 0) {
        perror("fork");
        return errno;
    }

    if (ret == 0) {
        //printf("\n%s\n", input);
        close(2);
        open("/dev/null", O_WRONLY);
        char* args[4];
        args[0] = "gcc";
        args[1] = input;
        args[2] = NULL;
        int k = execvp(args[0], args);
        if (k < 0) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(ret,&status,0);
        
        if(status == 0){
        int k = execl("./a.out", "./a.out",NULL);
        if (k < 0) {
            perror("execvp");
            return errno;
        }
        }
        else{
            write(2,"code_comp: Compilation Failed\n",sizeof("code_comp: Compilation Failed"));
        }
        
    }
}
