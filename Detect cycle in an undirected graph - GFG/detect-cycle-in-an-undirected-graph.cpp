//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool bfs(int x, vector<int> &vis,vector<int> adj[]) {
        queue<int> q;
        q.push(x);
        vis[x] = 1;
        map<int,int> map;
        map[x]++;
        while(!q.empty()) {
            int topq = q.front();
            q.pop();
            vis[topq] = 1;
            for(int i : adj[topq]) {
                
                if(vis[i] == 0) {
                    q.push(i);
                    map[i]++;
                }
                if(map[i] > 1) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V);
        map<int,int> map;
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                if(bfs(i,vis,adj))
                    return true;
            }

        }
        return false;

    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends