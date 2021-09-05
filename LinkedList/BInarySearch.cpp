// BINARY SEARCH ON LINKED LIST

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    class Node* next;
};

class Node* newNode(int x)
{
    Node *node = new Node;
    node->data = x;
    node->next = NULL;
    return node;
}

class Node* middle(class Node* start , class Node* end)
{
    if(start == NULL)
        return NULL;

    struct Node* slow = start;
    struct Node* fast = start;
    while( fast!= NULL && fast->next != end )
    {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;    
}

struct Node* binarySearch(class Node* head , int x)
{
    if(!head)
        return NULL;

    class Node* start = head ; 
    class Node* last = NULL;
    
   do {
     Node* mid = middle(start , last);   

    if(mid->data > x){
        last = mid;
    } 
    else if(mid->data < x){
        start = mid->next;
    }
    else if (mid->data == x)
        return mid;
    }   while(last == NULL || last != start) ;
    
    return NULL;
}

void printNode(class Node* head){
        while(head != NULL){
            cout << head->data <<"->";
            head = head->next ; 
        }
        cout << "NULL" << endl;
    }
int main()
{
    struct Node* root = newNode(4);
    int i;
    struct Node* temp = root;
    for(i = 1; i <= 10 ; i++){
        struct Node* node = newNode(i*10);
       
            temp -> next = node;
            temp = temp -> next;
          
    }
    printNode(root);

  //  cout <<"22 "<<binarySearch(root , 22)<<endl;
 //   cout<<"30 "<<binarySearch(root , 30)<<endl;
 if(binarySearch(root , 22)->data)
  cout<<"1"<<endl;
 else
  cout<<"0"<<endl;
return 0;

}    