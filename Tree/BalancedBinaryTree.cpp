
// https://leetcode.com/problems/balanced-binary-tree

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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh-rh > 1 || lh-rh < -1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
        // return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
       
    }
    int height(TreeNode* root){
        if(!root)
            return 0;
     //   if(!root->left && !root->right)
     //       return 1;
        return max(height(root->left)+1, height(root->right)+1);
    }
};
