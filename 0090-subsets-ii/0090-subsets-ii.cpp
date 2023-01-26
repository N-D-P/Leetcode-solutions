class Solution {
public:
        void recurr(vector<int> nums,vector<vector<int>> &res, vector<int> &temp,int ind){
        res.push_back(temp);
        for(int i=ind; i<nums.size(); i++){
            if(i>ind and nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            recurr(nums, res, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        int ind = 0;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        recurr(nums,res,temp,ind);
        return res;
    }
};