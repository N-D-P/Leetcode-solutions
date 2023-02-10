class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>> pq;
        //dist, k, node
        
        vector<vector<pair<int,int>>> adj(n);
        //x,y,weigth
        vector<int> ans(n,INT_MAX);

        for(int i=0; i<f.size(); i++) {
            adj[f[i][0]].push_back({f[i][1],f[i][2]});
        }
        k+=2;
        ans[src] = 0;
        pq.push({0,{1,src}});
        while(!pq.empty()) {
            auto ele = pq.front();
            pq.pop();
            int dist = ele.first;
            int k1 = ele.second.first;
            int node = ele.second.second;
            for(auto i : adj[node]) {
                int newnode = i.first;
                int newdist = i.second;
                if(k1 < k and ans[newnode] > dist+newdist) {
                    ans[newnode] = dist+newdist;
                    pq.push({ans[newnode],{k1+1,newnode}});
                }
            }
        }

        return ans[dst]==INT_MAX?-1:ans[dst];
    }
};