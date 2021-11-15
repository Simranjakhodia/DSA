
// https://leetcode.com/problems/validate-binary-search-tree/

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
    /*
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        if(root->left && root->left->val >= root->val)
            return false;
        if(root->right && root->right->val <= root->val)
            return false;
        if(!isValidBST(root->left) || !isValidBST(root->right))
            return false;
        return true;
    }
    
    */  // Simple but testcase [5,4,6,null,null,3,7] gives wrong result
    /*
    bool isValidBST1(TreeNode* root){
        return helper(root, NULL, NULL);
    }
    
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max){
        if(!root)
            return true;
        if(min && root->val <= min->val || max && root->val >= max->val)
            return false;
        return helper(root->left, min , root) && helper(root->right, root, max);
    }
    */
    //Method-2: Inorder traversal
    
    bool isValidBST(TreeNode* root){
        TreeNode* prev = NULL;
        return helper (root, prev);
    }
    
    bool helper(TreeNode* root, TreeNode* &prev){
            if(!root) return true;
      
            if(!helper(root->left, prev)) return false;
            if(prev && prev->val >= root->val) return false;
            prev = root;
            return helper(root->right, prev);
        }
   
    
};
