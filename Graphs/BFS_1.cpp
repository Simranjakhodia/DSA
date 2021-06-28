#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int V; // no of vertex
    list<int> *adj;

    public : 
        Graph(int V); // constructor
        void AddEdge(int v, int w);
        void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::AddEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to list containing v's
}

void Graph::BFS(int s)
{
    bool* visited = new bool[V]; 
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;      // mark all vertices as not visited
    }

    //create a queue for BFS
    list<int> queue;

    visited[s] = true; // mark current node as visited and push it in queue
    queue.push_back(s);

    //i will be used to get adjacent vertices of s

    list<int>::iterator i;

    while(!queue.empty())
    {
        //Dequeue a vertex from queue and print it

        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        //Get all adjacent vertices of vertex s. If the adjacent vertx 
        //hasnt been visited, then mark it visited and enqueue it.

        for (i = adj[s].begin(); i != adj[s].end(); ++i)     // for(auto i : adj[s])
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

}

//Driver code to test methods of graph class
int main()
{
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);

    cout << "Following is BFS " << "starting from vertex 2 \n" << endl;
    g.BFS(2);
    return 0;
}