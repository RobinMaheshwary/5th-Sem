#include <bits/stdc++.h>
using namespace std;

int main()
{
    clock_t start, end;
    start = clock();

    cout << "\n\nrobin,20051828\n\n";
    int n;
    cout << "enter n ";
    cin >> n;
    int arr[n];

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(2, 10000);

    for (int i = 0; i < n; i++)
    {
        arr[i] = distr(gen);
        bool flag = true;

        for (int j = 2; j * j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            cout << arr[i] << " ";
        }
        // cout<<arr[i]<<" ";
    }

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken << setprecision(5);
    cout << "sec" << endl;

    return 0;
}