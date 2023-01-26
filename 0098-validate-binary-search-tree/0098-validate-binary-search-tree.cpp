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
    bool isValidBST(TreeNode* root) {

        return isValidBST(root,nullptr,nullptr);
    }
    bool isValidBST(TreeNode* root, TreeNode *minnode, TreeNode *maxnode) {
        if(root == nullptr)
            return true;
        if((minnode != nullptr and root->val <= minnode->val) or (maxnode != nullptr and root->val >= maxnode->val))
            return false;
        return isValidBST(root->left,minnode,root) and isValidBST(root->right,root,maxnode);
    }
};