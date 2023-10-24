#include <stdio.h>

void printOddEvenLinesOfFile();

int main(){
    printOddEvenLinesOfFile();
    return 0;
}

void printOddEvenLinesOfFile(){
    char fileName[15];
    printf("\n Enter the file Name : ");
    scanf("%s",fileName);

    FILE* file = fopen(fileName,"r");
    if(file == NULL){
        printf("\nUnable to access the file / not found -> \"%s\"\n",fileName);
        return;
    }
    char buffer[200];
    int count = 1;
    printf("\n-- ODD lines of the file : \"%s\" --\n\n",fileName);
    while (fgets(buffer,sizeof(buffer),file) != NULL){
           if(count%2 != 0){
               fputs(buffer,stdout);
           }
           count++;
    }
    count = 1;
    rewind(file);
    printf("\n\n-- EVEN lines of the file : \"%s\" --\n\n",fileName);
    while (fgets(buffer,sizeof(buffer),file) != NULL)
        {   if(count%2 == 0){
                fputs(buffer,stdout);
            }
            count++;
        }
        fclose(file);
}