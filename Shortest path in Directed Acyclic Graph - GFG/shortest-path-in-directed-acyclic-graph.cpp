//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int> ans(N,INT_MAX);
        vector<int> indeg(N);
        vector<vector<pair<int,int>>> adj(N);
        queue<int> q;
        
        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        
        for(int i=0; i<N; i++) 
            for(auto x : adj[i])
                indeg[x.first]++;
        
        ans[0] = 0;
        
        q.push(0);
        
        while(!q.empty()) {
            int topEle = q.front();
            q.pop();
            for(auto i : adj[topEle]) {
                indeg[i.first]--;
                ans[i.first] = min(ans[i.first], ans[topEle]+i.second);
                // if(indeg[i.first] == 0)
                 q.push(i.first);
            }
            
        }
        
        for(int i=1; i<N; i++)
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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