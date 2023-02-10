class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       queue<pair<int,pair<int,int>>> q;
       
       int R = grid.size();
       int C = grid[0].size();
       int ans = INT_MAX;
       int dirR[] = {1, 0, -1, 0, 1, 1 ,-1, -1};  
       int dirC[] = {0, 1, 0 ,-1, 1, -1, 1, -1};
        
        if(grid[0][0] == 0) {
            q.push({0,{0,1}});
            if(R == 1)
                return 1; 
        }
            grid[0][0] = 1;

        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second.first;
            int cnt = q.front().second.second;
            q.pop();
            for(int i=0; i<8; i++) {
                int nx = x + dirR[i];
                int ny = y + dirC[i];
                if(nx >=0 and nx < R and ny >= 0 and ny < C and grid[nx][ny] == 0 ) {
                    if(nx == R-1 and ny == C-1) {
                        return cnt+1;
                        cout<<cnt;
                    }
                    grid[nx][ny] = cnt+1;
                    q.push({nx,{ny,cnt+1}});
                }
            }
        }
        return -1;
    }
};