#include <stdio.h>
struct item
{
    int index;
    float val, weight, profit;
};
void bubbleSort(struct item array[], int size)
{
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            if (array[i].profit < array[i + 1].profit)
            {
                struct item temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
int main()
{
    int n, total_weight;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weight of knapsck: ");
    scanf("%d", &total_weight);
    struct item items[n];
    float vector[n];
    for (int i = 0; i < n; i++)
    {
        vector[i] = 0;
    }
    printf("Enter the value and weight of items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f %f", &items[i].val, &items[i].weight);
        items[i].index = i;
        items[i].profit = items[i].val / items[i].weight;
    }
    bubbleSort(items, n);
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (total_weight - items[i].weight >= 0)
        {
            sum += items[i].val;
            total_weight -= items[i].weight;
            vector[items[i].index] = 1;
        }
        else if (total_weight > 0)
        {
            float temp = (total_weight / items[i].weight);
            sum += items[i].val * temp;
            vector[items[i].index] = (total_weight / items[i].weight);
            total_weight = 0;
        }
        else
            break;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%f ", vector[i]);
    }
    printf("\nSum = %f", sum);
}
