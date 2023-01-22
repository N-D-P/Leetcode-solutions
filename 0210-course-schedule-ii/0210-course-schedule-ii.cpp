class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        int cnt = 0;
        vector<int> ind(V);
        vector<int> adj[V];
        queue<int> q;
        vector<int> ans;
        
        for(int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        for(int i=0; i<V; i++)
            for(int x : adj[i])
                ind[x]++;
        
        for(int i=0; i<V; i++)
            if(ind[i] == 0)
                q.push(i);
        
        while(!q.empty()) {
            int ele = q.front();
            q.pop();
            cnt++;
            ans.push_back(ele);
            for(int i:adj[ele]) {
                ind[i]--;
                if(ind[i] == 0)
                    q.push(i);
            }
        }
        return cnt == V ? ans : vector<int> ();
    }
};