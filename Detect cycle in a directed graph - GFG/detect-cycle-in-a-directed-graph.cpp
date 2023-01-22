//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int cnt = 0;
        vector<int> indegree(V);
        queue<int> q;
        for(int i=0; i<V; i++)
            for(int x : adj[i])
                indegree[x]++;
        
        for(int i=0; i<V; i++)
            if(indegree[i] == 0)
                q.push(i);
                
        while(!q.empty()) {
            cnt++;
            int ele = q.front();
            q.pop();
            for(int i : adj[ele]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        return !(cnt == V);
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