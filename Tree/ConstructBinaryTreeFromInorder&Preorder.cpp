// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal



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
    int idx = 0;
    unordered_map<int, int> m;
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int lb, int ub) {
        if(lb > ub)return NULL;
        TreeNode* res = new TreeNode(preorder[idx++]);
        if(lb == ub) return res;
        int mid = m[res->val];
        res->left = buildTreeHelper(preorder, inorder, lb, mid - 1);
        res->right = buildTreeHelper(preorder, inorder, mid + 1, ub);
        return res; 
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) return NULL;
        int n = preorder.size();
        m.clear();
        for(int i = 0; i < n; i++) m[inorder[i]] = i;
        TreeNode* root = buildTreeHelper(preorder, inorder, 0, n - 1);
        return root;
    }
};
