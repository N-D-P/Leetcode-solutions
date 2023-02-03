//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        vector<int> parent(n+1);
        for(int i=1; i<=n; i++) parent[i] = i;
        vector<vector<pair<int,int>>> adj(n+1);
      
        
        for(int i=0; i<m; i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        
        pq.push({0,1});
        dist[1] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto i : adj[node]) {
                int adjnode = i.first;
                int adjdist = i.second;
                
                if(dis+adjdist < dist[adjnode]) {
                    dist[adjnode] = dis+adjdist;
                    pq.push({dist[adjnode],adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        
 
            if(dist[n] == INT_MAX) {
                return {-1};
            }
        
        vector<int> ans;
        int x = n;
        while(x != parent[x]) {
            ans.push_back(x);
            x = parent[x];

        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
     
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends