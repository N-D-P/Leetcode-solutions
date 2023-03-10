class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int l=0, r=size-1, ans=0;
        while(l<r) {
            ans = max(ans, (r-l)*(min(height[l],height[r])));
            if(height[l] > height[r])
                r--;
            else
                l++;
        }
        return ans;
    }
};