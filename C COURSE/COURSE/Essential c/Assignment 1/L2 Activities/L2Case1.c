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
int main(){
    readFile("car_price_prediction.csv");
    return 0;
}