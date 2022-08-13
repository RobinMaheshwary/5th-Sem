#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findMajorityNormal(int nums[], int n)
{
    for (int i = 0; i <= n / 2; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }
        if (count > n / 2)
            return nums[i];
    }
    return -1;
}
int findMajorityLinear(int nums[], int n)
{
    int m;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == 0)
            m = nums[j], i = 1;
        else
            (m == nums[j]) ? i++ : i--;
    }
    return m;
}
int main()
{
    printf("robin, 20051828\n");
    printf("Enter the value of n : ");
    
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n;i++)
        scanf("%d",&arr[i]);
    clock_t t = clock();
    printf("The major element in (O(n^2)): %d\n", findMajorityNormal(arr, n));
    t = clock() - t;
    printf("Time taken Normal method : %f\n", ((double)t) / CLOCKS_PER_SEC);
    t = clock();
    printf("The major element in (O(n)): %d\n", findMajorityLinear(arr, n));
    t = clock() - t;
    printf("Time taken Boyer-Moore method : %f\n", ((double)t) / CLOCKS_PER_SEC);
}