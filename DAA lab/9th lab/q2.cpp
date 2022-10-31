#include <iostream>
#include <stdlib.h>
#include <limits.h>

using namespace std;

#define Vertices 5

// Finding the vertex with the lowest key value from a set of vertices not included in MST

int Least_Key(int key[], bool Min_Span_Tree[])

{

    int least = INT_MAX, min_index;

    for (int v = 0; v < Vertices; v++)

        if (Min_Span_Tree[v] == false && key[v] < least)

            least = key[v], min_index = v;

    return min_index;
}


void print_Prims_MST(int parent[], int graph[Vertices][Vertices])

{

    cout << " Edge  : Cost";

    for (int i = 1; i < Vertices; i++)
         cout << "\n"<<" "<< parent[i]<<"-->" << i <<" : "<< graph[i][parent[i]];
}


void prims_MST(int graph[Vertices][Vertices])

{

    int parent[Vertices];

    int key[Vertices];

    bool Min_Span_Tree[Vertices];

    for (int i = 0; i < Vertices; i++)

        key[i] = INT_MAX, Min_Span_Tree[i] = false;

    key[0] = 0;

    parent[0] = -1;

    for (int count = 0; count < Vertices - 1; count++)
    {

        int u = Least_Key(key, Min_Span_Tree);

        Min_Span_Tree[u] = true;

        for (int v = 0; v < Vertices; v++)

            if (graph[u][v] && Min_Span_Tree[v] == false && graph[u][v] < key[v])

                parent[v] = u, key[v] = graph[u][v];
    }

    cout<<"Created Spanning Tree for Given Graph is: \n";

    cout<<"\n";

    print_Prims_MST(parent, graph);
}

int main()

{

    int graph[Vertices][Vertices] = {{0, 3, 2, 0, 0},

                                     {3, 0, 16, 12, 0},

                                     {2, 16, 0, 0, 5},

                                     {0, 12, 0, 0, 0},

                                     {0, 0, 5, 0, 0}};

    prims_MST(graph);

    return 0;
}