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
        queue<pair<TreeNode*,int>> q;
        q.push({root,root->val});
        int ans = 0;
        while(!q.empty()) {
            auto ele = q.front();
            TreeNode *curr = ele.first;
            int val1 = ele.second;
            q.pop();
            
            if(curr->left) {
                q.push({curr->left, (val1*10)+curr->left->val});
            }
            if(curr->right) {
                q.push({curr->right, (val1*10)+curr->right->val});
            }
            
            if(curr->left == nullptr and curr->right == nullptr) {
                cout<<val1<<" ";
                ans += val1;
            }
        }
        return ans;
    }
};