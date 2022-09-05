#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int binarySearch(int array[], int n, int x)
{
    int first = 0, last = n - 1, middle, position;
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
    clock_t start1, end1,start2, end2,start3, end3;
    int n = rand() % 100 + 1;
    cout << "n=" << n << endl;
    int a[n];
    cout << "array";
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        cout << a[i] << ", ";
    }
    cout<<endl;
    // int x = a[rand() % 100 - 1];
    int x;
    cout<<"enter a no to be searched: ";

    cin>>x;
    cout << "x=" << x;

    start1 = clock();
    int posIndex1 = binarySearch(a, n, x);
    cout << "\n"
         << posIndex1 << "\n";
    end1 = clock();

    sort(a,a+n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ", ";
    }
    cout<<endl;
    start2 = clock();
    int posIndex2 = binarySearch(a, n, x);
    cout << "\n"
         << posIndex2 << "\n";
    end2 = clock();

    sort(a, a+n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ", ";
    }
    cout<<endl;
    start3 = clock();
    int posIndex3 = binarySearch(a, n, x);
    cout << "\n"
         << posIndex3 << "\n";
    end3 = clock();

    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR PROGRAM for average case=" << time_taken1 << setprecision(6) << "sec" << endl;

    double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR PROGRAM for best case=" << time_taken2 << setprecision(6) << "sec" << endl;

    double time_taken3 = double(end3 - start3) / double(CLOCKS_PER_SEC);
    cout << "TIME TAKEN FOR PROGRAM for worst case=" << time_taken3 << setprecision(6) << "sec" << endl;
    return 0;
}