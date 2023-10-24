#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFileFormat(char* s);
void erroCaseHandling(int argc,char* str);
void fileValidation(char* argv);

int main(int argc,char **argv){
    //printf("\n%d\n%s\n",argc,argv[1]);
    erroCaseHandling(argc,argv[1]);
    //readFileFormat(argv[1]);
    return 0;

}


void erroCaseHandling(int argc,char* argv){

    if(argc < 2){
        printf("\nYou have provided few arguments\n");
        printf("\nexiting..\n");
        exit(0);
    }
    else if(argc > 2){
        printf("\nYou have provided too many arguments\n");
        printf("\nexiting..\n");
        exit(0);
    }
    else if (argc == 2)
    {
        printf("\nReading the file \"%s\"...\n",argv);
        readFileFormat(argv);
    }
    
}
void readFileFormat(char* argv){
    if(strlen(argv) <= 5){
        printf("\nProvided file name doesn't matches the criteria\n");
        printf("\nproceeding to checking the file format whether the file \"%s\" is JPEG/JPG or not...\n",argv);
        fileValidation(argv);
        printf("\nexiting..\n");
        exit(0);
    }
    // printf("\n->%s\n",str);
    // int len = strlen(str);
    //printf("\n---->%s\n",s);

    char ext[6];
    //if()
    strncpy(ext,argv+strlen(argv)-5,5);
    //printf("\n%s - > %lu\n",ext,strlen(ext));
    if(strcmp(ext,".jpeg") == 0 || strcmp(ext+1,".jpg") == 0){
        printf("\nProvided file name matches the criteria\n");
        printf("\nproceeding to checking the file format whether the file \"%s\" is JPEG/JPG or not...\n",argv);
        fileValidation(argv);
        printf("\nexiting...\n");
        exit(0);
    }
    else{
        printf("\nProvided file name doesn't match the criteria\n");
        printf("\nproceeding to checking the file format whether the file \"%s\" is JPEG/JPG or not...\n",argv);
        fileValidation(argv);
        printf("\nexiting...\n");
        exit(0);
    }

}

void fileValidation(char* argv){
    FILE* file = fopen(argv,"rb");
    if(file == NULL){
        printf("\nUnable to access the file / not found -> \"%s\"\n",argv);
        exit(0);
    }

    unsigned char buffer[3];
    fread(buffer,1,3,file);
    if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
    {
            printf("\n -> \"%s\" is a JPEG/JPG File\n",argv);
    }
    else{
        printf("\n -> \"%s\" is not a JPEG/JPG File\n",argv);
        fclose(file);
        exit(0);
    }
    fclose(file);
}