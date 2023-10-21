#include <stdio.h>


// void array(int a[]){
//     printf("\n%d",arr[i]);
// }
int main(){
    // char* p ;
    // printf("\n%ld,\n%zu\n",sizeof("HELLO"),sizeof(p));

    // double x = 0.7;
    // if(x == 0.7){
    //     printf("\nYES");
    // }
    // else{
    //     printf("\nNO\n");
    // }

    // char a[] = "ltts";
    // char* pt = a;
    // printf("\n%c\n",pt);
    int arr[3] = {1,2,3};
    //double *pt = arr;
    //char* p = arr;
    char* p = (char*)arr;
    printf("\n%d\n",*p+2);
    printf("\n%p\n",arr);
}