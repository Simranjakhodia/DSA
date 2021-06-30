#include<limits.h>
#include<stdio.h>
#include<stdlib.h>

//To represent a node in adjacency list
struct AdjListNode{
    int dest;
    int weight;
    struct AdjListNode* next;

};

//To represent an adjacency list
struct AdjList{
    struct AdjListNode* head;     // pointer to head node of the list

};

//To represent a graph. A graph is an array of adjacency lists.
//Size of array is V vertices
struct Graph{
    int V;
    struct AdjList* array;

};

//To create a new adjacency list node

struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc ( sizeof ( struct AdjListNode ));
    newNode -> dest = dest;
    newNode -> weight = weight;
    newNode -> next = NULL;
    return newNode;    

}

//To create a graph of V vertices

struct Graph* createGraph( int V )
{
    struct Graph* graph = (struct Graph*) malloc (sizeof( struct Graph ));
    graph -> V = V;

    //creates an array of adjacency list 
    graph -> array = (struct AdjList*) malloc ( V * sizeof (struct AdjList) );

    //initialize each adjacency list as empty by making head as NULL

    for( int i = 0; i < V ; ++i){
        graph -> array[i].head = NULL;
    }

    return graph;

}

//Add an edge to AN UNDIRECTED GRAPH

void addEdge ( struct Graph* graph, int src, int dest, int weight)
{

    //Add an edge from src to dest. A new node is added to the adjacency
    // list of src The new node is added at the beginning

    struct AdjListNode* newNode = newAdjListNode (dest , weight);
    newNode -> next = graph -> array[src].head;
    graph -> array[src].head = newNode;

    //Since graph is undirected, add an edge from dest to src also

    newNode = newAdjListNode(src, weight);
    newNode->next =  graph -> array[dest].head;
    graph -> array[dest].head = newNode;

}

//To represent a min heap node
struct MinHeapNode {
    int v;
    int key;
};


//To represent a min heap
struct MinHeap {
    int size;   //No of heap nodes present currently
    int capacity; //capacity of min-heap
    int *pos; // needed for decreaseKey()
    struct MinHeapNode** array;
};

//To create a new Min Heap Node
struct MinHeapNode* newMinHeapNode( int v, int key )
{
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc (sizeof(struct MinHeapNode));
    minHeapNode -> v = v;
    minHeapNode -> key = key;
    return minHeapNode;
} 

//To create Min Heap
struct MinHeap* createMinHeap ( int capacity )
{
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof( struct MinHeap ));
    minHeap -> pos = (int*)malloc (capacity * sizeof(int));
    minHeap -> size = 0;
    minHeap -> capacity = capacity;
    minHeap -> array = (struct MinHeapNode **)malloc (capacity * sizeof( struct MinHeapNode*));
    return minHeap;
}

//To swap two nodes of min heap needed for max heapify

void swapMinHeapNode ( struct MinHeapNode ** a, struct MinHeapNode ** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify( struct MinHeap* minHeap , int idx)
{
    int smallest, left, right ;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if ( left < minHeap -> size && minHeap ->array[left]->key < minHeap->array[smallest]->key )
        smallest = left;
     
    if ( right < minHeap -> size && minHeap ->array[right]->key < minHeap->array[smallest]->key )
        smallest = right;

    if ( smallest != idx) {

        //The nodes to be swapped in min Heap

        MinHeapNode* smallestNode = minHeap -> array[smallest];
        MinHeapNode* idxNode = minHeap -> array[idx];

        //Swap positions
        minHeap -> pos[smallestNode -> v] = idx;
        minHeap -> pos[idxNode -> v] = smallest;

        //Swap Nodes
        swapMinHeapNode( &minHeap->array[smallest] , &minHeap->array[idx] );

        minHeapify( minHeap, smallest );

    }    

}

// To check if minHeap is empty or not

int isEmpty( struct MinHeap* minHeap)
{
    return minHeap -> size == 0;
}

//To extract min node from heap

struct MinHeapNode* extractMin( struct MinHeap* minHeap)
{
    if(isEmpty(minHeap))
        return NULL;

    //Store root node with last node
    struct MinHeapNode* root = minHeap -> array[0];

    //Replace root node with last node
    struct MinHeapNode* lastNode = minHeap -> array[minHeap -> size - 1];
    minHeap -> array [0] = lastNode;

    //Update position of last node
    minHeap -> pos[ root -> v ] = minHeap -> size -1;
    minHeap -> pos[ lastNode -> v ] = 0;

    //Reduce heap size and heapify root
    --minHeap -> size ;
    minHeapify ( minHeap , 0 );

    return root;
}

//Function to decreae key value of given vertex v. This function uses pos[]
// of min heap to get the current index of node in min heap

void decreaseKey( struct MinHeap* minHeap, int v, int key)
{
    // Get indec of v in heap array
    int i = minHeap -> pos[v];

    //Get node and update its key value
    minHeap -> array [i] -> key = key;

    //This is O( Log n ) loop
    while( i && minHeap -> array[i] -> key < minHeap -> array[ (i-1) / 2] ->key ){

        //Swap this node with its parent 

        minHeap -> pos[minHeap -> array[i] -> v ] = ( i -1 ) / 2;
        minHeap -> pos[minHeap -> array[ (i - 1) / 2 ] -> v ] = i;
        swapMinHeapNode( &minHeap -> array[i], &minHeap->array[ (i - 1) / 2]);

        // move to parent index
        i  = ( i - 1) / 2;  

    }

}

// To heck if a vertex v is in min  heap or not
bool isInMinHeap( struct MinHeap * minHeap , int v)
{
    if ( minHeap -> pos[v] < minHeap -> size)
        return true;
    return false;    

}

void printArr( int arr[] , int n )
{
    for ( int i = 1; i < n;  ++i )
        printf("%d - %d\n", arr[i] , i);
}

void PrimMST( struct Graph* graph)
{
    int V = graph -> V;   // Get no of vertices in graph
    int parent[V] ;  // array to store constructed MST
    int key[V]; // Key values used to pick min weight edge in cut

    //minHeap represents set E

    struct MinHeap* minHeap = createMinHeap(V); 

    //Initialize min heap with all vertices. Key values of all 
    //vertices except 0th is initially infinite

    for(int v = 1; v < V; ++v){
        parent[v] = -1;
        key[v] = INT_MAX;
        minHeap -> array[v] = newMinHeapNode( v, key[v]);
        minHeap -> pos[v] = v;
    } 

    //Make key value of 0th vertex as 0 so that its extracted first

    key[0] = 0;
    minHeap -> array [0] = newMinHeapNode( 0, key[0]);
    minHeap -> pos [0] = 0;

    //Initialize size of min heap equal to V
    minHeap -> size = V;

    // In following loop, min heap contains all nodes
    // not yet added to MST

    while ( !isEmpty(minHeap) ){
        
        // Extract the vertex with min key value.
        struct MinHeapNode* minHeapNode = extractMin( minHeap );
        int u = minHeapNode -> v; // Store the extracted vertex no
        
        //Traverse throught all the adjacent vertices of u ( the extracted vertex )
        // and update their key values

        struct AdjListNode* pCrawl = graph -> array[u].head;
        while ( pCrawl != NULL){
            int v = pCrawl -> dest;

            // If v is not yet included in MST and weight of u-v is 
            // less than key value of v, then update key value and 
            // parent of v

            if( isInMinHeap ( minHeap, v) && pCrawl -> weight < key[v] ){
                key[v] = pCrawl -> weight;
                parent[v] = u;
                decreaseKey( minHeap , v , key[v] );
            }

            pCrawl = pCrawl -> next;
        }
    }
    //print edges of MST
    printArr ( parent , V );
}

int main()
{
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph , 0 , 1 , 4);
    addEdge(graph , 0 , 7 , 8);
    addEdge(graph , 1 , 2 , 8);
    addEdge(graph , 1 , 7 , 11);
    addEdge(graph , 2 , 3 , 7);
    addEdge(graph , 2 , 8 , 2);
    addEdge(graph , 2 , 5 , 4);
    addEdge(graph , 3 , 4 , 9);
    addEdge(graph , 3 , 5 , 14);
    addEdge(graph , 4 , 5 , 10);
    addEdge(graph , 5 , 6 , 2);
    addEdge(graph , 6 , 7 , 1);
    addEdge(graph , 6 , 8 , 6);
    addEdge(graph , 7 , 8 , 7);

    PrimMST(graph);

    return 0;
}