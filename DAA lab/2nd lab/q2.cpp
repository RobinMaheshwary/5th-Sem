#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int static dp[1001][1001];
int Euclid(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int Consecutive_integer_checking(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

// int primeFactorisation_method(int a, int b)
// {
//     int temp1, temp2, gcd;
//     temp1 = a;
//     temp2 = b;
//     for (int i = 2; i <= temp1 && i <= temp2; ++i)
//     {
//         while (temp1 % i == 0 && temp2 % i == 0)
//         {
//             gcd = i;
//             temp1 /= gcd;
//             temp2 /= gcd;
//         }
//     }
//     return gcd;
// }

// int primeFactorisation_method(int a, int b){
//     int a[10000000000];
//     for (int i=0; i>b; i++){
//         if(a%i==0 && a%b==0)
//             a[i]=i;
//     }
//     return a[-1];
// }

int gcd(int a, int b)
{

    // Everything divides 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // base case
    if (a == b)
        return a;

    // if a value is already
    // present in dp
    if (dp[a][b] != -1)
        return dp[a][b];

    // a is greater
    if (a > b)
        dp[a][b] = gcd(a - b, b);

    // b is greater
    else
        dp[a][b] = gcd(a, b - a);

    // return dp
    return dp[a][b];
}

int main()
{
    clock_t start1, end1;
    clock_t start2, end2;
    clock_t start3, end3;
    cout << "\n\nrobin,20051828\n\n";
    int number1, number2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);
    if (number1 < 0 || number2 < 0)
    {
        printf("Error: n must be positive.\n");
        return 0;
    }
    else
    {
        start1 = clock();
        cout << "gcd1= " << Euclid(number1, number2);
        end1 = clock();
        double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
        cout << "\n\nTime taken by program is :" << fixed << time_taken1 << setprecision(5);
        cout << "sec" << endl;

        start2 = clock();
        cout << "gcd2= " << Consecutive_integer_checking(number1, number2);
        end2 = clock();
        double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
        cout << "\n\nTime taken by program is :" << fixed << time_taken2 << setprecision(5);
        cout << "sec" << endl;

        start3 = clock();
        memset(dp, -1, sizeof(dp));
        cout << "gcd3= " << gcd(number1, number2);
        end3 = clock();
        double time_taken3 = double(end3 - start3) / double(CLOCKS_PER_SEC);
        cout << "\n\nTime taken by program is :" << fixed << time_taken3 << setprecision(5);
        cout << "sec" << endl;
    }
    return 0;
}