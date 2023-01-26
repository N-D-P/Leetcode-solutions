class Solution {
public:
    static bool comp(string str1, string str2) {
        return str1.size() < str2.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end(),comp);
        string ans;
        bool flag;
        for(int i=0; i<strs[0].size(); i++) {
            char x = strs[0][i];
            flag = true;
            for(int j=1; j<strs.size(); j++) {
                if(x != strs[j][i])
                    flag = false;
            }
            if(flag)
                ans.push_back(x);
            else
                break;
        }
            
        return ans;
    }
};