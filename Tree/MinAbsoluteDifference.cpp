// https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
    int res = INT_MAX;
    int prev = INT_MAX;
    int getMinimumDifference1(TreeNode* root) {
        if(root == NULL) return res;
        
        getMinimumDifference1(root->left);
        if(prev != INT_MAX) {
            res = min(res, root->val - prev);
        }
        prev = root->val;
        getMinimumDifference1(root->right);
        return res;
    }
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* curr = root;
       
        while(curr || !s.empty()) {
            if(curr != NULL) {
                 s.push(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                s.pop();
                if(prev != INT_MAX)
                    res = min(res, curr->val - prev);
                prev = curr->val;
                curr = curr->right;
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/minimum-absolute-difference-in-bst/discuss/99905/Two-Solutions-in-order-traversal-and-a-more-general-way-using-TreeSet
