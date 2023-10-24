#include <stdio.h>
#include <stdlib.h>

void  unions_of_two_array(int* , int* b,int , int);

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {1, 2, 5};
    int n = sizeof(a)/sizeof(a[0]);
    int m = sizeof(b)/sizeof(b[0]);
    //printf("\n%d\n",sizeof(a)/sizeof(int));
    unions_of_two_array(a,b,n,m);
    printf("\n");
    return 0;
}

void unions_of_two_array(int* a,int* b,int n, int m){
    if(n > 105 || m > 105 || n < 1 || m<1){
        printf("\nThe size of array is exceeding the limit\n");
        exit(0);
    }
    int buff[105] = {0};
    int count = 0;
    // printf("\n%d %d\n",sizeof(a),sizeof(int));
    for(int i=0; i<n; i++){
        if(a[i] < 0 || a[i] > 105){
            printf("\nThe element Value of array index %d is exceeding the limit constraint\n",i);
            exit(0);
        }
        buff[a[i]] += 1; 
    }

    for(int i=0; i<m; i++){
        if(b[i] < 0 || b[i] > 105){
            printf("\nThe element Value of array index %d is exceeding the limit constraint\n",i);
            exit(0);
        }
        buff[b[i]] += 1; 
    }

    for(int i=0; i<105; i++){
        if(buff[i] > 0){
            ++count;
        } 
    }
    
    printf("\nUnions count of two array is %d",count);
}