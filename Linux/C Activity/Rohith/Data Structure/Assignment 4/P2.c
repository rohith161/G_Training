#include <stdio.h>
#include <stdlib.h>


typedef struct Queue{
    int data[100];
    int front;
    int rear;
}Queue;

Queue* createQueue();
void enqueue(Queue* stack, int data);
int dequeueArr(Queue* stack);
int dequeueCir(Queue* q);

int main(){

    Queue* qArr = createQueue();
    Queue* cArr = createQueue();
    
    printf("\n\n---Insertion & Deletion in Array Queue and Circular Queue---\n\n");
    char ch = 'y';
    while (ch == 'y' || ch == 'y')
    {   
        printf("\n 1 - Insertion in a Queue using Array implementation");
        printf("\n 2 - Deletion in a Queue using Array");
        printf("\n 3 - Insertion in a Circular Queue");
        printf("\n 4 - Deletion in a Circular Queue");
        printf("\nChoose any one option from above : ");
       
        int n = 0;
        scanf("%d",&n);
        switch(n){
            case 1 :
                int data = 0;
                printf("\nEnter the Element to be inserted in Array Queue : ");
                scanf("%d",&data);
                enqueue(qArr,data);
                break;		
            case 2 : 
                int res = dequeueArr(qArr);
                (res != -1) ? printf("\nArray Queue - deQueue -> %d",res) : 0;
                break;		
            case 3 :  
                int data1 = 0;
                printf("\nEnter the Element to be inserted in Circular Queue: ");
                scanf("%d",&data1);
                enqueue(cArr,data1);
                break; 		
            case 4 : 
                int res1 = dequeueCir(cArr);
                (res1 != -1) ? printf("\nCircular Queue - deQueue -> %d",res1) : 0;
                break;
            default :
                printf("\n\"Invalid Option\"\n");
                break; 
        }
        printf("\n\nTo continue press \'Y\' \\ any key to exit -> ");
        scanf(" %c",&ch);
    }
    
    return 0;
}

Queue* createQueue(){
    Queue* newqueue = (Queue*)calloc(1,sizeof(Queue));
    if(newqueue == NULL){
        printf("\nMemroy allocation failed\n");
        exit(0);
    }
    newqueue->front = -1;
    newqueue->rear = -1;
    return newqueue;
}

void enqueue(Queue* q, int data){
    if((q->front == -1 && q->rear == -1) || (q->front == 0 && q->rear == 0)){
        if(q->front == 0 && q->rear == 0){
            q->rear++;
            q->data[q->rear] = data;
            return;
        }
        q->front++;
        q->rear++;
        q->data[q->rear] = data;
        return;
    }
    if( (q->front != q->rear) && (q->front > q->rear || q->front < q->rear) ){

        q->rear++;
        q->data[q->rear] = data;
        return;
    }
    else{
        printf("\n\"Queue is full\"\n");
        return;
    }
}
int dequeueArr(Queue* q){
    if(q->front > q->rear){
        printf("\n\"Queue is Empty\"\n");
        return -1;
    }
    else{
        return q->data[q->front++];
    }
}

int dequeueCir(Queue* q){
    if(q->front == q->rear){
        //printf("\n-- > %d",q->front);
        int temp = q->data[q->front];
        q->front = 0;
        return temp;
    }
    else{
        //printf("\n%d -> %d",q->front++,q->front);
        return q->data[q->front++];
        
    }
}

