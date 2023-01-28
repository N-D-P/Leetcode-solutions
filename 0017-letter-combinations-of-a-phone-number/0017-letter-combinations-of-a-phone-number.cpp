class Solution {
public:
    vector<string> alp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string &digits, vector<string>&ans, string &temp, int ind) {
        if(temp.size() == digits.size()) {
            ans.push_back(temp);
            return;
        }
        int indDig = digits[ind] - '0';
        cout<<indDig;
        string currDial = alp[indDig];
        for(int i=0; i<currDial.size(); i++) {
            temp.push_back(currDial[i]);
            dfs(digits,ans,temp,ind+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string temp;
        int ind = 0;
        if(digits == "")
            return ans;
        dfs(digits,ans,temp,ind);
        return ans;
    }
};