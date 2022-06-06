#include <stdio.h>
#include <stdlib.h>

binomialCoefficient(int n,int k){
    if(k>n)
         return 0;
    if(k==n || k==0)
        return 1;
    
    return binocoeff(n-1,k-1) + binocoeff(n-1,k);
}

int main()
{
    int n, k;
    printf("Enter n : ");
    scanf("%d", &n);
    printf("Enter k : ");
    scanf("%d", &k);
    printf("the value of %d C %d is %d", n, k, binomialCoefficient(n, k));
    return 0;
}
