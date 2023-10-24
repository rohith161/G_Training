#include <stdio.h>
#include <string.h>

void readFile(char* name){
    FILE* file = fopen(name, "r");
    if(file == NULL){
        printf("\nThe source File NOT FOUND/Unable to open \n");
    }
    char buffer[1024];
    while (fgets(buffer,sizeof(buffer),file))
    {
        char* Token = strtok(buffer,",");
        while (Token != NULL)
        {
            printf("%s ",Token);
            Token = strtok(NULL,",");
        }
        printf("\n");
        
    }fclose(file);
    
}
void writeFile(char* name){
    FILE* file = fopen(name,"r+");
    if(file == NULL){
        printf("\nThe source File NOT FOUND/Unable to open \n");
    }
    char buffer[1024];
    fgets(buffer,sizeof(buffer),file);
    char* Headings[19];
    char* Token = strtok(buffer,",");
    int i = 0;
    while (Token != NULL)
    {
        Headings[i] = Token;
        printf("%s ",Headings[i]);
        Token = strtok(NULL,",");
        i++;
    }
    buffer[0] = '\0';
    int n = sizeof(Headings)/sizeof(int);
    int flag = 0;
    printf("\nAppend the Data to FILE press 1 else 0 to exit : ");
    scanf("%d",&flag);
    while(flag == 1)
    {
    for(int i=0; i<19; i++){
        printf("%s\n",Headings[i]);
        printf("\n%s -> ",Headings[i]);
        char input[20];
        scanf("%s",input);
        strcat(buffer,input);
        if(i+1 != n-1){
            strcat(buffer,",");
        }
    printf("\nAppend the Data to FILE press 1 else 0 to exit : ");
    scanf("%d",&flag);
    }
    fprintf(file,"%s\n",buffer);
    }
    // for(int i=0; i<19; i++)
    // printf("%s\n",Headings[i]);
    
}
int main(){
    //readFile("car_price_prediction.csv");
    writeFile("car_price_prediction copy.csv");
    return 0;
}