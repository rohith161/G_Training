#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int microShellV1();

int main() {
    microShellV1();
    return 0;
}

int microShellV1(){
    printf("\n\t\t--- Welcome to Micro Shell - V1 ---\n\n\n");
    char input[100];
    int status;
       int byteread = 0;
        byteread = write(1, "MicroShell] ",strlen("MicroShell] "));
        if(byteread < 0){
            perror("write");
            return errno;
        }
        byteread = read(0,input,sizeof(input));
        if(byteread < 0){
            perror("read");
            return errno;
        }
        input[byteread-1] = '\0';

        int ret = fork();

        if (ret < 0) {
            perror("fork");
            return errno;
        }

        if (ret == 0) {
            char* token = strtok(input, " ");
            char* args[10];
            int i = 0;
            while (token != NULL) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            int k = execvp(args[0], args);
            if (k < 0) {
                perror("execvp");
                return errno;
            }
        } else {
            waitpid(ret,&status,0);
            printf("exit status = %d\n",WEXITSTATUS(status));
        }
    

}