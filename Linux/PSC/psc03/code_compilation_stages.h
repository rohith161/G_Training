#include <stdlib.h> 
#include <errno.h> // for error message
#include <fcntl.h> // for flag macros in open
#include <unistd.h> // for syscall open, write read
#include <string.h> // for string functions
#include <sys/wait.h> // for waitpid process to get the status of cjild status
#include <sys/stat.h>
#include <sys/types.h>

char dirName[] = "IntermediateFile"; // IntermediateFile folder / directory

void makeDirectory();
int executeCmd(char* cmd,char* fileName);
int shellExecution(char* cmd);

void makeDirectory(){
    int ret = mkdir(dirName,0777);
    //printf("\ndir -> %d\n",ret);
    return;
}

int executeCmd(char* cmd,char* fileName){

    char temp[100];

    if(strcmp(cmd,"cldir") == 0){

        snprintf(temp, sizeof(temp), "rm -rf %s",dirName);
        int ret = shellExecution(temp);
       // fprintf(stderr,"\n%s\n",strerror(ret));

        return 0;
    }
    else if(strcmp(cmd,"Preprocessing") == 0){
        int len = strlen(fileName);
        //char temp[50];
        snprintf(temp, sizeof(temp), "gcc -E %s -o ./IntermediateFile/%.*si", fileName, len - 1, fileName);
        return shellExecution(temp);
    }
    else if(strcmp(cmd,"Compiling") == 0){
        int len = strlen(fileName);
        //char temp[50];
        snprintf(temp, sizeof(temp), "gcc -S %s -o ./IntermediateFile/%.*ss", fileName, len - 1, fileName);
        return shellExecution(temp);
    }
    else if(strcmp(cmd,"Assembling") == 0){
        int len = strlen(fileName);
        //char temp[50];
        snprintf(temp, sizeof(temp), "gcc -c %s -o ./IntermediateFile/%.*so", fileName, len - 1, fileName);
        return shellExecution(temp);
    }
    else if(strcmp(cmd,"Linking") == 0){
        int len = strlen(fileName);
        snprintf(temp, sizeof(temp), "gcc ./IntermediateFile/%.*so -o ./IntermediateFile/%.*sout",len-1, fileName, len - 1, fileName);
        return shellExecution(temp);
    }
    else{
        errno = EINVAL;
        perror("Error");
        return errno;
    }

}

int shellExecution(char* cmd){
        int status = 0;
        int ret = fork();
        if (ret < 0) {
            perror("fork");
            return errno;
        }

        if (ret == 0) {
            close(2); // To close the stderr of the file descriptor while compiling the .c file
            open("/dev/null", O_WRONLY); //  now open the /dev/null to redirect the stderr msg to the null file
            char* token = strtok(cmd, " ");
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
        } 
        else{
            waitpid(ret,&status,0);
            if(status == 0){ // if status is 0 means that the compilation is successful , then execute a.out else compilation error
                return status;
            }
            else{
                executeCmd("cldir",dirName);
                makeDirectory();
                fprintf(stderr,"\n\ncode_comp: Compilation Failed\nClearing the files and Aborting...\n");
                exit(1);
            }   
            
        }
}