//  Lowest Common Ancestor in Binary Tree

Node* lca ( Node* root, int n1, int n2 ) {
    
    if(root == NULL) {
      return root;
    }
  
    if(root->data == n1 || root->data == n2) {
      return root;
    }
  
    Node*  left = lca ( root -> left, n1, n2 );
    Node*  right = lca ( root -> right, n1, n2 );
    
    if( left != NULL && right != NULL ) 
        return root;
  
    else if(left != NULL)
        return left;
    
    else
        return right;
    
}

Explanation: 
We have two different variables namely left and right. Both contains answer either null or a valid node. We have 
three conditions to check based on this. 
  1 If left and right ans both are not null, it means values of n1 and n2 lies in right as well as left so return root
  
  2 If left is not null and right is null, it means values of n1 and n2 both lie on left side of subtree so return left
  
  3 If right is not null and left is null, it means values of n1 and n2 both lie on right side of subtree so return right



// Lowest Common Ancestor in Binary Search Tree

Node* lca ( Node* root, Node* p, Node* q) {
  
  if( (root->val > p->val) && (root->val > q->val) )
      return lca ( root->left, p, q );
  
  if( (root->val < p->val) && (root->val < q->val) )
      return lca ( root-> right, p, q );
  
  return root;
  
}
  
