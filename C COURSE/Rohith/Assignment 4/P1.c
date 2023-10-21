#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct Queue{
    node* Node;
    int size;
    node* endpoint;
}Queue;



Queue* createQueue();
void enQueue(Queue* list,int data);
int deQueue(Queue* list);
void display(Queue* list);
int getsize(Queue* list);
void freeNodes(Queue* list);


int main(){
    Queue* q1 = createQueue();
    Queue* q2 = createQueue();
    createStack(q1,q2);

    freeNodes(list);
    free(list);
    return 0;
}

Queue* createQueue(){
    Queue* list = (Queue*)malloc(sizeof(Queue));
    if(list == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    list->Node = NULL;
    list->size = 0;
    
    list->endpoint = list->Node;

    return list;
}


void enQueue(Queue* list,int data){

    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    
    if(list->Node == NULL){
        list->Node = newnode;
        list->endpoint = newnode;
    }
    else{
    list->endpoint->next = newnode;
    list->endpoint = newnode;
    }
   
    list->size++;

}
int deQueue(Queue* list){
    if(list->size <= 0){
        printf("\n\"Empty Queue\"\n");
        return -1;
    }
    node* current  = list->Node;
    int data = current->data;
    list->Node = current->next;
    free(current);
    list->size--;
    return data;
}

void display(Queue* list){
    if(list->size <= 0){
        printf("\n\"Empty Queue\"\n");
        return;
    }
    node* current = list->Node;
    printf("\n");
    while (current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

int getsize(Queue* list){
    if(list->size == 0){
        printf("\n\"Empty Queue\"\n");
        return -1;
    }
    return list->size;
}

 void freeNodes(Queue* list){
    node* current = list->Node;
    while(current != NULL){
        node* temp = current;
        current = current->next;
        free(temp);
    }
 }

