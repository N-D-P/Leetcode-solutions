class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        int R = heights.size();
        int C = heights[0].size();
        vector<vector<int>> dist(R,vector<int>(C,INT_MAX));

        q.push({0,{0,0}});
        //x,y,diff

        dist[0][0] = 0;

        int ans = INT_MAX;

        int dirR[] = {0,1,0,-1};
        int dirC[] = {-1,0,1,0};
        while(!q.empty()) {
            auto ele = q.top();
            q.pop();
            int diff = ele.first;
            int x = ele.second.first;
            int y = ele.second.second;
            for(int i=0; i<4; i++) {
                int nx = x + dirR[i];
                int ny = y + dirC[i];

                if(nx >= 0 and ny >= 0 and nx < R and ny < C) {
                    
                    int newdiff = max(abs(heights[x][y] - heights[nx][ny]),diff);
                    
                    if(newdiff < dist[nx][ny]) {
                        dist[nx][ny] = newdiff;
                        q.push({newdiff,{nx,ny}});
                    }

                }
            }
        }
        return dist[R-1][C-1];

    }
};