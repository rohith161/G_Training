#include <stdio.h>

typedef struct Node{
    char date[10];			
    char Name[15];					
    int Age;					
    int Salary;					
    int EmployeeID;
    struct Node* next;
}Node;

typedef struct record
{
    Node* node;
}record;

Node* endPoint = NULL;

record* initrecord(){
    record* ptr = (record*)calloc(1,sizeof(record));
     if(ptr == NULL){
        printf("\nMemory allocation failed\n");
        return ;
    }
    ptr->node = NULL;
    if(endPoint == NULL){
        endPoint = ptr->node;
    }
    return ptr;
}

Node* createNode(){
    Node* newnode = (Node*)calloc(1,sizeof(Node));
    if(newnode == NULL){
        printf("\nMemory allocation failed\n");
        return ;
    }
    newnode->next = NULL;
    endPoint = newnode;
    return newnode;

}
void append(){
    
    printf("\nEnter the Date is this format \"dd/mm/yyyy\" : ");
    scanf("%s",endPoint->date);
    printf("\nEnter the Employee Name : ");
    scanf("%s",endPoint->Name);
    printf("\nEnter the Employee Age : ");
    scanf("%d",ptr->Age);
    printf("\nEnter the Employee Salary : ");
    scanf("%d",ptr->Salary);
    printf("\nEnter the Employee ID : ");
    scanf("%d",ptr->EmployeeID);
    endPoint
}
void appendRecord(record* ptr){
    if(ptr->node == NULL){
    ptr->node = createNode();
    }
    append();

}