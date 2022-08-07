#include <bits/stdc++.h>
#include<chrono>
#include<unistd.h>
using namespace std::chrono;
using namespace std;
  
int maxsum(int a[], int size)
{
    int curr_max = INT_MIN, sum = 0;
  
    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
        if (curr_max < sum)
            curr_max = sum;
  
        if (sum < 0)
            sum = 0;
    }

    if(curr_max < 0)
        return 0;
    else
        return curr_max;
}
  
int main()
{
    auto start = system_clock::now();
    sleep(1);
    cout<<"robin, 20051828"<<endl;
    int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<"Array: ";

    for(int i=0 ; i<n ; i++)
        cout << a[i] << " ";

    int max_sum = maxsum(a, n);
    cout << endl << "Maximum Sum: " << max_sum;
    auto end = system_clock::now();
    cout << "\nTIME TAKEN : " <<duration_cast<nanoseconds>(end - start).count() / pow(10, 9) - 1<< endl;
    return 0;
}