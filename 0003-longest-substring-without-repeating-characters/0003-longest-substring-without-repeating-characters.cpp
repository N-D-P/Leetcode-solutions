class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int ans = 0;
        int i=0;
        int j=0;
        while(i < s.size()) {
            if(set.find(s[i]) == set.end()) {
                set.insert(s[i]);
                ans = max(ans,i-j+1);
                i++;
            }
            else {
                set.erase(s[j]);
                j++;
            }
        }
        return ans;
    }
};