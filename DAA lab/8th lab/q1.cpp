/* Nikhil wants to bring sofa(s) to his room. But he wants to dedicate the entire length of the room to the sofa(s). Nikhil's room length is W meters
and when he went to the shop he found out sofas of two types, one of length N and other of length M. Let Nikhil know how many sofas of the
first and second type he should buy to reduce wastage of space. First minimize the space wastage then, if similar result arises always
prefer the sofa with a larger length. */

  

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp1(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}

bool cmp2(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll w, n, m;
        cin >> w>>n>>m;
        
        vector<pair<ll, ll>> value[w + 1];
        ll so = 1;
        
        if (n > m)
        {
            so = 0;
        }
        
        for (ll i = w / m; i >= 0; i--)
        {
            ll l = w - (m * i);
            value[l % n].push_back({l / n, i});
        }
        
        ll f = 1;
        for (ll i = 0; i <= w; i++)
        {
            if (value[i].size() > 0)
            {
                f = 0;
                if (so == 0)
                    sort(value[i].begin(), value[i].end(), cmp1);
                else
                    sort(value[i].begin(), value[i].end(), cmp2);
                cout << value[i][0].first << " " << value[i][0].second << "\n";
                break;
            }
        }
        if (f == 1)
            cout << "0 0\n";
        
        cout<<endl<<endl;
    }
    return 0;
}