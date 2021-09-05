#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
};

class NodeOperation{
    public:

    // void function to add new node

    void pushNode(class Node** head, int data){

        class Node *new_node = new Node();

        new_node ->data = data;
        new_node ->next = *head;
        *head = new_node; 
    }

    void printNode(class Node* head){
        while(head != NULL){
            cout << head->data <<"->";
            head = head->next ; 
        }
        cout << "NULL" << endl;
    }

    void printMiddle(class Node*head){
        struct Node* slow_ptr = head;
        struct Node* fast_ptr = head;
        
        if (head != NULL)
        {
            while ( fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr -> next -> next;
                slow_ptr = slow_ptr -> next;
            }
            cout << " The middle element is [" << slow_ptr->data << "]" << endl;
        }
    }
};

int main(){
    class Node *head = NULL;
    class NodeOperation *temp = new NodeOperation();
    
    for(int i = 5 ; i > 0 ; i--){
        temp -> pushNode(&head, i);
        temp -> printNode(head);
        temp -> printMiddle(head);
    }
    return 0;
}




/// https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/