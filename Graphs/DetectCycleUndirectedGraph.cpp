// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto child : adj[node]){
            if(vis[child] == 0){ // child not visited yet
                if(dfs(child, vis, adj))
                    return true;
            }        
            else if(vis[child] == 1) // node is under processing and appeared again
                return true;
                
        }
        vis[node] = 2;
        return false;
    } 
    
    bool isCyclic(int v, vector<int> adj[]) {
        vector<int> vis(v, 0);
        for(int i = 0; i < v; i++){
            if(vis[i] == 0) {
                if(dfs(i, vis, adj))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
