#include <stdio.h>

struct job
{
    int id;
    int t1;
    int t2;
};

void bubbleSort1(struct job arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].t1 > arr[j + 1].t1)
            {
                struct job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void bubbleSort2(struct job arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].t2 > arr[j + 1].t2)
            {
                struct job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int min_arr(int arr[][3], int n, int a)
{
    int min = arr[0][a];
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i][a])
            min = arr[i][a];
    }
    return min;
}

int max_arr(int arr[][3], int n)
{
    int max = arr[0][1];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i][1])
        {
            max = arr[i][1];
        }
    }
    return max;
}

int main()
{
    printf("Johnson's algorithm for 3 machine scheduling problem\n");
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    struct job arr[n];
    int input[n][3];
    printf("Enter the processing time of jobs: ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d %d %d", &input[i][0], &input[i][1], &input[i][2]);
    }

    int a = min_arr(input, n, 0);
    int b = max_arr(input, n);
    int c = min_arr(input, n, 2);
    // checking constraint
    if (a >= b || b <= c)
    {

        for (int i = 0; i < n; i++)
        {
            arr[i].id = i + 1;
            arr[i].t1 = input[i][0] + input[i][1];
            arr[i].t2 = input[i][1] + input[i][2];
        }

        int j = 0;
        struct job m1[n];
        for (int i = 0; i < n; i++)
            if (arr[i].t1 <= arr[i].t2)
                m1[j++] = arr[i];
        bubbleSort1(m1, j);
        struct job m2[n];
        int k = 0;
        for (int i = 0; i < n; i++)
            if (arr[i].t1 > arr[i].t2)
                m2[k++] = arr[i];
        bubbleSort2(m2, k);
        struct job m3[n];
        for (int i = 0; i < j; i++)
            m3[i] = m1[i];
        for (int i = 0; i < k; i++)
            m3[j + i] = m2[k - i - 1];
        printf("\nThe order of jobs is: ");
        for (int i = 0; i < n; i++)
            printf("%d ", m3[i].id);
        printf("\n");
    }
    return 0;
}
