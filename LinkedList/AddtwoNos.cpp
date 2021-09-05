#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
  //  Node(int data)
   // {
 //       this -> data = data;
 //       next = NULL;
 //   }
  
};

class LinkedList{
    public:
    Node* head,*tail;
    LinkedList() {
       
     head = NULL;
     tail = NULL;
    }
    Node* newNode(int data)
    {
      Node* node = new Node;
      node->data = data;
      node->next = NULL; 
      return node; 
    }

    void print()
    {
        Node *temp = head;
        int i;
        while(temp){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        cout << endl;
    }

    void insertNode(int data)
    {
        Node * node = newNode(data);
        if(!head){
            head = node;
            tail = head;
        }    
        else{    
            tail -> next = node;
            tail = tail-> next;
        }
    }

    void add(Node* root1, Node* root2)        // Can be written as recursive also. Remove while loop 
    {
        while(root1 || root2){
        int sum = root1->data + root2->data;
        if(sum < 10)
        {
            insertNode(sum);
        }
        else 
        {   if(!head){
            insertNode( sum / 10 );
            }
            else tail->data = tail->data + sum / 10;
            
            insertNode( sum % 10 );
        }
        root1 = root1 ->next;
        root2 = root2 ->next;
        }
    }    

};

int main()
{
    LinkedList l1 , l2,l3;
    
    l1.insertNode(7);
    l1.insertNode(8);
    l1.insertNode(3);
    l1.print();
    l1.print();
    l2.insertNode(8);
    l2.insertNode(9);
    l2.insertNode(7);
    l2.print();
    l3.add( l1.head , l2.head);
    l3.print();
    l1.print();
    return 0;
}













// https://www.geeksforgeeks.org/add-two-numbers-represented-by-linked-lists/