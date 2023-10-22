#include <stdio.h>
#include "code_compilation_stages.h"

int codeCompilation(int argc, char** argv);
int exerror(char* stage, int ret);
int fileCheck(int argc, char** argv);

int main(int argc, char** argv){
    codeCompilation(argc,argv);
    return 0;
}


int codeCompilation(int argc, char** argv){
    fileCheck(argc,argv);
    char dirName[] = "IntermediateFile";
    printf("\nCreating the %s's Directory\n",dirName);
    makeDirectory();

    int len = strlen(argv[1]);
    int ret = 0;

    fprintf(stderr,"\nGenerating the Preprocessing %.*si file",len-1,argv[1]);
    ret = executeCmd("Preprocessing",argv[1]);
    exerror("Preprocessing",ret);

    fprintf(stderr,"\nGenerating the Compiling %.*ss file",len-1,argv[1]);
    ret = executeCmd("Compiling",argv[1]);
    exerror("Compiling",ret);

    fprintf(stderr,"\nGenerating the Assembling %.*so file",len-1,argv[1]);
    ret = executeCmd("Assembling",argv[1]);
    exerror("Assembling",ret);

    fprintf(stderr,"\nGenerating the Linking %.*sout file",len-1,argv[1]);
    ret = executeCmd("Linking",argv[1]);
    exerror("Linking",ret);

    fprintf(stderr,"\nExecuting the %.*sout file",len-1,argv[1]);
    if(ret == 0){
        char temp[100];
        snprintf(temp, sizeof(temp), "./IntermediateFile/%.*sout",len - 1, argv[1]);
        ret = shellExecution(temp);
        exerror("Executing",ret);

    }
    


}

int exerror(char* stage,int ret){
    
    if(ret >= 0){
        printf("\n%s has been done\n",stage);
    }
    else{
        fprintf(stderr,"\n\ncode_comp: Compilation Failed\nClearing the files and Aborting...\n");
        executeCmd("cldir","IntermediateFile");
        makeDirectory();
        exit(1);
    }
}

int fileCheck(int argc,char** argv){
    if(argc == 1){
        fprintf(stderr, "Error: file operand missing\nAborting...\n");
        exit(1);
    }
    if(argc > 2){
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