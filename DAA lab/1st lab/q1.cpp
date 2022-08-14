#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
using namespace std;
int *generateRandArray(int n)
{
    int *res = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        res[i] = (rand() % 300) - 100;
    }
    return res;
}
void printArray(int *n)
{
    for (int i = 0; i < sizeof(n); i++)
    {
        cout << n[i] << "  ";
    }
    cout << endl;
}
int *findMinMax(int *arr)
{
    int *minMax = (int *)calloc(2, sizeof(int));
    minMax[0] = INT16_MIN;
    minMax[1] = INT16_MAX;
    for (int i = 0; i < sizeof(arr); i++)
    {
        minMax[0] = minMax[0] > arr[i] ? minMax[0] : arr[i];
        minMax[1] = minMax[1] < arr[i] ? minMax[1] : arr[i];
    }
    return minMax;
}
int main()
{
    auto start = clock();

    int *n = generateRandArray(6);
    printArray(n);
    int *minMax = findMinMax(n);
    printf("Max=%d\n Min=%d\n", minMax[0], minMax[1]);
    cout << "\n\nrobin,20051828\n\n";

    auto end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}