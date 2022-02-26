// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal


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
    TreeNode* buildTreeHelper(vector<int> inorder, vector<int> postorder, int lb, int ub) {
        if(lb > ub) return NULL;
        TreeNode* res = new TreeNode(postorder[idx--]);
        if(lb == ub) return res;
        int mid = m[res -> val];
        res -> right = buildTreeHelper(inorder, postorder, mid + 1, ub);
        res -> left = buildTreeHelper(inorder, postorder, lb, mid - 1);
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        idx = inorder.size() - 1;
        int n = idx + 1;
        m.clear();
        for(int i = 0 ; i < n; i++) m[inorder[i]] = i;
        TreeNode* root = buildTreeHelper(inorder, postorder, 0, n - 1);
        return root;
    }
};
