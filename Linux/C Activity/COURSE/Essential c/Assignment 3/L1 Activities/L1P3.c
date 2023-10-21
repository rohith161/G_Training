#include <stdio.h>
#include <stdlib.h>

void mergeFile();

int main(){
    mergeFile();
    return 0;
}

void mergeFile(){
    char file1[15];
    printf("\n Enter the first file Name : ");
    scanf("%s",file1);

    FILE* fileone = fopen(file1,"r");
    if(fileone == NULL){
        printf("\nUnable to access the file / not found -> \"%s\"\n",file1);
        return;
    }

    char file2[15];
    printf("\n Enter the second file Name : ");
    scanf("%s",file2);
     FILE* filetwo = fopen(file2,"r");
    if(filetwo == NULL){
        printf("\nUnable to access the file / not found -> \"%s\"\n",file2);
        return;
    }
   
    FILE* filethree = fopen("mergedFile.txt","w");
    if(filethree == NULL){
        printf("\nUnable to create the Merged File \n");
        return;
    }
    char buffer[200];
    while (fgets(buffer,sizeof(buffer),fileone) != NULL)
        {
            fprintf(filethree,"%s",buffer);
        }
        fclose(fileone);
        fprintf(filethree,"%s","\n");
    while (fgets(buffer,sizeof(buffer),filetwo) != NULL)
        {
            fprintf(filethree,"%s",buffer);
        }
        fclose(filetwo);
        fclose(filethree);
        printf("\nSuccessfully completed the merging of file 1 \"%s\" and file 2 \"%s\" to \"%s\"\n",file1,file2,"mergedFile");

}