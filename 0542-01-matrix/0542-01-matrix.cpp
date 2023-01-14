class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //queue<row,col,step>
        queue<pair<pair<int,int>,int>> q;
        
        int r = mat.size();
        int c = mat[0].size();
        
        //visited matrix
        vector<vector<int>> vis(r,vector<int>(c,0));
        //res matrix
        vector<vector<int>> res(r,vector<int>(c,0));
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                } 
            }
        }
        
        int delR[] = {0,1,0,-1};
        int delC[] = {1,0,-1,0};
        while(!q.empty()) {
            auto topg = q.front();
            int row = topg.first.first;
            int col = topg.first.second;
            int step = topg.second;
            q.pop();
            
            res[row][col] = step;
            for(int i=0; i<4; i++) {
                int nr = row + delR[i];
                int nc = col + delC[i];
                if(nr>=0 and nr<r and nc>=0 and nc<c and vis[nr][nc] == 0 and mat[nr][nc] == 1) {
                    q.push({{nr,nc},step+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return res;
        
    }
};