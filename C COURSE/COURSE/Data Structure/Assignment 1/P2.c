#include <stdio.h>
#include <stdlib.h>

void sortArray(int* arr,int n);

int main(){
    int arr[] = {0, 2, 1, 2, 0,2,3,0,1,0,1,0,2,2};
    int n = sizeof(arr)/sizeof(int);
    sortArray(arr,n);
    
    printf("\n");
    return 0;
}

void sortArray(int* arr,int n){
    if(n >= 100000){
        printf("\nThe size of array is exceeding the limit\n");
        return ;
    }
    int i= 0, sindx = 0, eindx = n-1;

    for(int i=0; i<=eindx; i=i ){
        if(arr[i] < 0 || arr[i] > 2){
            printf("\nThe element Value of array index %d is exceeding the limit constraint\n",i);
            return;
        }
        if(arr[i] == 0){
            int temp = arr[i];
            arr[i] = arr[sindx];
            arr[sindx] = temp;
            i++,sindx++;
        }
        else if(arr[i] == 1){
            i++;
          //  continue;
        }
        else{
            int temp = arr[i];
            arr[i] = arr[eindx];
            arr[eindx] = temp;
            eindx--;

        }
    }

    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
}