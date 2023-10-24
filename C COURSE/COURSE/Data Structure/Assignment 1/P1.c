#include <stdio.h>
#include <stdlib.h>


int distinct_integrs(int*,int);

int main(){
    int arr[] = {1,2,0,4,5,6,7,8,10};
    int n = (sizeof(arr) / sizeof(int));
    distinct_integrs(arr,n+1);
    return 0;
}
int distinct_integrs(int* arr,int n){
  if(n >= 100){
        printf("\nThe size of array is exceeding the limit\n");
        return 0;
    }
    int sum = n*(n+1)/2;
    int count = 0;
    for(int i=0; i<n-1; i++){
        if(arr[i] > 0 && arr[i] < 101){
        count += arr[i];
        }
        else{
        printf("\nThe element Value of array index %d is exceeding the limit constraint\n",i);
        return 0;
    }
       
    }
    //printf("\n-< count %d , sum-< %d, n ->%d\n",count,sum,n);
    printf("\n%d\n",sum-count);

    return (sum-count);

}