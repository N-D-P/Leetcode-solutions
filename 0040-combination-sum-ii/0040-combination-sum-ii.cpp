class Solution {
public:
        void backtrack(vector<vector<int>>&res, vector<int>& temp, vector<int>& nums, int target, int start) {
        if(target == 0) {
            res.push_back(temp);
            return;
        }
        else if(target < 0)
            return;
        else {
            for(int i=start; i<nums.size(); i++) {
                if(i>start and nums[i] == nums[i-1]) continue;
                temp.push_back(nums[i]);
                backtrack(res, temp, nums, target-nums[i], i+1);
                temp.pop_back();
                
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        int start = 0;
        backtrack(res, temp, candidates, target, start);
        return res;
    }
};