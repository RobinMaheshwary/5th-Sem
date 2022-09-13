//  activity scheduling using greedy algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" ");

}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *start, int *finish, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (finish[j] > finish[j + 1])
            {
                swap(&finish[j], &finish[j + 1]);
                swap(&start[j], &start[j + 1]);
            }
        }
    }
}

int main()
{
    printf("20051828,robin\n");
    clock_t s,e;
    s = clock();
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    int start[n], finish[n];
    printf("Enter the start time of activities: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &start[i]);
    }
    printf("Enter the finish time of activities: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &finish[i]);
    }
    sort(start, finish, n);
    printf("The activities to be performed are: ");
    int i = 0;
    printf("%d ", i);
    for (int j = 1; j < n; j++)
    {
        if (start[j] >= finish[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
    printf(" ");
    e = clock();
    double time_taken = ((double)(e - s)) / CLOCKS_PER_SEC;
    printf("Time taken: %f", time_taken);
    return 0;
}
