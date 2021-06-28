// Prim's Minimum Spanning Tree using Adjacency Matrix Representation

#include <bits/stdc++.h>
using namespace std;

#define  V 5
int minKey(int key[], bool mst[])
{
    int min = INT_MAX, min_index;

    for( int v = 0; v < V; v++ )
        if ( mst[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;        
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for(int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}

void primMST( int graph[V][V] )
{
    int parent[V]; // array to store MST
    int key[V];  // key values to pick min weight edge
    bool mst[V];   // to represent set of vertices included in MST

    //initialize all keys as Infinite and mark all vertices not visited

    for(int i = 0 ; i < V ; i++){
        key[i] = INT_MAX, mst[i] = false;
    }

    key[0] = 0;   // 0th vertex is picked first (let)
    parent[0] = -1;   //first node is always roots of MST

    for( int count = 0; count < V-1 ; count++){
        
        //pick min vertex from the vertices not included in MST
        int u = minKey( key , mst );

        //Mark the vertex u as visited
        mst[u] = true;

        //update key value and parent index of adjacent vertices of u

        for(int v = 0 ; v < V; v++ ){

            // graph[u][v] is not zero only for adjacent vertices of m
            // mst[v] is false for vertices not yet included in MST
            //Update key only when graph[u][v] is smaller than key[v]

            if( graph[u][v] && mst[v] == false && graph[u][v] < key[v] )
                parent[v] = u, key[v] = graph[u][v]; 
        
        }

     }
     printMST ( parent , graph );

}

int main()
{
    int graph[V][V] = { {0, 2, 0, 6, 0 },
                        {2, 0, 3, 8, 5 },
                        {0, 3, 0, 0, 7 },
                        {6, 8, 0, 0, 9 },
                        {0, 5, 7, 9, 0 } };

    primMST(graph);

    return 0;                    
}


//https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
//Time Complexity is: O(V^2)