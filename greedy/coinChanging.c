#include <stdio.h>
void count(int a[], int n, int max)
{
    // max of a
    int count[n],t[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
        t[i] = a[i];
    }
    while (max > 0)
    {
        int max_a = a[0], j=0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > max_a)
            {
                max_a = a[i];
                j = i;
            }
        }
        if (max_a <= max)
        {
            count[j] = max / max_a;
            max = max % max_a;
            a[j]=0;
        }else{
            a[j] = 0;
            count[j] = 0;
        }
    }
    printf("\n Solution set is:\nElement\t\tCount\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", t[i], count[i]);
    }
}
int main()
{
    int m;
    scanf("%d", &m);
    int arr[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &arr[i]);
    int n = 10;
    count(arr, m, n);
    return 0;
}
