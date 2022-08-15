#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
using namespace std;
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

int primeFactorisation_method(int a, int b)
{
    int temp1, temp2, gcd;
    temp1 = a;
    temp2 = b;
    for (int i = 2; i <= temp1 && i <= temp2; ++i)
    {
        while (temp1 % i == 0 && temp2 % i == 0)
        {
            gcd = i;
            temp1 /= gcd;
            temp2 /= gcd;
        }
    }
    return gcd;
}

int main()
{
    clock_t  start1,end1;
    clock_t  start2,end2;
    clock_t  start3,end3;

    int number1, number2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &number1, &number2);
    if (number1 < 0 || number2 < 0)
    {
        printf("Error: n must be positive.\n");
        return 0;
    }
    else
    start1 = clock();
    cout<<"gcd1= "<<Euclid(number1, number2);
    end1 = clock();
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken1 << setprecision(5);
    cout << "sec" << endl;

    start2 = clock();
    cout<<"gcd2= "<<Consecutive_integer_checking(number1, number2);
    end2 = clock();
    double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken2 << setprecision(5);
    cout << "sec" << endl;

    start3 = clock();
    cout<<"gcd3= "<<primeFactorisation_method(number1, number2);
    end3 = clock();
    double time_taken3 = double(end3 - start3) / double(CLOCKS_PER_SEC);
    cout << "\n\nTime taken by program is :" << fixed << time_taken3 << setprecision(5);
    cout << "sec" << endl;
    
    
    return 0;
}