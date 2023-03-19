class Solution {
public:
    void backt(vector<int>&nums, int k,int ind,int &ans,map<int,int>&m) {
        if(ind == nums.size()) {
            ans++;
            return;
        }
        if(!m[nums[ind]+k] and !m[nums[ind]-k]) {
            m[nums[ind]]++;
            backt(nums,k,ind+1,ans,m);
            m[nums[ind]]--;
        }
        backt(nums,k,ind+1,ans,m);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        map<int,int> m;
        int ind = 0;
        backt(nums,k,ind,ans,m);
        return ans-1;
    }
};