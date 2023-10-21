#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

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
void push(Stack* stack,char data);
char pop(Stack* stack);
int getsize(Stack* stack);
int isEmpty(Stack* stack);
int isfull(Stack* stack);
char peek(Stack* stack);
bool checkExpression(char* str);

int main(){

    char str[200];
    printf("\nEnter the Expression String : ");
    scanf("%s",str);
    printf("\n%s\n",str);
    int len = strlen(str);
    if(len <=0 || len > 32000){
        printf("\nThe string length exceeds the given constraints\n");
        return 0;
    }
    bool flag = checkExpression(str);
    if(flag){
        printf("\nbalanced\n");
    }
    else{
        printf("\nnot balanced\n");
    }
    return 0;
}

int countBrackets(char* str){
    int count = 0;
    for(int i=0; str[i] != '\0'; i++){
        char ch = str[i];
        if ((ch == '{' || ch == '}') || (ch == '(' || ch == ')') || (ch == '[' || ch == ']'))
        {
            count++;
        }
    }
    return count;
}
bool checkExpression(char* str){
    int n = countBrackets(str);
    if((n%2 != 0) || (strlen(str) == 0)){
        return false;
    }
    int flag = 1;
    Stack* stack = createStack(n);
    char ch,top;
    for(int i=0; str[i] != '\0'; i++){
        ch = str[i];
        if(!isEmpty(stack))
        {
        top = peek(stack);
        }
        if ((ch == '{' || ch == '}') || (ch == '(' || ch == ')') || (ch == '[' || ch == ']'))
        {
            if (isEmpty && (ch == '{' || ch == '(' || ch == '['))
            {
                push(stack,ch);
                flag = 0;
                continue;
            }
            else if (ch == '{' || ch == '(' || ch == '[')
            {
                push(stack,ch);
                continue;
            }
            else if (isEmpty && ch == '}' || ch == ')' || ch == ']')
            {
                if((top == '{' && ch == '}') || (top == '(' && ch == ')') || (top == '[' && ch == ']'))
                {
                    pop(stack);
                }
                else{
                    return false;
                }
            }
        }
        else{
            continue;
        }
    }
    if(stack->size == 0){
        return true;
    }
    else{
        return false;
    }

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
        //printf("\n\"Stack is not Empty\"\n");
        return 0;
    }
    else
    {
        //printf("\n\"Stack is Empty\"\n");
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