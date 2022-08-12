// https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1


class Solution{
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    void helper(Node* root, int expected, int curr, int &res) {
        if(!root) return;
        
        if(root->data == expected)
            curr ++;
        else 
            curr = 1;
        
        res = max(res, curr);
        
        helper(root->left, root->data + 1, curr, res);
        helper(root->right, root->data + 1, curr, res);
    }
    int longestConsecutive(Node* root)
    {
        if(!root) return 0;
        int res = 0;
        helper(root, root->data, 0, res);
        if(res < 2) return -1;
        return res;
    }
};
