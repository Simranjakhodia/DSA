#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
   class Node* next;
};

Node* newNode(int data)
{
    class Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node; 
}

void printList(Node* head)
{
    while(head!=NULL){
      cout << head->data << " -> ";
      head = head->next;
    }
    cout << endl;
}

void insertatpos(Node** head , int data , int pos)   // pos is acc to one indexing
{
   struct Node* node = *head;
   struct Node* temp = NULL;
   if (pos == 1)
   {
       temp = newNode(data);
       temp->next = *head;
       *head = temp;
   }
   else if (pos == 2)
   {
       temp = newNode(data);
       temp->next = (*head)->next;
       (*head)->next = temp;

   }
   else{

       while(pos > 2){
           node = node->next;
           pos--;
        }
       temp = newNode(data);
       temp->next = node->next;
       node->next = temp;
    //  printList(node);cout<<endl<<"head below"<<endl<<endl;   // for debugging purposes
    //  printList(*head);    // for debugging purposes
   }

}
void delatpos(Node**head , int pos)   // pos acc to 1 indexing
{
   struct Node* node = *head;   // struct word before Node* is optional
    Node* temp = NULL;
    if(pos == 1){
    node = node -> next;
    //*head = NULL;
    *head = node;
    //cout << (*head)->data<<endl;
    }
    else if(pos == 2){
        temp = (*head)->next;
        (*head)->next = (*head)->next->next;
        free(temp);
    }
    else{
        while(pos > 2){
            node = node->next;
            pos--;
        }
        temp = node->next;
        node->next = node->next->next;
        free(temp);
        }
}

void delNode( Node **head , int x)   // x-> no to be deleted
{
    Node *temp =  *head;

    if( (*head)->data == x ){
        temp = temp->next;
        delete *head;
        *head = temp;
    }
    else{
        while(temp!=NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp == NULL)
        return;

        prev->next = temp->next;
        delete temp;    
    }
}
int main()
{
    struct Node* root = NULL;
    for(int i = 1 ; i <= 10 ; i++){
        insertatpos(&root , i*5 , i );
        printList(root);
    }
    insertatpos(&root , 11 , 11 );
    printList(root);
    insertatpos(&root ,6 , 6 );
    printList(root);
    insertatpos(&root , 2 , 2 );
    printList(root);
    delatpos(&root , 1);
    printList(root);
    insertatpos(&root , 5 , 1 );
    printList(root);
    delatpos(&root , 13 );
    printList(root);
    delatpos(&root ,6  );
    printList(root);
    delatpos(&root , 1);
    printList(root);


    return 0;
}