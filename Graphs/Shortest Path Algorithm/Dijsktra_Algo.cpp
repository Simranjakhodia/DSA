#include <bits/stdc++.h>

#define V 9


int minDistance(int dist[], bool sptSet[])
{
    //Initialize min value
    int min = INT_MAX, min_index ;

    for(int v = 0 ; v < V; v++){
        if(sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    }
    return min_index;
}

//Function to print shortest path from source to j using parent array

void printPath( int parent[] , int j)
{
    //Base case : If j is source
    if( parent[j] == -1)
        return;

    printPath( parent , parent[j] );
    printf("%d ", j);    
}

void printSolution( int dist[], int n , int parent[])
{
    int src = 0;
    printf("Vertex \t\t Distance From Source\n");
    for( int i = 1; i < V; i++ ){
        printf("\n%d -> %d \t\t %d\t\t%d ", src , i , dist[i] , src );
        printPath(parent , i );
    }
}

void dijkstra( int graph[V][V] , int src)
{
    int dist[V];   //The output array, dist[i] will hold shortest distance from src to i
    bool sptSet[V]; // vertex i is included in shortest path or not

    //parent array to store shortest path tree
    int parent[V];
    //Initialize all distances as INFINITE and stpSet[] as false
    for ( int i = 0; i < V ; i++)
    dist[i] = INT_MAX , sptSet[i] = false, parent[0] = -1;

    //Distance of src vertex from itself is 0 so:
    dist[src] = 0;

    //Find Shortest path for all vertices
    for( int count = 0; count < V - 1; count++ ){
        
        //Pick the min distance vertex from set of vertices not included in path yet

        int u = minDistance(dist, sptSet);

        //Mark the picked vertex as true 
        sptSet[u] = true;

        //update distance value to adjacent vertices of picked vertex

        for(int v = 0; v < V; v++){

            // Update dist[v] only is not in sptSet, there is an edge from u to v , and total weight of path 
            // from src to v through u is smaller than current value of dist[v]

            if( !sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v] , parent[v] = u ;
        }  
    }
    // print the constructed distance array 
    printSolution(dist, V , parent );
}

int main()
{

    // adjacency matrix implementation
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0 );

    return 0;                    
}
