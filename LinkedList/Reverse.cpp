#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

class LinkedList{

    public :
    Node* head;
    LinkedList() {
        head = NULL;
    }

    void reverse()
    {

        Node* current = head ;
        Node* prev = NULL , *next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    void push(int data)
    {
        Node* node = new Node(data);
      //  node->data = data;
        node->next = head;
        head = node;
        
    }

    void print()
    {
        struct Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }

    }

};    

int main()
{
    LinkedList l1;
    l1.push(20);
    l1.push(4);
    l1.push(15);
    l1.push(85);

    cout << "Given linked list\n";
    l1.print();

    l1.reverse();

    cout << "\nReversed Linked List \n";
    l1.print();
    return 0;

}

/************************************************************************************************************/
/************************************************************************************************************/
class Solution
{
    public:
    // MT 1 : ITERATIVE
    struct Node* reverseList1(struct Node *head)
    {
        Node* curr = head, *prev = NULL, *nextp;
        while(curr) {
            nextp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextp;
        }
        head = prev;
        return head;
    }
    
    // MT 2 : RECURSION
    struct Node* reverseList(struct Node *head) {
        if(!head || !head->next) return head;
        
        Node* node = reverseList(head->next);
        Node* tail = head->next;
        tail->next = head;
        head->next = NULL;
        return node;
    }
    
};
    
