

#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(vector<int> adj[], vector<bool>visited, int curr) {
    if(visited[curr] == true) return true;
    visited[curr] = true;
    bool FLAG = false;
    for(int i = 0 ; i < adj[curr].size(); i++) {
        FLAG = isCyclicUtil(adj, visited, adj[curr][i]);
        if(FLAG == true) return true;
    }
    return false;
} 

bool isCyclic(int v, vector<int> adj[]) {
    vector<bool> visited (v, false);
    bool FLAG = false;
    for(int i = 0; i < v; i++) {
        visited[i] = true;
        for(int j = 0 ; j < adj[i].size(); j++) {
            FLAG = isCyclicUtil(adj, visited, adj[i][j]);
            if(FLAG == true) return true;
            
        }
        visited[i] = false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int v, e;
        cin >> v >> e;
        vector<int> adj[v];
        
        for(int i = 0; i < e; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        cout << isCyclic(v, adj) << endl;
    }
    return 0;
}



// https://www.youtube.com/watch?v=0dJmTuMrUZM&t=388s
