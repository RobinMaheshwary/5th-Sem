// Write a program to find out the second smallest and second largest element stored in an
// array of n integers. n is the user input. The array takes input through random number
// generation within a given range. How many different ways you can solve this problem.
// Write your approaches & strategy for solving this problem.

#include <stdio.h>
#include <stdlib.h>

int second_largest(int *arr, int n)
{
    int largest = arr[0];
    int second_largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > second_largest)
        {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

int second_smallest(int *arr, int n)
{
    int smallest = arr[0];
    int second_smallest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < second_smallest)
        {
            second_smallest = arr[i];
        }
    }
    return second_smallest;
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    printf("The array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("The second largest element is: %d\n", second_largest(arr, size));
    printf("The second smallest element is: %d\n", second_smallest(arr, size));
    return 0;
}