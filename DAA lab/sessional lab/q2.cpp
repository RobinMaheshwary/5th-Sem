// Given a string s, return the longest palindromic substring in s.


#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout<<"20051828, robin"<<endl;
    string s;

    cin >> s;
    int n = s.length();
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l > end - start)
            {
                start = l;
                end = r;
            }
            l--;
            r++;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if (r - l > end - start)
            {
                start = l;
                end = r;
            }
            l--;
            r++;
        }
    }
    cout << s.substr(start, end - start + 1)<<endl;
    return 0;
}