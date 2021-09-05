# include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int key)
    {
        this.data = key;
        next = NULL;
    }
};



    void insert(Node **head , int data)
    {
        
        Node *node = new Node(data);
        if(*head == NULL)
            (*head)  = node;
        else{    
        node->next = *head;
        *head = node;}
    }

    void printList(Node *head)
    {
        Node *temp = head;
        while(temp){
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << endl;
    }
    Node *findMid( Node* root);
    Node* merge( Node* a , Node* b);

    Node *mergeSort( Node* head)
    {
        if( (head)->next == NULL )
            return head;

      struct Node *mid = findMid( head );
       struct Node *head2 = mid->next;
       struct Node* a =  mergeSort(head);
       struct Node* b =  mergeSort(head2);

        struct Node* result = merge( a , b );

        return result;    
    }

    Node *findMid( Node* root)
    {
        struct Node *fast = root -> next, *slow = root;

        while( fast || fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        } 
        return slow;
    }

    Node* merge( Node* a , Node* b)
    {
        Node *res = NULL;
        Node *temp = res;
        if( !a && !b)
            return NULL;
        if( !a && b)
            return b;
        if( a && !b)
            return a;
        if( a && b )
        {
            if( a->data >= b->data){
                res = a -> data;
                res -> next = merge( a ->next , b );
            }
            if ( a-> data < b -> data){
                res = b -> data;
                res -> next = merge( a , b ->next );
            }
        }
        return temp;            
    }



int main()
{
    Node*head = NULL;
   
    int a[] = {7 , 10 , 5 , 20 , 3 , 2};
    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]); i++ ){
        insert(&head , a[i] );
    }
    cout<<"Original List: " << printList(head) << endl;

    Node* newRoot = mergeSort(head);

    cout<<"New List: " << printList(newRoot) << endl;

    return 0;
}
