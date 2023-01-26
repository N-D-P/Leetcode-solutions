class Solution {
public:
    void backtrack(vector<vector<int>> &res,vector<int> &nums, vector<int> &temp, int index) {
        res.push_back(temp);
        for(int i=index; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(res,nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int index = 0;
        backtrack(res,nums,temp,index);
        return res;
        
    }
};