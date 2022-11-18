// Implement a algorithm to find minimum cost path between individual node in semi-directional and unconnected graph

#include <bits/stdc++.h>
#include <limits.h>

using namespace std;
#define V 11
#define X INT_MAX

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printSolution(int dist[], int n)
{
    cout << "Vertex \t\t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t " << dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist, V);
}

int main()
{
    int graph[V][V] = {{0, X, X, X, X, 7, X, X, X, X, X},
                       {5, 0, 3, X, X, X, X, 11, X, X, X},
                       {X, 3, 0, 6, 9, X, X, X, X, X, X},
                       {X, X, 6, 0, 5, X, X, X, X, X, X},
                       {X, X, X, X, 0, 7, X, X, X, X, X},
                       {X, X, X, X, 7, 0, X, X, X, X, X},
                       {X, X, X, X, X, X, 0, 7, X, X, 5},
                       {X, X, X, X, X, X, 7, 0, 3, X, X},
                       {X, X, 2, X, X, X, X, 3, 0, 8, 6},
                       {X, X, X, X, X, X, 4, X, X, 0, X},
                       {X, X, X, X, X, X, 5, X, X, X, 0}};
    dijkstra(graph, 0);
    return 0;
}
