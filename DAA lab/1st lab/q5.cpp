#include <bits/stdc++.h>
#include <time.h>
using namespace std;

const int M = 4;
const int N = 4;

void nonzero(int n, int arr[][4])
{
    int nonzeroes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
                nonzeroes++;
        }
    }
    cout << "number of non zero elements " << nonzeroes << endl;
}
void upperhalf(int n, int arr[][4])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                sum += arr[i][j];
        }
    }
    cout << "the sum of upper half is " << sum << endl;
}
void belowhalf(int n, int arr[][4])
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
                cout << arr[i][j] << " ";
        }
        cout << endl;
    };
}
void product_diagonal(int n, int arr[][4])
{
    int pro = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                pro *= arr[i][j];
        }
    }
    cout << "the product of diagonal is " << pro << endl;
}
void matrixx()
{
    int n = 4;
    int arr[4][4];
    random_device rd;  // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(-100, 100);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = distr(gen);
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    nonzero(n, arr);
    upperhalf(n, arr);
    belowhalf(n, arr);
    product_diagonal(n, arr);
}
int main()
{
    clock_t start, end;
    start = clock();
    cout << "\n\nrobin,20051828\n\n";
    

    matrixx();
    end = clock();

    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}