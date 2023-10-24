#include <stdio.h>

int main(){
    int n = 390;
    int d = 0;
    while( n != 0){
        int rem = n%10;
        printf("%d ",rem);
        n /= 10;
        
    }
}