class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1)
            return s;
        
        string ans;
        int maxl = 0;
        int size = s.size();
        
        for(int i=0; i<size; i++) {
            int l = i;
            int r = i;
            while(r+1<size and s[r+1] == s[r]) {
                r++;
            } 
            while(l-1>=0 and s[l-1] == s[l]) {
                l--;
            } 
            while(l-1>=0 and r+1<size and s[l-1] == s[r+1]) {
                l--;
                r++;
            }
            cout<<l<<" "<<r<<endl;
            if(r-l+1 > maxl) {
                ans = s.substr(l,r-l+1);
                cout<<ans<<endl;
                maxl = r-l+1;
            }
        }
        return ans;
    }
};