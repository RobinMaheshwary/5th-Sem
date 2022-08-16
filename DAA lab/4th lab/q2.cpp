#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void reverse(int a[], int n) {}

void merge(int arr[], int p, int q, int r)
{

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}
int main()
{
    cout << "\n\nrobin,20051828\n\n";
    int n;
    cout << "enter valu of n";
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << ", ";
        b[i] = a[i];
    }
    cout << endl;
    clock_t start, end;
    start = clock();

    mergeSort(a, 0, n - 1);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR random data=" << time_taken << setprecision(5) << "sec" << endl;

    sort(b, b + n);
    clock_t start1, end1;
    start1 = clock();

    mergeSort(a, 0, n - 1);

    end1 = clock();
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR sorted data=" << time_taken1 << setprecision(5) << "sec" << endl;

    sort(a, a + n, greater<int>());
    clock_t start2, end2;
    start2 = clock();

    mergeSort(b, 0, n - 1);

    end2 = clock();
    double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR reversly sorted data=" << time_taken2 << setprecision(5) << "sec" << endl;

    return 0;
}