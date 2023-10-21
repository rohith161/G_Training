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
        printf("%s", "MicroShell] ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

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