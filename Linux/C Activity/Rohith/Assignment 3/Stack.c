#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node{
    char ch;
    struct node* next;
}node;

typedef struct Stack{
    node* Top;
    int size;
    int capaciy;
}Stack;

Stack* createStack(int size);
bool checkExpression(char* str);
void push(Stack* stack,char data);
char pop(Stack* stack);
int getsize(Stack* stack);
int isEmpty(Stack* stack);
int isfull(Stack* stack);
char peek(Stack* stack);

int main(){
    int n = 0;
    printf("\nEnter the size of the Expression String : ");
    scanf("%d",&n);
    char str[n];
    printf("\nEnter the Expression String : ");
    scanf("%s",str);
    printf("\n%s\n",str);
    Stack* stack = createStack(n);
    //printf("\n%s\n",str);
    for(int i=0; i<n; i++){
        push(stack,str[i]);
    }
    push(stack,'a');
    printf("%c ", peek(stack));
    isEmpty(stack);
    isfull(stack);
    //printf("\n%s\n",str);
    for(int i=0; i<n; i++){
        printf("%c ", pop(stack));
    }
    pop(stack);
    printf("%c ", peek(stack));
    isEmpty(stack);
    isfull(stack);
    printf("\n");
    //bool flag = checkExpression(str);
    return 0;
}

Stack* createStack(int size){
    Stack* newstack = (Stack*)calloc(1,sizeof(Stack));
    if(newstack == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    
    newstack->Top = NULL;
    newstack->size = 0;
    newstack->capaciy = size;
    
    return newstack;
}

void push(Stack* stack,char data){
    if(stack->size >= stack->capaciy){
        printf("\n\"Stack is Full\"\n");
        return;;
    }
    node* newnode = (node*)calloc(1,sizeof(node));
    if(newnode == NULL){
        printf("\nMemory allocation failed\n");
        exit(0);
    }
    newnode->ch = data;
    if(stack->Top == NULL)
    {
        newnode->next = NULL;
        stack->Top = newnode;
    }
    else
    {
        newnode->next = stack->Top;
        stack->Top = newnode;
    }
    stack->size++;
}

char pop(Stack* stack){
    if(stack->size <= 0){
        printf("\n\n\"Stack is Empty\"\n");
        return '\0';
    }
    node* current = stack->Top;
    stack->Top = current->next;
    char ch = current->ch;
    free(current);
    stack->size--;
    return ch;
}

int getsize(Stack* stack){
    return stack->size;
}

int isEmpty(Stack* stack){
    if(stack->size >0){
        printf("\n\"Stack is not Empty\"\n");
        return 0;
    }
    else
    {
        printf("\n\"Stack is Empty\"\n");
        return 1;
    }
}

int isfull(Stack* stack){
    if(stack->capaciy == stack->size){
        printf("\n\"Stack is Full\"\n");
        return 1;
    }
    else{
        printf("\n\"Stack is not Full\"\n");
        return 0;
    }
}

char peek(Stack* stack){
    if(stack->size <= 0){
        printf("\n\"Stack is Empty\"\n");
        return '\0';
    }
    return stack->Top->ch;
}