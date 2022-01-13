// https://practice.geeksforgeeks.org/problems/topological-sort/1#

	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int src, vector<int> &vis, vector<int>adj[], stack<int> &s) {
	    vis[src] = 1;
	    for(auto it : adj[src]) {
	        if(!vis[it]) dfs(it, vis, adj, s);
	    }
	    s.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V, 0);
	    stack<int> s;
	    for(int i = 0; i < V; i++) 
	        if(!vis[i]) dfs(i, vis, adj, s);
	   
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	    
	}
