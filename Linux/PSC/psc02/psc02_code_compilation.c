#include <stdio.h> // for input / output functions
#include <stdlib.h> 
#include <errno.h> // for error message
#include <fcntl.h> // for flag macros in open
#include <unistd.h> // for syscall open, write read
#include <string.h> // for string functions
#include <sys/wait.h> // for waitpid process to get the status of cjild status

int codeCompilation(char** argv);

int main(int argc, char** argv) {
    if(argc < 2 || argc > 2){
        errno=EINVAL;
            perror("Error");
		    return errno;
    }

    int len = strlen(argv[1]);
    
    
    if (strstr(argv[1]+len-2, ".c") == NULL && strstr(argv[1]+len-2, ".C") == NULL) {
        printf("\n \"%s\" is not a \'.c\' File\n",argv[1]);
        return 0;
    }

    codeCompilation(argv);
    return 0;
}

int codeCompilation(char** argv) {
    printf("\n\t\t--- Code Compilation ---\n\n\n");  
    
    int status;
    
    int src_fd = open(argv[1],O_RDONLY);
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
        
        close(2); // To close the stderr of the file descriptor while compiling the .c file
        open("/dev/null", O_WRONLY); //  now open the /dev/null to redirect the stderr msg to the null file
        char* args[4];
        args[0] = "gcc";
        args[1] = argv[1];
        args[2] = NULL;
        int k = execvp(args[0], args);
        if (k < 0) {
            perror("execvp");
            return errno;
        }
    } else {

        waitpid(ret,&status,0); // to check the compiled status from the child process using waitpid()
        
        if(status == 0){ // if status is 0 means that the compilation is successful , then execute a.out else compilation error
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
