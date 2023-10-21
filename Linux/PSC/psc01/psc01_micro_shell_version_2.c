#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int microShellV2();

int main() {
    microShellV2();
    return 0;
}

int microShellV2(){
    printf("\n\t\t--- Welcome to Micro Shell - Version 2 ---\n\n\n");
    char input[100];

    while(1) {
        printf("%s", "MicroShell] ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            break;
        }

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
            wait(NULL);
        }
    }

}