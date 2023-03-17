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
    TreeNode* buildtree(vector<int>&in,int li,int ri, vector<int>&po,int lp,int rp) {
        if(li>ri or lp>rp) return nullptr;
        
        TreeNode* node = new TreeNode(po[rp]);
        
        int tmp = li;
        int cnt = 0;
        while(po[rp] != in[tmp]) {
            cnt++;
            tmp++;
        }
        
        node->left = buildtree(in,li,tmp-1,po,lp,lp+cnt-1);
        
        node->right = buildtree(in,tmp+1,ri,po,lp+cnt,rp-1);
        
        return node;
    }
    
    /*
        TreeNode *Tree(vector<int>& in, int x, int y,vector<int>& po,int a,int b){
        if(x > y || a > b)return nullptr;
        TreeNode *node = new TreeNode(po[b]);
        int SI = x;  
        while(node->val != in[SI])SI++;
        node->left  = Tree(in,x,SI-1,po,a,a+SI-x-1);
        node->right = Tree(in,SI+1,y,po,a+SI-x,b-1);
        return node;
    }
    */

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int rp = postorder.size()-1;
        int ri = inorder.size()-1;
        int li=0,lp=0;
        return buildtree(inorder,li,ri,postorder,lp,rp);
        
    }
};