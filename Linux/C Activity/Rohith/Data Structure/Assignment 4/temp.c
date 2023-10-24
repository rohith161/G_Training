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
    node* head;
}Queue;



Queue* createLinkedList();
void insert(Queue* q,int data);
void display(Queue* q);
int getsize(Queue* q);
void deleteLast(Queue* q);
void freeNodes(Queue* q);
int checkLinkedList(Queue* q);

typedef struct arrayQueue{
    int data[100];
    int front;
    int rear;
}arrayQueue;

void pushArrStack(arrayQueue* stack, int data);
int popArrStack(arrayQueue* stack);
arrayQueue* createarrayQueue();

int main(){

    arrayQueue* q = createarrayQueue();
    //Queue* q = createLinkedList();
    // while (ch =='y' || ch == 'Y')
    // {   printf("\n 1 - Insertion in a Queue using Array implementation");
    //   printf("\n 4 - Deletion in a Circular Queue");
    //     printf("\nChoose any one option from above : ");
    //        printf("\n 2 - Deletion in a Queue using Array implementation");
    //     printf("\n 3 - Insertion in a Circular Queue");
       
    //     int n = 0;
    //     scanf("%d",&n);
    //     switch(n){
    //         case 1 :

    //             break;		
    //         case 2 : 
            
    //             break;		
    //         case 3 :  
            
    //             break; 		
    //         case 4 : 
    //             break; 
    //     }
    // }
    
    
    return 0;
}

arrayQueue* createarrayQueue(){
    arrayQueue* newqueue = (arrayQueue*)calloc(1,sizeof(arrayQueue));
    if(newqueue == NULL){
        printf("\nMemroy allocation failed\n");
        exit(0);
    }
    newqueue->front = -1;
    newqueue->rear = -1;
    return newqueue;
}

void pushArrStack(arrayQueue* q, int data){
    printf("\n%d  -  %d",q->front,q->rear);
}
int popArrStack(arrayQueue* stack){

}

Queue* createLinkedList(){
    Queue* list = (Queue*)malloc(sizeof(Queue));
    if(list == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    list->Node = NULL;
    list->size = 0;

    list->endpoint = list->Node;
        //head = list->Node;
        //tail = list->Node->next;
    
    return list;
}


void insert(Queue* list,int data){

    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    
    if(list->Node == NULL){
        list->head = newnode;
        list->Node = newnode;
        list->endpoint = newnode;
        newnode->next = list->head;
        
    }
    else{
    list->endpoint->next = newnode;
    list->endpoint = newnode;
    newnode->next = list->head;
    }
   
    list->size++;

}

void display(Queue* list){
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return;
    }
    node* current = list->Node;
    //node* headPtr = &list->Node;
    int flag = 0;
    printf("\n%d ",current->data);
    current = current->next;
    while (current != NULL)
    {   if(current == list->head){
            break;
        }
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

int getsize(Queue* list){
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return 0;
    }
    return list->size;
}

void deleteLast(Queue* list){
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return ;
    }
    int n = getsize(list);
    node* current = list->Node;
    for(int i=0; i<=n; i++){
        if(i+1 == n-1){
            break;
        }
        current = current->next;
    }
    node* temp = current->next;
    current->next = list->head;
    free(temp);
    list->size--;
}

void freeNodes(Queue* list){
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return;
    }
    node* current = list->Node;
    current = current->next;
    while(current != NULL){
        if(current == list->head){
            free(current);
            break;
        }
        node* temp = current;
        current = current->next;
        free(temp);
    }
 }
