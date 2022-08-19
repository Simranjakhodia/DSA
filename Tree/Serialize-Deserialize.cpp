//  https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1


/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Preorder traversal to store data in vector ans storing -1 when there is NULL
class Solution
{
    public:
    
    void solve(Node* root, vector<int>& ans) {
        if(root == NULL) {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    int i = 0;
    Node * deSerialize(vector<int> &A)
    {
       if(i == A.size()) return NULL;
       int val = A[i];
       i++;
       if(val == -1) return NULL;
       Node* root = new Node(val);
       
       root->left = deSerialize(A);
       root->right = deSerialize(A);
       return root;
    }

};
