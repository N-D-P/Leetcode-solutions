class Solution {
public:
    void dfs(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &temp, int ind) {
        if(target == 0) {
            ans.push_back(temp);
        }
        else if(target < 0)
            return;
        else {
            for(int i=ind; i<nums.size(); i++) {
                temp.push_back(nums[i]);
                target -= nums[i];
                dfs(nums,target,ans,temp,i);
                target += nums[i];
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int ind = 0;
        dfs(candidates, target, ans, temp, ind);
        return ans;
    }
};