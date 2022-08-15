 #include <bits/stdc++.h>
using namespace std;

int factorial_Method(int n)
{

    // if ((n-1)!+1)%n == 0 then n is prime
    int count = 0;
    int factm = 1;
    int m = n - 1;

    for (int i = 1; i <= m; i++)
    {
        factm *= i;
    }
    int factn = factm + 1;
    if (factn % n == 0)
    {
        printf(" %d  is prime number.\n", n);
    }
    else
    {
        printf("%d  is not prime number.\n", n);
    }
    return 0;
}

int main()
{
    clock_t start, end;
    start = clock();

    cout << "\n\nrobin,20051828\n\n";

     int n;
    cout << "enter n ";
    cin >> n;
   factorial_Method(n);

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken << setprecision(5);
    cout << "sec" << endl;
    return 0;
}