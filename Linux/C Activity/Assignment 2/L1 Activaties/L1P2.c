#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[20];
    double Temperature;
    int Humidity;
}city_info;

city_info* create();
void read_info(city_info* ptr);
void print_info(city_info* ptr);

int main(){
    city_info* info = create();
    read_info(info);
    print_info(info);
}

void read_info(city_info* ptr){
    printf("\nEnter the City name : ");
    scanf("%s",ptr->name);
    printf("\nEnter the Temperature : ");
    scanf("%lf",&ptr->Temperature);
    printf("\nEnter the Humidity : ");
    scanf("%d",&ptr->Humidity);

}

void print_info(city_info* ptr){
    printf("\nCity name : %s",ptr->name);
    printf("\nTemperature : %lf",ptr->Temperature);
    printf("\nHumidity : %d",ptr->Humidity);
}

city_info* create(){
    city_info* new = (city_info*)calloc(1,sizeof(city_info));
    if(new == NULL){
        perror("\nMemeory allocation failed");
        free(new);
        exit(0);
    }
    return new;
}