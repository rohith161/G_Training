#include <stdio.h>
#include <stdlib.h>
typedef struct city_info{
    char name[20];
    double Temperature;
    int Humidity;
}city_info;


city_info* create();
void read_info(city_info* ptr,int n);
void print_info(city_info* ptr,int n);

int main(){
    int n = 0;
    printf("\nEnter the number of Cities To be entered : ");
    scanf("%d",&n);
    city_info* info = create(n);
    read_info(info,n);
    print_info(info,n);
    free(info);
}

city_info* create(int n){
    city_info* new = (city_info*)calloc(n,sizeof(city_info));
    if(new == NULL){
        perror("\nMemeory allocation failed");
        free(new);
        exit(0);
    }
    return new;
}

void read_info(city_info* ptr,int n){
    for(int i=0; i<n; i++){
        printf("\n--> City No %d :\n",i+1);
        printf("\nEnter the City name : ");
        scanf("%s",ptr[i].name);
        printf("\nEnter the Temperature : ");
        scanf("%lf",&ptr[i].Temperature);
        printf("\nEnter the Humidity : ");
        scanf("%d",&ptr[i].Humidity);
    }
}

void print_info(city_info* ptr,int n){
    for(int i =0; i<n; i++){
        printf("\n--> City No %d :\n",i+1);
        printf("\nCity name : %s",ptr[i].name);
        printf("\nTemperature : %0.2lf",ptr[i].Temperature);
        printf("\nHumidity : %d\n\n",ptr[i].Humidity);
    
    }
    
}