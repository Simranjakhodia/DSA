#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this -> data = data;
        left = right = NULL;
    }
};

vector <int> inorder(struct Node * root, vector<int> res)
{
    stack <Node* > s ;
    Node *curr = root;

    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            curr = curr -> left;
        }
        curr = s.top();
        s.pop();
        res.push_back(curr->data);

        curr  = curr-> right;
    }
    return res;
}

void PrintTraversal ( vector<int>res){

    for (auto i = res.begin() ; i != res.end() ; ++i)
        cout << *i << " ";
}

int main()
{
    struct Node* root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);

    vector< int >res;
    res = inorder( root , res) ;
    PrintTraversal( res );

    return 0;
}




// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/