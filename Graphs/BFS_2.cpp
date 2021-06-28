//simplified code for cpp 

#include <bits/stdc++.h>
//#define pb push_back

using namespace std;

vector <bool> v;
vector <vector<int> > g;

void edge(int a, int b)
{
    g[a].push_back(b);
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    v[u] = true;
    
    while (!q.empty()){

        int f = q.front();
        q.pop();

        cout << f << " ";

        //Enqueue all the adjacent of f and mark them visited
        
        for(auto i = g[f].begin(); i != g[f].end(); i++){
            if(!v[*i]){
                q.push(*i);
                v[*i] = true;
            }
        }
    }
}

int main()
{
    int n, e;  // n-> no of vertices ; e-> no of edges
    cout << "Give inputs (no of vertices and edges) " <<endl;
    cin >> n >> e;
    
    v.assign(n, false);
    g.assign(n, vector<int>());

    int a, b;
    cout << "Give inputs (a and b) " <<endl;
    for(int i = 0; i < e; i++){
        
        cin >> a >> b;
        edge(a, b); 
    }

    for(int i = 0; i < n; i++){
        if(!v[i])
        BFS(i);
    }

    return 0;
}






// https://www.geeksforgeeks.org/bfs-using-stl-competitive-coding/
// g++ -o BFS_2  BFS_2.cpp
//.\BFS_2.exe