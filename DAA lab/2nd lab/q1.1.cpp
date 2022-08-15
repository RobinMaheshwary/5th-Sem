#include <bits/stdc++.h>
using namespace std;

void halfN_method(int n)
{
    int i, count = 0, flag = 0;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("%d is prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
}

int main()
{
    clock_t start, end;
    start = clock();

    cout << "\n\nrobin,20051828\n\n";
    int n;
    cout << "enter n ";
    cin >> n;
   halfN_method(n);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken << setprecision(5);
    cout << "sec" << endl;

    return 0;
}