class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        long long ans = 0;
        long long cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0)
                cnt++;
            else {
                ans += (cnt * (cnt + 1))/2;
                cout<<cnt<<" "<<ans<<endl;
                cnt = 0;
            }
        }
        if(cnt!=0)
            ans += (cnt * (cnt + 1))/2;
        
        return ans;
    }
};