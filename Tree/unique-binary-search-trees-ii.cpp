// https://leetcode.com/problems/unique-binary-search-trees-ii/submissions/


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
    vector<TreeNode*> generateTrees(int n) {
        return genTrees (1, n);
    }
    
    vector<TreeNode*> genTrees(int start, int end) {
        
        vector<TreeNode*> list;
        if(start == end) {
            list.push_back(new TreeNode(start));
            return list;
        }
        if(start > end) {
            list.push_back(NULL);
            return list;
        }
        vector<TreeNode*> left, right;                                            
        for(int i = start ; i <= end; i++) {
            left = genTrees(start, i-1);
            right = genTrees(i+1, end);
            
            for(TreeNode* lnode : left) { 
                for(TreeNode* rnode : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    list.push_back(root);
                }
            }
        } 
        return list;                                            
    }
};
