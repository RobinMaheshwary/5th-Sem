// def miniMaxSum(arr):
//     arr.sort()
//     hold = [None]*int(len(arr)-3)
//     for i in range (0,len(arr)-3):
//         temp=0
//         for j in range(i,i+4):
//             temp = temp + arr[j]
//         hold[i] = temp
//     print(hold[0],hold[-1])

// convert it into cpp

// Path: C/C++/q.cpp
#include <bits/stdc++.h>
using namespace std;

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    vector<int> hold(arr.size() - 3);
    for (int i = 0; i < arr.size() - 3; i++)
    {
        int temp = 0;
        for (int j = i; j < i + 4; j++)
        {
            temp = temp + arr[j];
        }
        hold[i] = temp;
    }
    cout << hold[0] << " " << hold[hold.size() - 1] << endl;
}
