#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int a = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            a++;
            swap(&arr[i], &arr[a]);
        }
    }
    swap(&arr[a + 1], &arr[high]);
    return (a + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter no. of elements : \n");
    scanf("%d", &n);
    int data[n];
    printf("Enter elements : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    printf("Unsorted Array\n");
    printArray(data, n);

    quickSort(data, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(data, n);
    return 0;
}