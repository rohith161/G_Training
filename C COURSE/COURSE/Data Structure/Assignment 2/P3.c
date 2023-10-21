#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct LinkedList{
    node* Node;
    int size;
    node* endpoint;
}LinkedList;



LinkedList* createLinkedList();
void insert(LinkedList* list,int data);
void reverse(LinkedList* list);
void display(LinkedList* list);
int getsize(LinkedList* list);
void deleteLastNode(LinkedList* list);
void freeNodes(LinkedList* list);


int main(){
    LinkedList* list = createLinkedList();
    int n = 0;
    printf("\n\n-----Reversing the given linked list-----\n\n");
    printf("\nEnter the size of Single LinkedList : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int data = 0;
        printf("\nEnter data %d : ",i+1);
        scanf("%d",&data);
        insert(list,data);
    }
    
    printf("\n--Before reverse---\n");
    display(list);
    //printf("\nsize - > %d\n",getsize(list));
    //deleteLastNode(list);
    //insert(list,6);
    printf("\n--After reverse---\n");
    reverse(list);
    display(list);
    //("\nsize - > %d\n",getsize(list));
    freeNodes(list);
    free(list);
    return 0;
}

LinkedList* createLinkedList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    if(list == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    list->Node = NULL;
    list->size = 0;
    
    list->endpoint = list->Node;
    
    return list;
}

/*node* createNode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
    
}*/
void insert(LinkedList* list,int data){

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

void reverse(LinkedList* list){
    node* current = list->Node;
    node* prev = NULL;
    while(current != NULL){
        node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->Node = prev;
}
void display(LinkedList* list){
    node* current = list->Node;
    printf("\n");
    while (current != NULL)
    {
        printf("%d ",current->data);
        current = current->next;
    }
    printf("\n");
}

int getsize(LinkedList* list){
    return list->size;
}
void deleteLastNode(LinkedList* list){
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
    current->next = NULL;
    free(temp);
    list->size--;
}
 void freeNodes(LinkedList* list){
    node* current = list->Node;
    while(current != NULL){
        node* temp = current;
        current = current->next;
        free(temp);
    }
 }

