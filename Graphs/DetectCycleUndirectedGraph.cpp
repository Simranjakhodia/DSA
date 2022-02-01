#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[], vector<int> visited, int curr) {
    if(visited[curr] == 2) 
        return true;
    visited[curr] = 1;
    bool FLAG = false;
    for(int i = 0; i < adj[curr].size(); i++){
        if(visited[adj[curr][i]] == 1)
            visited[adj[curr][i]] = 2;
        else 
            {
                FLAG = isCyclicUtil(adj[curr], visited, adj[curr][i]);
                if(FLAG == true)
                    return true;
            }
    }
    return false;
}

bool isCyclic(vector<int> adj[], int v) {
    vector<int> visited(v, 0);
    bool FLAG = false;
    for(int i = 0; i < v; i++){
        visited[i] = 1;
        for(int j = 0; j < adj[i].size(); j++) {
            FLAG = isCyclicUtil(adj, viisted, adj[i]);
            if(FLAG == true) 
                return true;
        }
        visited[i] = 0;
    } 
    return false;
}

int main(){
    int T;   // no of testcase
    cin >> T;
    while(T--) {
        int V, E;
        cin >> V >> E;
        
        vector<int> adj[V];
        int u, v;
        for(int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << isCyclic(adj, V) << endl;
    }
    return 0;
}
