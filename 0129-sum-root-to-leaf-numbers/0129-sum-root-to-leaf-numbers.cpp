/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        sumnum(root,ans,0);
        return ans;
    }
    
    void sumnum(TreeNode* root, int &ans, int num) {
        if(root == nullptr)
            return;
        if(root->left == nullptr and root->right == nullptr) {
            ans += (num*10)+root->val;
            cout<<num<<" ";
            return;
        }
        // else if(root->left == nullptr or root->right == nullptr)
        //     return;
        sumnum(root->left,ans,(num*10)+root->val);
        sumnum(root->right,ans,(num*10)+root->val);
        return;
    }
};