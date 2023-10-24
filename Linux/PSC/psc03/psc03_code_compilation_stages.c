#include <stdio.h>
#include "code_compilation_stages.h"

int codeCompilation(int argc, char** argv);
int exerror(char* stage, int ret);
int fileCheck(int argc, char** argv);

int main(int argc, char** argv){
    fileCheck(argc,argv);
    codeCompilation(argc,argv);
    return 0;
}


int codeCompilation(int argc, char** argv){
    
    char dirName[] = "IntermediateFile";
    printf("\nCreating the %s's Directory\n",dirName);
    makeDirectory();

    int len = strlen(argv[1]);
    fprintf(stderr,"\nGenerating the Preprocessing %.*si file\n",len-1,argv[1]);
    executeCmd("Preprocessing",argv[1]);
    

    fprintf(stderr,"\nGenerating the Compiling %.*ss file\n",len-1,argv[1]);
    executeCmd("Compiling",argv[1]);
    
    fprintf(stderr,"\nGenerating the Assembling %.*so file\n",len-1,argv[1]);
    executeCmd("Assembling",argv[1]);
    

    fprintf(stderr,"\nGenerating the Linking %.*sout file\n",len-1,argv[1]);
    executeCmd("Linking",argv[1]);
    

    fprintf(stderr,"\nExecuting the %.*sout file",len-1,argv[1]);
    
        char temp[100];
        snprintf(temp, sizeof(temp), "./IntermediateFile/%.*sout",len - 1, argv[1]);
        shellExecution(temp,"Execution");

    


}


int fileCheck(int argc,char** argv){
    if(argc == 1){
        fprintf(stderr, "Error: file operand missing\nAborting...\n");
        exit(1);
    }
    if(argc > 2 || argc < 2){
        errno = 7;  //E2BIG 7 Argument list too long
        fprintf(stderr, "Error: %s\nAborting...\n", strerror(errno));
        exit(1);
    }

    if (strstr(argv[1], ".c") == NULL && strstr(argv[1], ".C") == NULL) {
        errno = 2;
        fprintf(stderr,"%s\nAborting...\n",strerror(errno));
        exit(1);
    }

    int src_fd;
    src_fd = open(argv[1],O_RDONLY);
    if(src_fd == -1){
        perror("open");
        fprintf(stderr,"Aborting...\n");
        close(src_fd);
        exit(1);
    }
    else{
        return 0;
    }
}