class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for(int i=0; i<nums.size()-1; i++) {
            int l = i+1;
            int r = nums.size()-1;
            int target = 0 - nums[i];
            while(l < r) {
                if(nums[l] + nums[r] > target) {
                    r--;
                }
                else if(nums[l] + nums[r] < target) {
                    l++;
                }
                else {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[l];
                    temp[2] = nums[r];
                    ans.push_back(temp);
                    while(l<r and nums[l]==temp[1]) l++;
                    while(l<r and nums[r]==temp[2]) r--;
                }
            }
            while(i+1<nums.size() and nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};