//  https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/
 
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int v;
    vector<pair<int, int>>* adj;
 
 public:    
    Graph(int v) ;
    
    void addEdge(int u, int v, int w);
    
    void primMST();
};

Graph :: Graph(int v) {
    this->v = v;
    adj = new vector<iPair> [v];
}

void Graph :: addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph :: primMST() {
    priority_queue <iPair, vector<iPair>, greater<iPair>>  pq;
    
    int src = 0;
    
    vector<int> key (v, INT_MAX);
    vector<int> parent (v, -1);
    vector<bool> inMST(v, false);
    
    pq.push(make_pair(0, src));
    key[src] = 0;
    
    while(!pq.empty()) {
        
        int u = pq.top().second;
        pq.pop();
        
        if(inMST[u] == true) continue;
        
        inMST[u] = true;
        
        vector<iPair> :: iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); i++) {
            int v = (*i).first;
            int w = (*i).second;
            
            if(inMST[v] == false && key[v] > w) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
    
    for(int i = 1; i < v; i++) 
        cout << parent[i] << " - " << i << endl;
}

int main() {
    int v = 9;
    
    Graph g(v);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    
   
    g.primMST();
    
    return 0;
}


// https://www.youtube.com/watch?v=oP2-8ysT3QQ&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j&index=3

