// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        // Last i elements are already in place
        for (j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[] = {8, 2, 4, 1, 3};
    int n = 5;
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}