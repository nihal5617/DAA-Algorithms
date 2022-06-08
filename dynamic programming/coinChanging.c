// //gives total number of possible ways to make change for a given amount of money
// #include <stdio.h>
// int count(int a[], int n, int max)
// {
//     if (max == 0)
//         return 1;
//     if (max < 0)
//         return 0;
//     if (n <=0 && max >= 1)
//         return 0;
//     return count(a, n - 1, max)+count(a, n, max - a[n-1]);
// }
// int main()
// {
//     int m;
//     scanf("%d", &m);
//     int arr[m];
//     for (int i = 0; i < m; i++)
//         scanf("%d", &arr[i]);
//     int n = 10;
//     printf("Ans is : %d", count(arr, m, n));
//     return 0;
// }

#include <stdio.h>
#include <limits.h>
#define INF 999;

int min(int a, int b)
{
    return a < b ? a : b;
}

int coinchange(int a[], int n, int total)
{
    if (total < 0)
        return INF;
    if (total == 0)
        return 0;
    if (n == -1)
        return INF;
    int in = INF;
    int out = INF;

    in = 1 + coinchange(a, n, total - a[n]);
    out = coinchange(a, n - 1, total);
    return min(in, out);
}

int main()
{
    int n, total;
    printf("Enter number of coins:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the coins:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the total value required:\n");
    scanf("%d", &total);
    printf("The minimum required coins are %d", coinchange(a, n - 1, total));
    return 0;
}