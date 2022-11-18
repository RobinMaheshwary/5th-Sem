// There are N balls in a bag. Initially, the ith ball has a number A[i] on it.

// In one second, a ball with number k (k>1), dissociates into k balls, where each of the k balls has number (k-1)written on it.
// If k = 1, there is no change on the state of the ball.

// Find th number of balls in the bag after 100^{100} seconds. Since the final number of balls can be huge, output the answer modulo 10^9+7.
// input:
// 3
// 1
// 2
// 2
// 1 2
// 3
// 3 1 3

// output:
// 2
// 3
// 13

// solution:

#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int fun(int n){
    if(n==1)
        return 1;
    else
        return (n*fun(n-1))%mod;
}

int main()
    {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
       
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int sum=0;
        for(int i=0;i<n;i++)
            sum=(sum+fun(a[i]))%mod;
        cout<<sum<<endl;
        
    }
    return 0;
}






