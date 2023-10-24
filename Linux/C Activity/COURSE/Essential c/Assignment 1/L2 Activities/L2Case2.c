#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readFirstLine(char* name){
    FILE* file = fopen(name,"r");
    if(file == NULL){
        printf("\nFILE NOT FOUND\n");
        return '\0';
    }
    char* h = (char*)calloc(1000,sizeof(char));
    fgets(h,1000,file);
     // printf("%s\n",h);
    fclose(file);
    return h;

}
void appendFile(char* name){
    FILE* file = fopen(name,"a");
    if(file == NULL){
        printf("\nFILE NOT FOUND\n");
        return ;
    }
    char *h = readFirstLine(name);
    //printf("%s\n",h);
    char* buf = (char*)calloc(300,sizeof(char));;
    char* Token = strtok(h,",");
        while (Token != NULL)
        {
            printf("%s -> ",Token);
            char* temp = (char*)calloc(20,sizeof(char));
            Token = strtok(NULL,",\n");
            fgets(temp,20,stdin);
            strncpy(buf+strlen(buf),temp,strlen(temp)-1);
            free(temp);
            if(Token != NULL){
                //strcat(buf-2,",");
                strcat(buf,",");
            }
            else{
                strcat(buf,"\n");
            }
        }
        printf("\n%s\n",buf);
        fputs(buf,file);
        free(buf);
        fclose(file);
}
int main(){
    char name[] = "car_price_prediction.csv";
    appendFile(name);
    return 0;
}