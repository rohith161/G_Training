#include <stdio.h>

typedef struct {
    char name[20];
    double Temperature;
    int Humidity;
}city_info;

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
int main(){
    city_info* info;
    read_info(info);
    print_info(info);
}