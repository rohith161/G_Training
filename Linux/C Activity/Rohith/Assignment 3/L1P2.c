#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void fileToUpperCase();

int main(){
    fileToUpperCase();
    return 0;
}

void toUp(char* buffer){
    for(int i=0; buffer[i] != '\0'; i++){
        if(buffer[i] >= 'a' && buffer[i] <= 'z'){
            buffer[i] -= 32;
        }
    }
}
void fileToUpperCase(){
    char fileName[15];
    printf("\n Enter the file name To convert the file contents to Upper Case : ");
    scanf("%s",fileName);
    FILE* file = fopen(fileName,"r");
    if(file == NULL){
        printf("\nUnable to access the file / not found\n");
        return;
    }
    FILE* temp = fopen("temp.txt","w");
    char buffer[200];
    while (fgets(buffer,sizeof(buffer),file) != NULL)
    {
        toUp(buffer);

        fprintf(temp,"%s",buffer);
    }
    fclose(temp);
    fclose(file);
    rename("temp.txt",fileName);
    printf("\nSuccessfully done the UpperCase conversion of the file Named \"%s\"\n",fileName);
    
}