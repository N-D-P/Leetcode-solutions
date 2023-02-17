class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans=0;
        // set<pair<int,int>> s;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int c=0;
        if(k==0){
            for(auto i:m){
                if(i.second>1) c++;
            }
            return c;
        }
        for(auto i:m){
            // if(m.find(i+k)!=m.end()){
            //     m[i+k]--;
            //     ans++;
            // }
            //case1
            if(m.find(i.first+k)!=m.end() and m.find(i.first-k)!=m.end()){
                ans+=2;
                m.erase(i.first);
                // break;
            }
            else if(m.find(i.first+k)!=m.end()){
                ans++;
                m.erase(i.first);
                // break;
            }
            else if(m.find(i.first-k)!=m.end()){
                ans++;
                m.erase(i.first);
            }
            else{
                m.erase(i.first);
            }
        }
        
        return ans;
    }
};