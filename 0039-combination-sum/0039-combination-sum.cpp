class Solution {
public:
    void dfs(vector<int> &nums, int target, vector<vector<int>> &ans, vector<int> &temp, int ind) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        else if(target < 0)
            return;
        if(ind == nums.size())
            return;
        temp.push_back(nums[ind]);
        dfs(nums,target-nums[ind],ans,temp,ind);
        temp.pop_back();
        dfs(nums,target,ans,temp,ind+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int ind = 0;
        dfs(candidates, target, ans, temp, ind);
        return ans;
    }
};