class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        // color array, 1 for Blue, -1 for red
        vector<int> col(V);
        
        for(int i=0; i<V; i++) {
            // If vertex is already colored, no need to perform BFS on it
            if(col[i] != 0) continue;
            queue<int> q;
            q.push(i);
            col[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(int adj : graph[node]) {
                    if(col[adj] == 0) {
                        col[adj] = -1 * col[node];
                        q.push(adj);
                    }
                    else if(col[adj] != -1*col[node])
                        return false;
                }
            }
        }
        return true;
    }
};