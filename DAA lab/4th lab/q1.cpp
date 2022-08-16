#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
using namespace std;

int binarySearch(int array[], int n, int x)
{
    int first = 0,
        last = n - 1, middle, position = -1;
    bool found = false;
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == n)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > x)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}
int main()
{
    clock_t start, end;
    start = clock();
    int n = rand() % 100 + 1;
    cout << "n=" << n << endl;
    int a[n];
    cout << "array";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << ", ";
    }

    int x = a[rand() % 100 - 1];
    cout << "x=" << x;
    int posIndex = binarySearch(a, n, x);
    cout << "\n"
         << posIndex << "\n";
    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR PROGRAM=" << time_taken << setprecision(6) << "sec" << endl;

    return 0;
}