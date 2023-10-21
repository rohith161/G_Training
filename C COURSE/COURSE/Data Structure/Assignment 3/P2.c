#include <stdio.h>
#include <stdlib.h>

int minPossibleDiff(int* arr,int n,int k);
void scanArray(int* arr,int n);
void printArray(int* arr,int n);

int main(){
    int n = 0, k = 0;
    printf("\nEnter the size of the N Towers : ");
    scanf("%d",&n);
    printf("\nEnter the value of K : ");
    scanf("%d",&k);
    
    if(k <= 0 || k > 10000){
        printf("\nThe k value exceeds the given constraints\n");
        return 0;
    }

    int arr[n];
    scanArray(arr,n);
    printArray(arr,n);

    int minPos = minPossibleDiff(arr,n,k);
    printArray(arr,n);
    //printf("\nThe min possible difference between the height of the shortest and tallest towers after modification of each tower \n")
    printf("\n%d\n",minPos);
    return 0;
}

int compare(const void* a,const void* b){
    return (*(int*)a) - (*(int*)b);
}
int minPossibleDiff(int* arr,int n,int k){
    int kPos = k*k;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > kPos)
        {
            arr[i] = arr[i] - k;
        }
        else
        {
            arr[i] += k;
        }
    }
    qsort(arr,n,sizeof(int),compare);
    return abs(arr[0] - arr[n-1]);
}

void scanArray(int* arr,int n){
    int data = 0;
    for(int i =0; i<n; i++)
    {
            printf("Enter the %d Tower Height : ",i+1);
            scanf("%d",&data);
            if(data <=0 || data > 100000)
            {
                printf("\nThe array index %d value exceeds the given constraints\n",i);
                exit(0);
            }
            arr[i] = data;
        }
}

void printArray(int* arr,int n){
    printf("\n");
    for(int i =0; i<n; i++)
    {
        printf("%d ",arr[i]); 
    }
    printf("\n");
}