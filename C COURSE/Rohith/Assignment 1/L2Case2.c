#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readFile(char* name){
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
    char *h = readFile(name);
    //printf("%s\n",h);
    char buf[1024];
    char* Token = strtok(h,",");
        while (Token != NULL)
        {
            printf("%s -> ",Token);
            char temp[50];
            Token = strtok(NULL,",");
            fgets(temp,sizeof(temp),stdin);
            strncpy(buf+strlen(buf),temp,strlen(temp)-1);
            //strcat(buf-1,temp);
            if(Token != NULL){
                //strcat(buf-2,",");
                strncpy(buf+strlen(buf),",",1);
            }
            else{
                strncpy(buf+strlen(buf),"\n\0",2);
            }
        }
        fputs(buf,file);
    // for(int i=0; i<20; i++){
    //     printf("%s -> ",h[i]);
    //     char buffer[100];
    //     fgets(buffer,sizeof(buffer),stdin);
    //     fputs(buffer,file);
    //     printf("\n");
    // }
        //printf("\n");

        fclose(file);
}
int main(){
    char name[] = "car_price_prediction.csv";
    appendFile(name);
    return 0;
}