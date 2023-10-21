
#include <stdio.h>

void fibo(int n, int a, int b){
    if(n <= 0){
        return;
    }
    printf("%d ",a);
    int sum = a+b;
    a = b;
    fibo(--n,a,sum);
}
int main()
{
    int a = 0, b = 1, n= 10;
    fibo(n,a,b);

    return 0;
}
