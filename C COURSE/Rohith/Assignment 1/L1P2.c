
#include <stdio.h>

int largestPrimeFactor(int n){
        int i=2, large_prime = -1;
        while(i*i <= n){
            while(n%i == 0){
                large_prime = i;
                n = n/i;
            }
            i++;
        }
        if(n>1){
            large_prime = n;
        }
    return large_prime;

}
int main()
{
    int n = 12345;
    printf("%d\n",largestPrimeFactor(n));
    return 0;
}
