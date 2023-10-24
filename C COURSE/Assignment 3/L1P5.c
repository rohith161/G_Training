#include <stdio.h>
#include <string.h>

void countCharcaterInFile();

int main(){
    countCharcaterInFile();
    return 0;
}

void countCharcaterInFile(){
    char fileName[15];
    printf("\n Enter the file Name : ");
    scanf("%s",fileName);

    FILE* file = fopen(fileName,"r");
    if(file == NULL){
        printf("\nUnable to access the file / not found -> \"%s\"\n",fileName);
        return;
    }

    char buffer[200];
    int count = 0;
    while (fgets(buffer,sizeof(buffer),file) != NULL){
           count += strlen(buffer);
    }
    printf("\n Total of %d Characters found in file \"%s\"\n",count,fileName);
}
