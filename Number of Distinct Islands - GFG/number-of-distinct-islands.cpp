//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int x, int y, vector<vector<int>>&grid,vector<pair<int,int>>&v, vector<vector<int>>&vis, int x0, int y0) {
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y] == 0 or vis[x][y] == 1)
            return;
        v.push_back({x-x0,y-y0});
        vis[x][y] = 1;
        dfs(x+1,y,grid,v,vis,x0,y0);
        dfs(x-1,y,grid,v,vis,x0,y0);
        dfs(x,y+1,grid,v,vis,x0,y0);
        dfs(x,y-1,grid,v,vis,x0,y0);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        set<vector<pair<int,int>>> set;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1 and vis[i][j] == 0) {
                    vector<pair<int,int>> v;
                    dfs(i,j,grid,v,vis,i,j);
                    set.insert(v);
                }
            }
        }
        return set.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends