#include <stdio.h>

int maxStep(int* arr,int len){
    int count = 0;
    for(int i=0; i<len; i++){
        if(arr[i]+i+1 < len){
            ++count;
        }
        else{
            break;
        }
    }
    return count;
}

int main(){
    int arr[] = {1,3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int len = sizeof(arr)/sizeof(int);
    printf("\nNumber of Maxmimum Steps : %d\n",maxStep(arr,len));
    return 0;
}