#include <stdio.h>

int largestPrimeFactor(int n){
    if( n < 0 && n > 1015){
        return 0;
    }
    int largestPrime = -1, i = 2;
    while((i*i) <= n){
        while (n%i == 0)
        {
            largestPrime = i;
            n = n/i;
        }
        i++;
    }
    if(n > 1){
        largestPrime = n;
    }
    return largestPrime;
}

int main(){
    int n = 6;
    printf("\n%d ",largestPrimeFactor(n));
    return 0;
}