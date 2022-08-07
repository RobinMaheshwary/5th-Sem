#include <bits/stdc++.h>
#include<chrono>
#include<unistd.h>
using namespace std::chrono;
using namespace std;

int floorSqrt(int x)
{
    if (x == 0 || x == 1)
    return x;

    int i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}
int main()
{
    auto start = system_clock::now();
    sleep(1);
    cout<<"robin, 20051828"<<endl;
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<"floor squareroot of "<<n<<" is "<<floorSqrt(n);
    auto end = system_clock::now();
    cout << "\nTIME TAKEN : " <<duration_cast<nanoseconds>(end - start).count() / pow(10, 9) - 1<< endl;
    return 0;
}
