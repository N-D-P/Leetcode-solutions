class Solution {
public:
    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int index,vector<bool> &freq) {
        if(temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(freq[i] == true) continue;
                freq[i] = true;
                temp.push_back(nums[i]);
                dfs(nums,res,temp,i,freq);
                temp.pop_back();
                freq[i] = false;
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> freq(nums.size());
        dfs(nums,res,temp,0,freq);
        return res;
    }
    
};