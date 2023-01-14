//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c] != 1)
            return;
        if(grid[r][c] == 1) grid[r][c] = 2;
        dfs(r+1,c,grid);
        dfs(r-1,c,grid);
        dfs(r,c+1,grid);
        dfs(r,c-1,grid);
    }
    
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int r = grid.size();
        int c = grid[0].size();
        for(int i=0; i<r; i++) {
            if(grid[i][0] == 1)
                dfs(i,0,grid);
             if(grid[i][c-1] == 1)
                dfs(i,c-1,grid);
        }
        
        for(int i=0; i<c; i++) {
            if(grid[0][i] == 1)
                dfs(0,i,grid);
             if(grid[r-1][i] == 1)
                dfs(r-1,i,grid);
        }
        int cnt=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1)
                    cnt++; 
  
            }
                
        return cnt;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends