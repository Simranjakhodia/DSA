//   https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1


// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    int ans = 0;
    while(root) {
        if(root->data > input) {
            ans = root->data;
            root = root->left;
        }
        else if(root->data == input) {
            ans = input;
            break;
        }
        else
            root = root->right;
    }
    return ans;
}
