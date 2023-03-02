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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return maxbt(0 , nums.size(),nums);
    }
    TreeNode* maxbt(int l, int r, vector<int> &nums) {
        int maxe = INT_MIN;
        int ind = 0;
        if(l>=r) {
            return nullptr;
        }
        for(int i=l; i<r; i++) {
            if(nums[i] > maxe) {
                maxe = nums[i];
                ind = i;
            }
        }
        
        TreeNode *root = new TreeNode(maxe);

        root->left = maxbt(l,ind,nums);
        root->right = maxbt(ind+1,r,nums);
        return root;
    }
};