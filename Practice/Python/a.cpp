// 2022 is a year of the Winter Olympics! Curling has been one of the most popular winter sports as it requires skill, strategy, and sometimes a bit of luck.

// In a curling game, two teams compete by sliding heavy granite stones on a long ice sheet. We call the teams the red team and the yellow team, as their stones are usually distinguished by the red and the yellow handle color. A curling game consists of several ends (subgames); in every end, the teams, each owning 8 stones, take turns to slide them across the long ice sheet toward a circular target area called the house. A stone may hit existing stones to change its own moving direction and other stones' position (including knocking them out of play). Roughly speaking, the goal for a team is to make their stones as close to the center of the house as possible.

// Geometrically, a house and a stone can be modeled as a circle and a disk (the region bounded by a circle), respectively, and the scoring rules at the conclusion of each end are formally summarized as follows.

// Each stone can be viewed as a disk of radius Rs on a 2-dimensional plane.
// The house is a circle of radius Rh centered at (0,0).
// Only stones in the house are considered in the scoring. A stone is in the house if any portion of the stone lies on or within the circle representing the house. Tangency also counts.
// A team is awarded 1 point for each of their own stones in the house such that no opponent's stone is closer (in Euclidean distance) to the center than it. We assume in this problem that no two stones are equally close to the center (0,0).
// Two teams are playing and have just delivered all their stones. The red team has N stones remaining on the curling sheet, centered at (X1,Y1),(X2,Y2),…,(XN,YN), while the yellow team has M stones remaining, centered at (Z1,W1),(Z2,W2),…,(ZM,WM). Now you are asked to figure out the scores of both teams.

// Input
// The first line of the input gives the number of test cases, T. T test cases follow.

// Each test case begins with a line containing the two space-separated integers Rs and Rh.

// The next line contains the integer N. Then N lines follow, the i-th line of which containing the two space-separated integers Xi and Yi.

// After that, similarly, the next line contains the integer M. In the next M lines, the i-th line contains the two space-separated integers Zi and Wi.

solution:

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    ll rs,rh;
    cin>>rs>>rh;
    ll n;
    cin>>n;
    vector<pair<ll,ll>> red;
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        red.push_back({x,y});
    }
    ll m;
    cin>>m;
    vector<pair<ll,ll>> yellow;
    for(ll i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        yellow.push_back({x,y});
    }
    ll redscore=0;
    ll yellowscore=0;
    for(ll i=0;i<n;i++){
        ll x=red[i].first
        ll y=red[i].second;
        ll dist=x*x+y*y;
        if(dist<=rh*rh){
            ll flag=0;
            for(ll j=0;j<m;j++){
                ll x1=yellow[j].first;
                ll y1=yellow[j].second;
                ll dist1=x1*x1+y1*y1;
                if(dist1<=rh*rh){
                    if(dist1<dist){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                redscore++;
            }
        }
    }
    for(ll i=0;i<m;i++){
        ll x=yellow[i].first;
        ll y=yellow[i].second;
        ll dist=x*x+y*y;
        if(dist<=rh*rh){
            ll flag=0;
            for(ll j=0;j<n;j++){
                ll x1=red[j].first;
                ll y1=red[j].second;
                ll dist1=x1*x1+y1*y1;
                if(dist1<=rh*rh){
                    if(dist1<dist){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                yellowscore++;
            }
        }
    }

    cout<<redscore<<" "<<yellowscore<<endl;
}

int main() {
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}

