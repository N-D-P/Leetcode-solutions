//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node, vector<int> adjj[], vector<int> &vis, vector<int> &Pvis) {
        vis[node] = 1;
        Pvis[node] = 1;
        for(int i : adjj[node]) {
            if(Pvis[i] == 0) {
                if(vis[i] == 0 and dfs(i,adjj,vis,Pvis)) 
                    return true;
               
            }
            else
                return true;
        }
        Pvis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> adjj[V];
        vector<int> vis(V);
        vector<int> Pvis(V);
        
        
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                if(dfs(i,adj,vis,Pvis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

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