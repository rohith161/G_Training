#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    char city[20];
    double Temperature;
    int Humidity;
    struct Node* next;
}Node;

typedef struct city_info{
    Node* node;
    int size;
}city_info;

Node* endPoint =  NULL;

city_info* create();
void read_info();
void print_info(city_info* ptr);
void searchCity(city_info* ptr);
void deleteCity(city_info* ptr);
double findAvgTemperature(city_info* ptr);
double findMaxTemperature(city_info* ptr);
double findMinTemperature(city_info* ptr);
int findAvgHumidity(city_info* ptr);
int findMaxHumidity(city_info* ptr);
int findMinHumidity(city_info* ptr);
void findLongestCityName(city_info* ptr);
int countOfTempinrange(city_info* ptr,double range);
void sortRecord(city_info* ptr);



int main(){
    city_info* info = create();
    read_info(info);
    read_info(info);
    read_info(info);
    print_info(info);
    searchCity(info);
    searchCity(info);
    printf("\naverage Temeprature : %0.2lf",findAvgTemperature(info));
    printf("\nmin Temeprature : %0.2lf",findMinTemperature(info));
    printf("\nmax Temeprature : %0.2lf",findMaxTemperature(info));
    printf("\naverage humidity : %d",findAvgHumidity(info));
    printf("\nmin humidity : %d",findMinHumidity(info));
    printf("\nmax humidity : %d",findMaxHumidity(info));
    findLongestCityName(info);
    printf("\ntemperrature within the range of %0.2lf : %d",(double)44.01,countOfTempinrange(info,44.01));
    sortRecord(info);
    print_info(info);
    deleteCity(info);
    print_info(info);
    
    free(info);
}

city_info* create(){
    city_info* ptr = (city_info*)calloc(1,sizeof(city_info));
    if(ptr == NULL){
        perror("\nMemeory allocation failed");
        exit(0);
    }
    ptr->node = NULL;
    ptr->size = 0;
    if(endPoint == NULL){
        endPoint = ptr->node;
    }
    return ptr;
}

Node* createNode(){
    Node* newnode = (Node*)calloc(1,sizeof(Node));
    if(newnode == NULL){
        perror("\nMemeory allocation failed");
        exit(0);
    }
    newnode->next = NULL;
    return newnode;
}
void read_info(city_info* ptr){
        Node* newnode = createNode();
        printf("\n--> City No %d :\n",++ptr->size);
        printf("\nEnter the City name : ");
        scanf("%s",newnode->city);
        printf("\nEnter the Temperature : ");
        scanf("%lf",&newnode->Temperature);
        printf("\nEnter the Humidity : ");
        scanf("%d",&newnode->Humidity);

        if (ptr->node == NULL) {
            ptr->node = newnode;
            endPoint = newnode;
        } else {
            endPoint->next = newnode;
            endPoint = newnode;
        }
            // endPoint->next = newnode;
            // endPoint = newnode->next;
}

void print_info(city_info* ptr){
    Node* current = ptr->node;
    int i = 0 ;
    while(current != NULL){
        printf("\n--> City No %d :\n",i+1);
        printf("\nCity name : %s",current->city);
        printf("\nTemperature : %0.2lf",current->Temperature);
        printf("\nHumidity : %d\n\n",current->Humidity);
        current = current->next;
        i++;
    }
    
}
void printOnce(Node* ptr){
        //printf("\n--> City No %d :\n",i+1);
        printf("\nCity name : %s",ptr->city);
        printf("\nTemperature : %0.2lf",ptr->Temperature);
        printf("\nHumidity : %d\n\n",ptr->Humidity);
    
}
void lowerCase(char* city){
    for(int i=0; city[i] != '\0'; i++){
        if(isupper(city[i]))
        city[i] = city[i]+32;
    }
}
void searchCity(city_info* ptr){
    Node* current = ptr->node;
    char city[15];
    printf("\nEnter the City Named to be searched : ");
    scanf("\n%s",city);
    lowerCase(city);
    //printf("\n%s",city);
    int i = 1;
    while(current != NULL){
        char c[strlen(current->city)];
        strcpy(c,current->city); 
        lowerCase(c);
        if(strcmp(city,c) == 0){
            city[0] = city[0]-32;
            printf("\n-- Found the City Named : %s --\n",city);
            printOnce(current);
            return;
        }
        if(i == ptr->size){
            printf("\nInformation not available\n");
            return ;
        } 
        ++i;
        current = current->next;
    }
    printf("\nInformation not available\n");
    return ;
}

double findAvgTemperature(city_info* ptr){
    Node* current = ptr->node;
    double avgTemp = 0;
    while(current != NULL){
        avgTemp += (double)current->Temperature;
        current = current->next;
    }
    printf("\n%0.2lf",avgTemp);
    return ((double)avgTemp/(double)ptr->size);
}
double findMaxTemperature(city_info* ptr){
    Node* current = ptr->node;
    double max = current->Temperature;
    while(current != NULL){
        if(max < current->Temperature){
            max = (double)current->Temperature;
        }
        current = current->next;
    }
    return max;
}

double findMinTemperature(city_info* ptr){
    Node* current = ptr->node;
    double min = current->Temperature;
    while(current != NULL){
        if(min > current->Temperature){
            min = (double)current->Temperature;
        }
        current = current->next;
    }
    return min;
}
int findAvgHumidity(city_info* ptr){
    Node* current = ptr->node;
    int avgHumi = 0;
    while(current != NULL){
        avgHumi += current->Humidity;
        current = current->next;
    }
    return (avgHumi/ptr->size);
}

int findMaxHumidity(city_info* ptr){
    Node* current = ptr->node;
    int max = current->Humidity;
    while(current != NULL){
        if(max < current->Humidity){
            max = current->Humidity;
        }
        current = current->next;
    }
    return max;
}
int findMinHumidity(city_info* ptr){
    Node* current = ptr->node;
    int min = current->Humidity;
    while(current != NULL){
        if(min > current->Humidity){
            min = current->Humidity;
        }
        current = current->next;
    }
    return min;
}
// void appendNewRecord(city_info* ptr,int* n){
//     ptr = (city_info*)realloc(ptr,++(*n)* sizeof(city_info));
//     read_info(&ptr[(*n)-1]);
//     n++;
// }
void findLongestCityName(city_info* ptr){
    Node* current = ptr->node;
    int len = 0;
    char city[15];

    while (current != NULL) {
        int p = strlen(current->city);
        if (p > len) {
            len = p;
            strcpy(city, current->city);
        }
    
        current = current->next;
    }
    printf("\nThe Longest City Name is : %s\n\n", city);
}
int countOfTempinrange(city_info* ptr,double range){
    // double range = 0;
    // printf("\nEnter the within the Temperature range to be counted : ");
    // scanf("%lf",&range);

    Node* current = ptr->node;
    int count = 0;
    while(current != NULL){
        double temp = current->Temperature;
        if(temp < range){
            ++count;
        }
        current = current->next;
    }
    return count;
}
void sortRecord(city_info* ptr){
    Node* current = ptr->node,*nextNode = current->next;
    while (current != NULL) {
       Node* nextNode = current->next;
        while (nextNode != NULL) {
            if (strcmp(current->city, nextNode->city) > 0) {
                Node*temp;
                temp = nextNode;
                temp->next = nextNode->next;
                nextNode = current;
                nextNode->next = current->next;
                break;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
}

void deleteCity(city_info* ptr){
    char city[15];
    printf("\n Enter the city Name to be deleted : ");
    scanf("%s",city);
    lowerCase(city);
    Node* current = ptr->node;
    Node* prev = current, *next = current->next;
    char st[20];
        strcpy(st,current->city);
        lowerCase(st);
        if(strcmp(city,st) == 0){
            ptr->node = current->next;
            free(current);
            --ptr->size;
            return;
        }
    while(current != NULL){
        char s[20];
        strcpy(st,current->city);
        lowerCase(st);
        if(strcmp(city,st) == 0){
            next = current->next;
            prev->next = next;
            free(current);
            printf("\n Deleted the city record named : %s",city);
            --ptr->size;
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("\nCity named \"%s\" not found",city);
}