class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        //reverse all the edges
        vector<vector<int>> revGrh(V);
        for(int i=0; i<V; i++) 
            for(int x : graph[i])
                revGrh[x].push_back(i);
        
        vector<int> indgre(V);
        
        for(int i=0; i<V; i++)
            for(int x: revGrh[i])
                indgre[x]++;
        
        queue<int> q;
        vector<int> res;
        
        for(int i=0; i<V; i++)
            if(indgre[i] == 0)
                q.push(i);
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            res.push_back(x);
            for(int i : revGrh[x]) {
                indgre[i]--;
                if(indgre[i] == 0)
                    q.push(i);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
        
    }
};