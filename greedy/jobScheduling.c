#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)
struct job
{
    int index, deadline;
    float profit;
};
void bubbleSort(struct job array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i].profit < array[i + 1].profit)
            {
                struct job temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void schedule(struct job data[], int n)
{
    int i, j, check[n], ans = 0;
    for (int k = 0; k < n; k++)
        check[k] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = MIN(data[i].deadline, n) - 1; j >= 0; j--)
        {
            if (!check[j])
            {
                check[j] = data[i].index;
                ans += data[i].profit;
                break;
            }
        }
    }
    printf("The sequence of job is: \n");
    for (i = 0; i < n; i++)
        if (check[i])
            printf("J%d ", check[i]);
    printf("\nThe max profit is: %d\n", ans);
}

int main()
{
    struct job data[100];
    int n, i, j;
    printf("Enter number of jobs:");
    scanf("%d", &n);
    printf("\nEnter jobs in the order (id deadline profit):");
    for (i = 0; i < n; i++)
        scanf("%d%d%f", &data[i].index, &data[i].deadline, &data[i].profit);
    bubbleSort(data, n);
    schedule(data, n);
    return 0;
}