#include <bits/stdc++.h>
using namespace std;
#define V 11
double  X = INFINITY;

int minDistance(int dist[], bool visited[])
{
    int min = X, maxIndex;
    for (int v = 0; v < V; v++)
        if (visited[v] == false && dist[v] <= min)
            min = dist[v], maxIndex = v;
    return maxIndex;
}
void dijkstra(double graph[V][V], int src, int dst)
{
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
        dist[i] = X, visited[i] = false;

    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != X &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    if (dist[dst] != INFINITY)
        cout << dist[dst] << " is the shortest path from ";
    else
        cout << "No path exists from ";

    cout << (char)(src + 'a') << " to " << (char)(dst + 'a') << endl;
}

int main()
{
    
    double graph[V][V] = {{0, X, X, X, X, 7, X, X, X, X, X},
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
    char src, dst;
    cout << "Enter source and destination nodes: ";
    cin >> src >> dst;
    dijkstra(graph, src - 'a', dst - 'a');
    return 0;
}