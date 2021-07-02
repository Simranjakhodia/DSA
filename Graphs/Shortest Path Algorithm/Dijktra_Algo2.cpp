# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

//A structure to represent a node in adjacency list

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};

//A structure to represent adjacency list
struct AdjList
{
    struct AdjListNode * head;  //pointer to head node of the list
};

//A structure to represent a graph.
//A graph is an array of adjacency lists.
//Size of array will be V(no of vertices in graph)

struct Graph
{
    int V;
    struct AdjList* array;
};

//A function to create a new adjacency list node

struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc ( sizeof (struct AdjListNode));
    newNode -> dest = dest;
    newNode -> weight = weight;
    newNode -> next = NULL;
    return newNode;
} 

//A function that creates a graph of V vertices

struct Graph* createGraph( int V )
{
    struct Graph* graph = (struct Graph*) malloc ( sizeof ( struct Graph ));
    graph -> V = V;

    //Create an array of adjacency lists
    //Size of array will be V
    graph -> array = ( struct AdjList* ) malloc ( V * sizeof ( struct AdjList ) );

    //Initialize each adjacency list as empty by making head NULL
    for ( int i = 0 ; i < V ; i++ )
        graph -> array [i].head = NULL;

    return graph;

}

//Add an edge to an undirected graph

void AddEdge ( struct Graph* graph , int src , int dest , int weight )
{
    //Add an edge from src to dest.
    //A new node is added to the adjacency list of src . The node is
    //added at the beginning 

    struct AdjListNode* newNode = newAdjListNode ( dest , weight );
    newNode -> next = graph -> array [src].head;
    graph -> array[src].head = newNode;

    //Since graph is undirected , add an edge from dest to src also

    newNode = newAdjListNode ( src , weight );
    newNode -> next = graph -> array [dest].head;
    graph -> array[ dest].head = newNode;

}

//Structure to represent a min heap node
struct MinHeapNode
{
    int v;
    int dist;
};

//Structure to represent to represent a min heap
struct MinHeap 
{
    //No. of heap nodes present currently
    int size;

    //Capacity of min heap
    int capacity;

    //This is needed for decreaseKey()
    int *pos;
    struct MinHeapNode ** array ;

};

//A function to create a new Min Heap Node
struct MinHeapNode* newMinHeapNode ( int v, int dist)
{

    struct MinHeapNode*  minHeapNode = ( struct MinHeapNode* ) malloc (sizeof (struct MinHeapNode )) ;
    minHeapNode -> v = v;
    minHeapNode -> dist = dist;

    return minHeapNode;

}

//Function to  create a Min Heap
struct MinHeap* createMinHeap ( int capacity )
{
    struct MinHeap* minHeap = (struct MinHeap*) malloc ( sizeof ( struct MinHeap ));
    minHeap -> pos = (int *) malloc ( capacity * sizeof(int ));
    minHeap -> size = 0 ;
    minHeap -> capacity = capacity;
    minHeap -> array = (struct MinHeapNode**) malloc ( capacity * sizeof (struct MinHeapNode*) );
    
    return minHeap;
}

//A function to swap nodes of min Heap
// Needed for min Heapify function

void swapMinHeapNode ( struct MinHeapNode** a , struct MinHeapNode** b )
{
    struct MinHeapNode *t = *a;
    *a = *b ;
    *b = t ; 
}

//A function to heapify at given index
//Also updates position of nodes when they are swapped. Position is needed for decreaseKey()

void minHeapify ( struct MinHeap* minHeap , int idx )
{
    int smallest , left , right ;
    smallest = idx ; 
    left = 2 * idx + 1 ;
    right = 2 * idx + 2;

    if ( left < minHeap -> size && minHeap->array[left] ->dist < minHeap->array[smallest] -> dist )
        smallest = left;

    if ( right < minHeap -> size && minHeap->array[right] ->dist < minHeap->array[smallest] -> dist )
        smallest = right;

    if ( smallest != idx )
    {
        //The nodes to be swapped in min heap
        MinHeapNode *smallestNode = minHeap -> array [ smallest];
        MinHeapNode *idxNode = minHeap -> array [ idx];

        //Swap positions
        minHeap -> pos [ smallestNode -> v ] = idx;
        minHeap -> pos [ idxNode -> v ] = smallest;

        //Swap nodes
        swapMinHeapNode( &minHeap -> array [ smallest] , &minHeap -> array [ idx] );

        minHeapify( minHeap, smallest );
    }        
}

//A function to check if given minHeap is empty or not

int isEmpty( struct MinHeap* minHeap )
{
    return minHeap -> size == 0;
}

// Function to extract min node from heap

struct MinHeapNode* extractMin( struct MinHeap* minHeap)
{
    if ( isEmpty(minHeap) )
        return NULL;

    // store the root node
    struct MinHeapNode* root = minHeap->array[0];

    // Replace root node with last node
    struct MinHeapNode* lastNode = minHeap -> array [ minHeap -> size - 1];
    minHeap -> array[0] = lastNode;

    //Update position of last node
    minHeap -> pos[ root -> v ] = minHeap -> size - 1 ;
    minHeap -> pos[ lastNode -> v ] = 0;

    //Reduce heap size and heapify root
    --minHeap -> size;
    minHeapify( minHeap , 0 );

    return root ;   
}

// Function to decrease dist value of a given vertex v. This function uses 
// pos[] of min heap to get the current index of node in min heap

void decreaseKey( struct MinHeap* minHeap, int v, int dist)
{
    // Get the index of v in heap array
    int i = minHeap -> pos[v];

    // Get the node and update its dist value
    minHeap -> array[i] -> dist = dist;
    
    // Travel up while the complete tree is not hepified
    // This is a O(Logn) loop
    while(i && minHeap -> array[i] -> dist < minHeap -> array[ (i-1) / 2] -> dist )
    {
        // Swap this node with its parent
        minHeap -> pos [minHeap -> array[i] -> v] = (i - 1) / 2;

        minHeap -> pos [minHeap -> array [ (i - 1)/2] -> v ] = i;

        swapMinHeapNode( &minHeap -> array[i] , &minHeap -> array[( i - 1) / 2]);

        //move to parent index
        i = (i - 1) / 2;
        
    }
}

// To check if a given vertex 'v' is in min heap or not

bool isInMinHeap( struct MinHeap *minHeap , int v)
{
    if (minHeap -> pos[v] < minHeap->size)
        return true;
    return false;    
}

void printArr(int dist[] , int n)
{
    printf("Vertex \t Distance from source\n");
    for ( int i = 0 ; i < n ; ++i)
        printf("%d \t\t %d \n", i , dist[i] );
}

// The Function which calculates distances of shortest paths from src to all
// vertices . It is a O( E Log V) function

void dijkstra( struct Graph* graph, int src)
{
    int V = graph -> V;

    int dist[V];
    struct MinHeap* minHeap = createMinHeap(V);

    // Initialize min heap with all vertices. dist value of all vertices
    for( int v = 0 ; v < V ; ++v ){
        dist[v] = INT_MAX;
        minHeap -> array [v] = newMinHeapNode( v , dist[v] );

        minHeap -> pos[v] = v ;
 
    }

    // Make dist value of src vertex as 0 so that it is extracted first
    minHeap -> array [ src ] = newMinHeapNode( src, dist[src] );
    minHeap -> pos [ src ] = src ;
    dist[src] = 0;
    decreaseKey ( minHeap, src, dist[src] );

    // Initially size of min heap is equal to V
    minHeap -> size = V;

    // In the following loop min heap contains all nodes whose shortest distance 
    // is not yet finalized
    while( !isEmpty(minHeap) )
    {
        // Extract the vertex with min distance value
        struct MinHeapNode* minHeapNode = extractMin( minHeap );

        // Store the extracted vertex no
        int u = minHeapNode -> v;

        // Traverse through all adjacent vertices of u ( the extracted vertex ) 
        // and update their distance values

        struct AdjListNode* pCrawl = graph -> array [u]. head;
        while ( pCrawl != NULL ){
            int v = pCrawl -> dest;

            // If shortest distance to v is not finalized yet, and distance
            // To v through u is less than its previously calculated distance

            if ( isInMinHeap( minHeap, v ) && 
                    dist[u] != INT_MAX && 
                pCrawl -> weight + dist[u] < dist[v] )
            {
                dist[v] = dist[u] + pCrawl -> weight;

                // Update distance
                // Value in Min Heap 
                decreaseKey ( minHeap, v, dist[v] );
            }
            pCrawl = pCrawl -> next;  
        } 
    }
        // print the calculated shortest distance
        printArr ( dist, V);

}

//Driver program to test above functions
int main()
{
    // create the graph given in above figure
    int V = 9;
    struct Graph* graph = createGraph( V );
    AddEdge ( graph , 0 , 1 , 4);
    AddEdge ( graph , 0 , 7 , 8);
    AddEdge ( graph , 1 , 2 , 8);
    AddEdge ( graph , 1 , 7 , 11);
    AddEdge ( graph , 2 , 3 , 7);
    AddEdge ( graph , 2 , 8 , 2);
    AddEdge ( graph , 2 , 5 , 4);
    AddEdge ( graph , 3 , 4 , 9);
    AddEdge ( graph , 3 , 5 , 14);
    AddEdge ( graph , 4 , 5 , 10);
    AddEdge ( graph , 5 , 6 , 2);
    AddEdge ( graph , 6 , 7 , 1);
    AddEdge ( graph , 6 , 8 , 6);
    AddEdge ( graph , 7 , 8 , 7);

    dijkstra ( graph , 0 );

    return 0;
}





//https://www.geeksforgeeks.org/dijkstras-algorithm-for-adjacency-list-representation-greedy-algo-8/