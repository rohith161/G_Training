#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* ptr;
}node;

typedef struct Queue{
    node* front;
    int size;
    node* rear;
}Queue;

int frontelement(Queue* q);
void enqueue(Queue* q,int data);
int dequeue(Queue* q);
void empty(Queue* q);
void display(Queue* q);
Queue* create();
int queuesize(Queue* q);
		


void main()		
{	Queue* q = create();
    char ch = 'y';
    while(ch == 'y' || ch == 'Y'){
        printf("\n 1 - Enque");		
        printf("\n 2 - Deque");		
        printf("\n 3 - Front element");		
        printf("\n 4 - Empty");		
        printf("\n 5 - Exit");		
        printf("\n 6 - Display");		
        printf("\n 7 - Queue size");
        printf("\nChoose any one option from above : ");
        int n = 0;
        scanf("%d",&n);		
        
        switch (n)
        {
        case 1 :
            int data  = 0;
            printf("\nEnter the element to be pushed : ");
            scanf("%d",&data);
            enqueue(q,data);
            break;
        case 2 :
            printf("\nDequeued Element -> %d\n",dequeue(q));
            break;
        case 3 :
            printf("\nFront Element - > %d\n",frontelement(q));
            break;
        case 4 :
            empty(q);
            break;
        case 5 :
            printf("\nExiting..\n");
            exit(0);
            break;
        case 6 :
            printf("\nElements in Queue are : ");
            display(q);
            break;
        case 7 :
            printf("\nQueue Size - > %d\n",queuesize(q));
            break;
        default:
            printf("\n\"Invalid Option\"\n");
            break;
        }
        printf("Do you continue Press \'Y\' or \'N\' to exit : ");
        getchar();
        scanf("%c",&ch);
    }
    printf("\nExiting..\n");
}

Queue* create(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if(q == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    q->front = NULL;
    q->size = 0;
    
    q->rear = q->front;

    return q;
}

void enqueue(Queue* q,int data){

    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    newnode->data = data;
    newnode->ptr = NULL;
    
    if(q->front == NULL){
        q->front = newnode;
        q->rear = newnode;
    }
    else{
    q->rear->ptr = newnode;
    q->rear = newnode;
    }
   
    q->size++;

}

int dequeue(Queue* q){
    if(q->size <= 0){
        printf("\n\"Empty Queue\"\n");
        return -1;
    }
    node* current  = q->front;
    int data = current->data;
    q->front = current->ptr;
    free(current);
    q->size--;
    return data;
}

int frontelement(Queue* q){
    if(q->size >=1)
    return q->front->data;
    else
    return -1;
}

void empty(Queue* q){
    if(q->size >= 1){
        printf("\nQueue is not Empty\n");
    }
    else{
        printf("\nEmpty Queue\n");
    }
}

void display(Queue* q){
    if(q->size <= 0){
        printf("\n\"Empty Queue\"\n");
        return;
    }
    node* current = q->front;
    while (current != NULL)
    {
        printf("%d ",current->data);
        current = current->ptr;
    }
    printf("\n");
}

int queuesize(Queue* q){
    if(q->size >= 1){
        return q->size;
    }
    else{
        return -1;
    }
}