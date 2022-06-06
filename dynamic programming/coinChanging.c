//gives total number of possible ways to make change for a given amount of money
#include <stdio.h>
int count(int a[], int n, int max)
{
    if (max == 0)
        return 1;
    if (max < 0)
        return 0;
    if (n <=0 && max >= 1)
        return 0;
    return count(a, n - 1, max)+count(a, n, max - a[n-1]);
}
int main()
{
    int m;
    scanf("%d", &m);
    int arr[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);
    int n = 10;
    printf("Ans is : %d", count(arr, m, n));
    return 0;
}