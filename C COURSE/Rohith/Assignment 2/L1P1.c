#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void scan_info(char* City,double* Temperature,int* Humidity){
     printf("\nEnter the City Name : ");
     fgets(City,20,stdin);
     //scanf("%20s",City);
     printf("\nEnter the Temperature : ");
     scanf("%lf",Temperature);
     printf("\nEnter the Humidity : ");
     scanf("%d",Humidity);
 }
void print_info(char *City,double *Temperature,int *Humidity){
     //fputs(City,stdout);
     printf("\nCity Name -> %s",City);
     printf("\nTemperature -> %lf",*Temperature);
     printf("\nHumidity -> %d\n",*Humidity);
     
}

int main()
{
    char City[20];
    double Temperature;
    int Humidity = 0;
    scan_info(City,&Temperature,&Humidity);
    print_info(City,&Temperature,&Humidity);
    

    return 0;
}
