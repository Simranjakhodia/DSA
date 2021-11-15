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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left)
            return minDepth(root->right) + 1;
        if(!root->right)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left) , minDepth(root->right)) + 1;
    }
    */ //DFS   time : 250sec 
    
    int minDepth(TreeNode* root){
        if(!root) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int i = 0;
        while(!Q.empty()){
            i++;
            int k = Q.size();
            for( int j = 0 ; j < k ; j++){
                TreeNode* rt = Q.front();
                if(rt->left) Q.push(rt->left);
                if(rt->right) Q.push(rt->right);
                Q.pop();
                if(!rt->left && !rt->right) return i;
            }
        }
        return -1;
    }  // MT-2 BFS 
};
