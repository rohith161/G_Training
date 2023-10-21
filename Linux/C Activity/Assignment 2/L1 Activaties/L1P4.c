#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct city_info{
    char city[20];
    double Temperature;
    int Humidity;
}city_info;

city_info* create(int size);
void read_info(city_info* ptr,int n);
void print_info(city_info* ptr,int n);
void searchCity(city_info* ptr,char* city,int n);


int main(){
    int n = 4;
    city_info* info = create(n);
    strcpy(info[0].city, "Bangalore");
    info[0].Temperature = 30.60;
    info[0].Humidity = 50;

    strcpy(info[1].city, "Mysore");
    info[1].Temperature = 31.50;
    info[1].Humidity = 40;

    strcpy(info[2].city, "Vadodara");
    info[2].Temperature = 40.50;
    info[2].Humidity = 60;

    strcpy(info[3].city, "Chennai");
    info[3].Temperature = 45.50;
    info[3].Humidity = 42;

    char city[20];
    printf("\nEnter the city name to be searched : ");
    scanf("%s",city);
    searchCity(info,city,n);
}

city_info* create(int size){
    city_info* new = (city_info*)calloc(size,sizeof(city_info));
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
        scanf("%s",ptr[i].city);
        printf("\nEnter the Temperature : ");
        scanf("%lf",&ptr[i].Temperature);
        printf("\nEnter the Humidity : ");
        scanf("%d",&ptr[i].Humidity);
    }
}

void print_info(city_info* ptr,int n){
    for(int i =0; i<n; i++){
        //printf("\n--> City No %d :\n",i+1);
        printf("\nCity name : %s",ptr[i].city);
        printf("\nTemperature : %0.2lf",ptr[i].Temperature);
        printf("\nHumidity : %d\n\n",ptr[i].Humidity);
    
    }
    
}
void lowerCase(char* city){
    for(int i=0; city[i] != '\0'; i++){
        if(isupper(city[i]))
        city[i] = city[i]+32;
    }
}
void searchCity(city_info* ptr,char* city,int n){
    lowerCase(city);
    //printf("\n%s",city);
    int i = 0;
    for(i=0; i<n; i++){
        char c[strlen(ptr[i].city)];
        strcpy(c,ptr[i].city); 
        lowerCase(c);
        if(strcmp(city,c) == 0){
            city[0] = city[0]-32;
            printf("\n-- Found the City Named : %s --\n",city);
            print_info(&ptr[i],1);
            return;
        }
       
    }
    if(i == n){
        printf("\nInformation not available\n");
        return ;
    }
}