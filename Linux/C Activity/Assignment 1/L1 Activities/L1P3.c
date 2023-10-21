#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return (a > b)? a: b;
}

int longestPalindromic(char* str,int sindx, int eindx){
    if(sindx == eindx){
        return 1;
    }
    
}

int main(){
    char str[] = "BBABCBCAB";
    longestPalindromic(str,0,strlen(str)-1);
    return 0;
}