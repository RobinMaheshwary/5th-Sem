#include <bits/stdc++.h>
using namespace std;

int seive()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(2, 100);

    cout << "enter n";
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = distr(gen);
        for (int j = 2; j < 9; j++)
        {
            if (arr[i] % j == 0)
            {
                arr[i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        cout << arr[i] << " ";
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    cout << "\n\nrobin,20051828\n\n";

    seive();

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken << setprecision(5);
    cout << "sec" << endl;
    return 0;
}