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
int contains(LinkedList* list,int data);

void sumOfTwoLinkedList(LinkedList* list1,LinkedList* list2,LinkedList* sum);

int main(){
    LinkedList* list1 = createLinkedList();
    LinkedList* list2 = createLinkedList();
    int n = 0, m = 0;
    printf("\nEnter the size of First Single LinkedList : ");
    scanf("%d",&n);
    printf("\nEnter the data for the First LinkedList : ");
    for(int i=0; i<n; i++){
        int data = 0;
        printf("\nEnter data %d : ",i+1);
        scanf("%d",&data);
        insert(list1,data);
    }
    display(list1);

    printf("\nEnter the size of Second Single LinkedList : ");
    scanf("%d",&m);
    printf("\nEnter the data for the second LinkedList : ");
    for(int i=0; i<m; i++){
        int data = 0;
        printf("\nEnter data %d : ",i+1);
        scanf("%d",&data);
        insert(list2,data);
    }
    display(list2);

    LinkedList* sum = createLinkedList();
    sumOfTwoLinkedList(list1,list2,sum);
    display(sum);
    freeNodes(list1);
    free(list1);
    freeNodes(list2);
    free(list2);
    return 0;
}

void sumOfTwoLinkedList(LinkedList* list1,LinkedList* list2,LinkedList* sum){
    node* curr = list1->Node;
    int digit1 = 0;
    while(curr != NULL){
        digit1 = (digit1 * 10) + curr->data;
        curr = curr->next;
    }

    curr = list2->Node;
    int digit2 = 0;
    while(curr != NULL){
        digit2 = (digit2 * 10) + curr->data;
        curr = curr->next;
    }
    int sumOfList = digit1 + digit2;
    printf("\n%d\n",sumOfList);
    //LinkedList* sum = createLinkedList();
    while( sumOfList != 0){
        int rem = sumOfList % 10;
        insert(sum,rem);
        sumOfList /= 10; 
    }
    reverse(sum);
    //return sum;
    
}

int contains(LinkedList* list,int data){
  
    node* curr = list->Node;
    while(curr != NULL){
        if(curr->data == data){
            return 1;
        }
        curr = curr->next;
    }
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
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return ;
    }
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
    if(list->Node == NULL){
        printf("\nEmpty List\n");
        return ;
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

