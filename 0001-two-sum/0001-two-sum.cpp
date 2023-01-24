class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        vector<int> ans(2);
        
        for(int i=0; i<nums.size(); i++) 
            map[nums[i]] = i;
        
        for(int i=0; i<nums.size(); i++) {
            int rem_tar = target - nums[i];
            if(map[rem_tar] and map[rem_tar] != i) {
                ans[0] = i;
                ans[1] = map[rem_tar];
                break;
            }
        }
        return ans;
    }
};