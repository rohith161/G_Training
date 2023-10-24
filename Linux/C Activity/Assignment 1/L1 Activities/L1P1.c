#include <stdio.h>

void fibonacci(int a, int b, int n){
    if(n <= 0){
        return ;
    }
    printf("%d ",a);
    fibonacci(b,a+b,--n);
}

int main(){
    int a = 0,b=1,n=10;
    fibonacci(a,b,n);
    return 0;
}