//  https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int i, int parent, vector<int> adj[], vector<int>& vis) {
        vis[i] = true;
        for(auto node : adj[i]) {
            if(!vis[node]){
                if(dfs(node, i,adj, vis))
                return true;}
            else if(node != parent) 
                return true;
        }
        return false;
    } 
    bool isCycle(int v, vector<int> adj[]) {
        vector<int> vis(v+1, 0);
        for(int i = 0; i < v; i++) {
            if(!vis[i] && dfs(i, -1 ,adj, vis))
                return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
