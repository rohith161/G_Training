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
void push(Queue* q1,Queue* q2,int data);
int pop(Queue* q1,Queue* q2);

int main(){
    Queue* q1 = createQueue();
    Queue* q2 = createQueue();
    int data = 0;
    push(q1,q2,2);
    printf("\nsize %d - %d\n",q1->size,q2->size);
    push(q1,q2,3);
    printf("\nsize %d - %d\n",q1->size,q2->size);
    printf("\n%d\n",pop(q1,q2));
    printf("\n%d - %d\n",q1->size,q2->size);
    push(q1,q2,4);
    printf("\n size %d - %d\n",q1->size,q2->size);
    printf("\n%d\n",pop(q1,q2));
    printf("\nsize %d - %d\n",q1->size,q2->size);
    printf("\n%d\n",pop(q1,q2));
    printf("\nsize %d - %d\n",q1->size,q2->size);
    printf("\n%d\n",pop(q1,q2));
    printf("\nsize %d - %d\n",q1->size,q2->size);
    printf("\n%d\n",pop(q1,q2));
    printf("\nsize %d - %d\n",q1->size,q2->size);
    freeNodes(q1);
    freeNodes(q2);
    free(q1);
    free(q2);
    return 0;
}

void push(Queue* q1,Queue* q2,int data){
    if(q1->size == 0 && q2->size == 0){
        enQueue(q1,data);
        return;
    }
    if(q1->size != 0)
    {
        enQueue(q1,data);
        return;
    }
    else{
        enQueue(q2,data);
        return;
    }
}
int pop(Queue* q1,Queue* q2){
    if(q1->size == 0 && q2->size == 0){
        printf("\n\"Empty Stack\"\n");
        return -1;
    }
    // when both the Queue size = 1 
    if(q1->size == 1)
    {
        return deQueue(q1);
    }
    else if(q2->size == 1){
        return deQueue(q2);
    }

    if(q2->size == 0 && q1->size != 1){
        while(q1->size != 1){
            enQueue(q2,deQueue(q1));
        }
        return deQueue(q1);
    }
    else if (q1->size == 0 && q2->size != 1)
    {
        while (q2->size != 1)
        {
            enQueue(q1,deQueue(q2));
        }
        return deQueue(q2);
    }
    
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

