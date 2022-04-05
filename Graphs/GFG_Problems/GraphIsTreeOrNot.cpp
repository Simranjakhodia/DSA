// https://www.geeksforgeeks.org/check-given-graph-tree/


#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v; 
    vector<int> *adj;
    bool isCyclicUtil(int v, vector<bool>& vis, int parent);
    
public:
    Graph(int v);
    void addEdge(int v, int w);
    bool isTree();
};

Graph::Graph(int v){
    this->v = v;
    adj = new  vector<int> [v];
}

void Graph :: addEdge(int v, int w){
    adj[v].push_back(w);    // Add w to v's list
    adj[w].push_back(v);    // Add v to w's list
}
/*A recursive function to return true if there exists a cycle and to mark 
all vertices that are connected   */

bool Graph :: isCyclicUtil(int v, vector<bool>& vis, int parent) {
    vis[v] = true;
    
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++) {
        /* If an adjacent is not visited, then recur for it  */
        if(!vis[*i]) {
            if(isCyclicUtil(*i, vis, v))
                return true;
        }
        /* If an adjacent is visited and not parent of current vertex,
        then there is a cycle */
        else if(*i != parent)
            return true;
    }
    return false;
}

bool Graph :: isTree() {
    vector<bool> vis(v, false);
    
    if(isCyclicUtil(0, vis, -1))
        return false;
    
    for(int u = 0; u < v; u++) 
        if(!vis[u])
            return false;
            
    return true;
}
int main() {
    Graph g1(5); 
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree \n";
    
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree() ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";
    
    return 0;
}
