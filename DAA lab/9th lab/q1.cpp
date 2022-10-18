#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
#define V 5

int main()
{
    int G[V][V] =  {{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}};

    int u; 
    int visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    u = 0;
    visited[0] = true;

    int x;
    int y; 
    cout << "Edge" << " : "<< "Cost";
    cout << endl;
    while (u < V - 1)
    { 
        int min = INT_MAX;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!visited[j] && G[i][j])
                    { 
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout << x << " ---> " << y << " :  " << G[x][y];
        cout << endl;
        visited[y] = true;
        u++;
    }
    cout << "\n\n";
    return 0;
}