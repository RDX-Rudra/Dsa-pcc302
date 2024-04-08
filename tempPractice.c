#include<stdio.h>
int fib(int n){
    int fib0 = 1, fib1 = 1, ans=0;
    for(int i=0; i<n-2; i++){
        ans = (fib0 + fib1);
        fib0 = fib1;
        fib1 = ans;
    } 
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    int ans = fib(n);
    printf("%d\n", ans);
    
}