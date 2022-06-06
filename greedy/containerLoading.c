#include <stdio.h>
#include <conio.h>

    void containerLoading(int a[], int n, int max)
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
            int min_a = a[0], j=0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] < min_a)
                {
                    min_a = a[i];
                    j = i;
                }
            }
            if (min_a <= max)
            {
                count[j] = 1;
                max = max - min_a;
                a[j]=__INT_MAX__;
            }else{
                break;
            }
        }
        printf("\n Solution set is:\nElement\t\tCount\n");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t\t%d\n", t[i], count[i]);
        }
    }

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int price = 400;
    containerLoading(arr,n,price);
    return 0;
}