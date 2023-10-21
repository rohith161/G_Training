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
    node* head;
}LinkedList;


LinkedList* createLinkedList();
void insert(LinkedList* list,int data);
void display(LinkedList* list);
int getsize(LinkedList* list);
void deleteLast(LinkedList* list);
void freeNodes(LinkedList* list);
int checkLinkedList(LinkedList* list);


int main(){
    LinkedList* list = createLinkedList();
    int n = 0;
    printf("\n\n-----Checking whether the given linked list is Circular LinkedList-----\n\n");
    printf("\nEnter the size of circular LinkedList : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        int data = 0;
        printf("\nEnter data %d : ",i+1);
        scanf("%d",&data);
        insert(list,data);
    }
    //endpoint->next = NULL;
    display(list);
    printf("\nsize - > %d\n",getsize(list));
    printf("\n : %d\n",checkLinkedList(list));

    // making the last node equal to NULL
    printf("\nNow we make the last node equal to NULL\n");

    list->endpoint->next = NULL;

    //deleteLast(list);
    display(list);
    //printf("\nsize - > %d\n",getsize(list));
    //endpoint->next = NULL;
    printf("\n : %d\n",checkLinkedList(list));

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
void display(LinkedList* list){
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

int getsize(LinkedList* list){
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return 0;
    }
    return list->size;
}

void deleteLast(LinkedList* list){
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

void freeNodes(LinkedList* list){
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

int checkLinkedList(LinkedList* list){
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return 0;
    }
    node* current = list->Node;
    current = current->next;
    while (current != NULL)
    {
        if(current == list->head){
            printf("\nThe given linked list is Circular LinkedList\n");
            return 1;
        }
        else if(current->next == NULL){
            printf("\nThe given linked list is not a Circular LinkedList\n");
            return 0;
        }
        current = current->next;
    }
    
}