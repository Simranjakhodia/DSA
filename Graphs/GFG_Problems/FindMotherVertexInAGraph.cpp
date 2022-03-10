// https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/




#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V; // no of vertices
    list<int> *adj;
    
    public:
        Graph(int V);
        void addEdge(int v, int w);
        int findMother();
        void dfs(int, vector<bool>&);
};
Graph :: Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph :: dfs(int v, vector<bool>& vis){
    vis[v] = true;
    list<int> :: iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        if(!vis[*i])
            dfs(*i, vis);
    }
}

int Graph :: findMother() {
    vector<bool> visited(V, false);
    int v = 0; // to store last finished vertex
    for(int i = 0; i < V; i++) {
        if(!visited[i]){
            dfs(i, visited);
            v = i;
        }    
    }
    
    fill(visited.begin(), visited.end(), false);
    dfs(v, visited);
    for(int i = 0; i < V; i++)
        if(visited[i] == false)
            return -1;
    return v;        
}

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(4, 1);
    g.addEdge(6, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
    
    cout << "Mother vertex is " << g.findMother();
    return 0;
}
