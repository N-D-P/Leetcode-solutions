class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &vis,vector<int> &pvis,vector<int> &safe) {
        vis[node] = 1;
        pvis[node] = 1;
        for(int i : graph[node]) {
            if(pvis[i] == 0) {
                if(vis[i] == 0 and dfs(i,graph,vis,pvis,safe) == true)
                    return true;
            }
            else
                return true;
        }
        pvis[node] = 0;
        safe[node] = 1;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v);
        vector<int> pvis(v);
        vector<int> safe(v);
        vector<int> res;
        
        for(int i=0; i<v; i++) {
            if(graph[i].size() == 0)
                safe[i] = 1;
        }
        
        for(int i=0; i<v; i++) {
            if(vis[i] == 0) {
                dfs(i,graph,vis,pvis,safe);
            }
        }
        for(int i=0; i<v; i++) {
            if(safe[i] == 1)
                res.push_back(i);
        }
        return res;
    }
};