#include <stdio.h>
#include <stdlib.h>

int  no_of_inversion(int* arr,int n);

int main(){
    int arr[] = {2, 4, 1, 3, 5 };
    int n = (sizeof(arr) / sizeof(int));
    printf("\nInversion count of arr is %d\n",no_of_inversion(arr,n));
    
    return 0;
}

int  no_of_inversion(int* arr,int n){
    if(n > (5*051)){
        printf("\nThe size of array is exceeding the limit\n");
        exit(0);
    }
    
    int count  = 0 ;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] < 1 || arr[i] > 1018){
            printf("\nThe element Value of array index %d is exceeding the limit constraint\n",i);
            exit(0);
        }
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }
    return count;
}